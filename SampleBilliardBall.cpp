#include "SampleBilliardBall.h"
#include "SampleBilliardBoard.h"

SampleBilliardBall::SampleBilliardBall(void) 
	: SampleBilliardBall(sf::Vector2f(100, 100), 10, sf::Color::Red)

{
	// nothing to do 
}


SampleBilliardBall::SampleBilliardBall(sf::Vector2f position, float radius, sf::Color color) 
	: VISCOSITY(1.0f), NUMVERTICES(20)
{
	// 공의 물리적 특성 
	this->position = position;
	this->radius = radius;
	this->angle = 0.f;
	this->mass = radius;
	this->velocity = sf::Vector2f(0, 0); //2차원에서 속도 x, y 각각의 속도
	this->acceleration = sf::Vector2f(0, 0); // 2차원에서 가속도 x, y 각각의 가속도

	// 공 색상
	this->color = color;

	// 원형 도형을 그리기 위한 데이터 초기화 
	// 새로운 원 그릴려면 이거 바꿔야 할 듯 
	vertices.setPrimitiveType(sf::TrianglesFan);
	vertices.clear();
	vertices.resize(NUMVERTICES);
	for (unsigned long i = 0; i != NUMVERTICES - 1; i++)
	{
		float x, y;
		x = position.x + radius * cosf(((360.f) / (static_cast<float>(NUMVERTICES - 2)) * i + angle) * float(M_PI) / 180.f);
		y = position.y + radius * sinf(((360.f) / (static_cast<float>(NUMVERTICES - 2)) * i + angle) * float(M_PI) / 180.f);
		vertices[i] = sf::Vertex(sf::Vector2f(x, y), color);
	}
}

SampleBilliardBall::SampleBilliardBall(const SampleBilliardBall& rhs) : SampleBilliardBall(rhs.position, rhs.radius, rhs.color)
{
	// nothing to do 
}

SampleBilliardBall& SampleBilliardBall::operator=(const SampleBilliardBall& rhs)
{
	// 버텍스 벡터 깊은 복사 
	vertices.clear();
	vertices = rhs.vertices;
	position = rhs.position;
	radius = rhs.radius;
	color = rhs.color;

	return *this;
}

SampleBilliardBall::~SampleBilliardBall(void)
{
	vertices.clear();
}

void SampleBilliardBall::setPosition(float x, float y)
{
	setPosition(sf::Vector2f(x, y));
}

void SampleBilliardBall::setPosition(sf::Vector2f position)
{
	this->position = position;

	// 위치 갱신 후 해당 위치에 원형 도형 업데이트 
	for (unsigned long i = 0; i != NUMVERTICES - 1; i++)
	{
		float x, y;
		x = position.x + radius * cosf(((360.f) / (static_cast<float>(NUMVERTICES - 2)) * i + angle) * float(M_PI) / 180.f);
		y = position.y + radius * sinf(((360.f) / (static_cast<float>(NUMVERTICES - 2)) * i + angle) * float(M_PI) / 180.f);
		vertices[i] = sf::Vertex(sf::Vector2f(x, y), color);
	}
}

void SampleBilliardBall::setAcceleration(sf::Vector2f acceleration)
{
	this->acceleration = acceleration;
}

void SampleBilliardBall::setVelocity(float x, float y)
{
	setVelocity(sf::Vector2f(x, y));
}

void SampleBilliardBall::setVelocity(sf::Vector2f velocity)
{
	this->velocity = velocity;
}

void SampleBilliardBall::setAngle(float angle)
{
	this->angle = angle;
}

void SampleBilliardBall::setRadius(float radius)
{
	this->radius = radius;
}

void SampleBilliardBall::setMass(float mass)
{
	this->mass = mass;
}

void SampleBilliardBall::setColor(sf::Color color)
{
	this->color = color; 
}

sf::Vector2f SampleBilliardBall::getPosition(void) const
{
	return position;
}

sf::Vector2f SampleBilliardBall::getAcceleration(void) const
{
	return acceleration;
}

