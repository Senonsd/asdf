#include "SampleBilliardGameBall.h"
#include "SampleGame.h"

bool SampleBilliardGameBall::isIntersecting(sf::Vector2f mouse)
{
	// mouse의 XY가 radius 안에 들어오는지 검사 
	
	if ((std::powf(mouse.x - getPosition().x, 2.f) + std::powf(mouse.y - getPosition().y, 2.f)) 
		<= getRadius() * getRadius())
	{
		return true;
	}

	return false;
}

bool SampleBilliardGameBall::isPlayable(void)
{
	return playable;
}

void SampleBilliardGameBall::setPlayable(bool playable)
{
	this->playable = playable;
}

void SampleBilliardGameBall::setOwner(std::string owner)
{
	this->owner = owner;
}

bool SampleBilliardGameBall::isOwner(std::string owner)
{
	return owner.compare(this->owner) == 0;
}

std::string SampleBilliardGameBall::getOwner(void)
{
	return owner;
}

//target은 출력시킬 윈도우 
void SampleBilliardGameBall::render(sf::RenderTarget& target)
{
	// 공 형태 그림 
	target.draw(getVertices());

	// SampleGame에서는 각 공에 플레이어 문자 표시 
	sf::Text ballText; // 텍스트 객체 생성
	//텍스트 객체 설정 초기화
	ballText.setFont(SampleGame::getFont());
	ballText.setFillColor(sf::Color::Black);
	ballText.setOutlineColor(sf::Color::White);
	ballText.setOutlineThickness(1.f);
	ballText.setString(owner);
	ballText.setCharacterSize(18);
	if (owner.length() > 1) {
		ballText.setPosition(getPosition() - sf::Vector2f(11, 12));

	}
	else {
		ballText.setPosition(getPosition() - sf::Vector2f(5, 12));

	}
	//윈도우에 텍스트 그림
	target.draw(ballText);
}