sf::Vector2f SampleBilliardBall::getVelocity(void) const
{
	return velocity;
}

float SampleBilliardBall::getAngle(void) const
{
	return angle;
}

float SampleBilliardBall::getRadius(void) const
{
	return radius;
}

float SampleBilliardBall::getMass(void) const
{
	return mass;
}

sf::Color SampleBilliardBall::getColor(void) const
{
	return color; 
}

const sf::VertexArray& SampleBilliardBall::getVertices(void) const
{
	return vertices; 
}


// Sample Game의 객체들은 반드시 상태 갱신 함수 구현해야 함 
void SampleBilliardBall::update(float timeElapsed)
{
	// 공의 마찰에 따른 감속량(가속도) 계산 
	acceleration = -velocity * VISCOSITY;

	// 공의 가속도와 시간에 따른 새로운 속도 계산 
	velocity += acceleration * timeElapsed;

	// 속도에 따른 위치 업데이트 
	setPosition(position.x + velocity.x * timeElapsed, position.y + velocity.y * timeElapsed);

	// xy 속력에 따른 각 계산 
	// 참고: https://ko.khanacademy.org/computing/computer-programming/programming-natural-simulations/programming-angular-movement/a/pointing-towards-movement
	setAngle(atan2f(velocity.y, velocity.x) * 180.f / float(M_PI));

	// 속도가 0.1보다 작으면 마찰을 가정하여 0으로 지정 
	if (std::abs(velocity.x) < 0.1f || std::abs(velocity.y) < 0.1f)
	{
		velocity = sf::Vector2f(0.f, 0.f);
	}
}

// Sample Game의 객체들은 반드시 충돌 물리 구현해야 함
// 충돌 안해도 계속 해당 ob가 있다면 계속 실행됨. 
void SampleBilliardBall::collide(SampleBilliardObject& other)
{
	// 공과 충돌할 경우 
	// ob 중에서 ~Ball 로 캐스팅할 수 있는 객체가 있다면 계속 실행됨.
	if (dynamic_cast<SampleBilliardBall*>(&other) != nullptr)
	{
		SampleBilliardBall& ball = *dynamic_cast<SampleBilliardBall*>(&other);
		collideWithBall(ball);
	}

	// 당구대와 충돌할 경우 
	if (dynamic_cast<SampleBilliardBoard*>(&other) != nullptr) // &other은 시작주소
	{
		SampleBilliardBoard& board = *dynamic_cast<SampleBilliardBoard*>(&other);
		collideWithBoard(board);
		//당구대 안에 홀은 반드시 존재하므로...
		collideWithHole(board);


	}
}

// Sample Game의 객체들은 반드시 렌더링 함수 구현해야 함  
void SampleBilliardBall::render(sf::RenderTarget& target)
{
	// 렌더링 윈도우에 원을 구성하는 버텍스를 그림 
	target.draw(vertices);
}


void SampleBilliardBall::collideWithBall(SampleBilliardBall& other)
{
	// 동일한 공 비교시 종료 // 이중 반목문 : collide 함수에서..
	if (this == &other)
	{
		return;
	}

	// 거리 계산 
	sf::Vector2f distance = getPosition() - other.getPosition();
	float distanceBetween = (sqrtf((distance.x * distance.x) + (distance.y * distance.y)));

	// 두 공이 겹치는지 검사 
	// 아래 부분이 서로 다른 공이 부딪힌다면 실행되는 코드
	if (distanceBetween < (getRadius() + other.getRadius()))
	{
		// 겹치는 정도 계산 
		float overlap = (distanceBetween - getRadius() - other.getRadius()) / 2.f;
		float moveX = (overlap * (getPosition().x - other.getPosition().x) / distanceBetween);
		float moveY = (overlap * (getPosition().y - other.getPosition().y) / distanceBetween);

		// 두 공이 겹치지 않도록 다시 떼어놓음 
		setPosition(getPosition().x - moveX, getPosition().y - moveY);
		other.setPosition(other.getPosition().x + moveX, other.getPosition().y + moveY);

		// 충돌 후 속도 계산하여 적용
		sf::Vector2f normal(distance.x / distanceBetween, distance.y / distanceBetween);
		sf::Vector2f tangential(-normal.y, normal.x);

		float dotProductTangential1 = getVelocity().x * tangential.x + getVelocity().y * tangential.y;
		float dotProductTangential2 = other.getVelocity().x * tangential.x + other.getVelocity().y * tangential.y;

		float dotProductNormal1 = getVelocity().x * normal.x + getVelocity().y * normal.y;
		float dotProductNormal2 = other.getVelocity().x * normal.x + other.getVelocity().y * normal.y;

		float m1 = (2.f * other.getMass() * dotProductNormal2 + dotProductNormal1 * (getMass() - other.getMass())) / (getMass() + other.getMass());
		float m2 = (2.f * getMass() * dotProductNormal1 + dotProductNormal2 * (other.getMass() - getMass())) / (getMass() + other.getMass());

		setVelocity(dotProductTangential1 * tangential + m1 * normal);
		other.setVelocity(dotProductTangential2 * tangential + m2 * normal);
	}

}

void SampleBilliardBall::collideWithBoard(SampleBilliardBoard& other)
{
	for (SampleBilliardBoard::Border border : other.getBorders())
	{
		sf::Vector2f p = getPosition();
		sf::Vector2f s(border.getPoints()[0].position);
		sf::Vector2f e = border.getPoints()[1].position;
		sf::Vector2f ps = p - s;
		sf::Vector2f se = e - s;

		float lineLength = (e.x - s.x) * (e.x - s.x) + (e.y - s.y) * (e.y - s.y);
		float t = ((ps.x * se.x) + (ps.y * se.y)) / lineLength;
		sf::Vector2f st(s.x + t * se.x, s.y + t * se.y);

		sf::Vector2f distance = p - st;
		float distanceBetween = sqrtf((distance.x * distance.x) + (distance.y * distance.y));

		sf::Vector2f normal = distance / distanceBetween;
		float dotProductNormal = getVelocity().x * normal.x + getVelocity().y * normal.y;

		sf::Vector2f tangential = sf::Vector2f(-normal.y, normal.x);
		float dotProductTangential = getVelocity().x * tangential.x + getVelocity().y * tangential.y;

		float overlap = distanceBetween - getRadius();
		if (distanceBetween <= getRadius())
		{
			if (t > -0.f && t < 1.f)
			{
				setPosition(p.x - distance.x * overlap / distanceBetween, p.y - distance.y * overlap / distanceBetween);
				setVelocity(-normal.x * dotProductNormal + tangential.x * dotProductTangential,
					-normal.y * dotProductNormal + tangential.y * dotProductTangential);
			}
		}

		
	}


}


void SampleBilliardBall::collideWithHole(SampleBilliardBoard& other)
{
	for (SampleBilliardBoard::Hole border : other.getHoles())
	{
		sf::Vector2f p = getPosition();
		sf::Vector2f s(border.getPoints()[0].position);
		sf::Vector2f e = border.getPoints()[1].position;
		sf::Vector2f ps = p - s;
		sf::Vector2f se = e - s;

		float lengthLine = (e.x - s.x) * (e.x - s.x) + (e.y - s.y) * (e.y - s.y);
		float t = ((ps.x * se.x) + (ps.y * se.y)) / lengthLine;

		sf::Vector2f st;
		st.x = s.x + t * se.x;
		st.y = s.y + t * se.y;

		sf::Vector2f distance = p - st;
		float distanceBetween = sqrtf(distance.x * distance.x + distance.y * distance.y);

		if (distanceBetween <= getRadius())
		{
			//goal = true;
			static int pos = 0;
			setVelocity(sf::Vector2f(0.f, 0.f));
			
			setPosition(getRadius() + pos, getRadius());
			pos += 2 * getRadius();
		}


	}


}
