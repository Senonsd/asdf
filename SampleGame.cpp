#include "SampleGame.h"
#include "SampleBilliardBoard.h"
#include "SampleBilliardGameBall.h"
#include "SampleBilliardObject.h"

SampleGame::SampleGame(int width, int height, int fpsLimit)
	:BaseGame(width, height, fpsLimit), isDraggingBall(false), draggedBall(nullptr)
{
	// SampleGame�� ���� �������̽� ���� �� ��� 

	// SampleGame�� ���� �籸�� ���� �� ��� 
	gameObjects.push_back(new SampleBilliardBoard());

	// SampleGame�� ���� �籸�� ���� �� ��� 
	SampleBilliardGameBall* ball0 = new SampleBilliardGameBall(sf::Vector2f(800, 500), 10, sf::Color::White); // �����ϼ��ִ°�

	SampleBilliardGameBall* ball1 = new SampleBilliardGameBall(sf::Vector2f(800, 350), 10, sf::Color::Yellow);

	SampleBilliardGameBall* ball2 = new SampleBilliardGameBall(sf::Vector2f(815, 330), 10, sf::Color::Blue);
	SampleBilliardGameBall* ball3 = new SampleBilliardGameBall(sf::Vector2f(785, 330), 10, sf::Color::Red);

	SampleBilliardGameBall* ball4 = new SampleBilliardGameBall(sf::Vector2f(830, 310), 10, sf::Color::Magenta);
	SampleBilliardGameBall* ball5 = new SampleBilliardGameBall(sf::Vector2f(800, 310), 10, sf::Color(255, 100, 130));
	SampleBilliardGameBall* ball6 = new SampleBilliardGameBall(sf::Vector2f(770, 310), 10, sf::Color::Green);

	SampleBilliardGameBall* ball7 = new SampleBilliardGameBall(sf::Vector2f(845, 290), 10, sf::Color::Cyan);
	SampleBilliardGameBall* ball8 = new SampleBilliardGameBall(sf::Vector2f(815, 290), 10, sf::Color::Black); // 8�� ��
	SampleBilliardGameBall* ball9 = new SampleBilliardGameBall(sf::Vector2f(785, 290), 10, sf::Color::Red);
	SampleBilliardGameBall* ball10 = new SampleBilliardGameBall(sf::Vector2f(755, 290), 10, sf::Color::Black);

	SampleBilliardGameBall* ball11 = new SampleBilliardGameBall(sf::Vector2f(860, 270), 10, sf::Color::Yellow);
	SampleBilliardGameBall* ball12 = new SampleBilliardGameBall(sf::Vector2f(830, 270), 10, sf::Color::White);
	SampleBilliardGameBall* ball13 = new SampleBilliardGameBall(sf::Vector2f(800, 270), 10, sf::Color::Blue);
	SampleBilliardGameBall* ball14 = new SampleBilliardGameBall(sf::Vector2f(770, 270), 10, sf::Color::Red);
	SampleBilliardGameBall* ball15 = new SampleBilliardGameBall(sf::Vector2f(740, 270), 10, sf::Color::Black);
	ball1->setOwner("1");
	ball2->setOwner("2");
	ball3->setOwner("3");
	ball4->setOwner("4");
	ball5->setOwner("5");
	ball6->setOwner("6");
	ball7->setOwner("7");
	ball8->setOwner("8");
	ball9->setOwner("9");
	ball10->setOwner("10");
	ball11->setOwner("11");
	ball12->setOwner("12");
	ball13->setOwner("13");
	ball14->setOwner("14");
	ball15->setOwner("15");
	ball0->setPlayable(true);
	ball1->setPlayable(false);
	ball2->setPlayable(false);
	ball3->setPlayable(false);
	ball4->setPlayable(false);
	ball5->setPlayable(false);
	ball6->setPlayable(false);
	ball7->setPlayable(false);
	ball8->setPlayable(false);
	ball9->setPlayable(false);
	ball10->setPlayable(false);
	ball11->setPlayable(false);
	ball12->setPlayable(false);
	ball13->setPlayable(false);
	ball14->setPlayable(false);
	ball15->setPlayable(false);
	gameObjects.push_back(ball0);
	gameObjects.push_back(ball1);
	gameObjects.push_back(ball2);
	gameObjects.push_back(ball3);
	gameObjects.push_back(ball4);
	gameObjects.push_back(ball5);
	gameObjects.push_back(ball6);
	gameObjects.push_back(ball7);
	gameObjects.push_back(ball8);
	gameObjects.push_back(ball9);
	gameObjects.push_back(ball10);
	gameObjects.push_back(ball11);
	gameObjects.push_back(ball12);
	gameObjects.push_back(ball13);
	gameObjects.push_back(ball14);
	gameObjects.push_back(ball15);
}

SampleGame::~SampleGame(void)
{
	// UI �ν��Ͻ� ����  

	// ���� ������Ʈ�� ���� 
	for (SampleBilliardObject* obj : gameObjects)
	{
		delete obj;
	}
}

sf::Font* SampleGame::font = nullptr;
const sf::Font& SampleGame::getFont(void)
{
	if (font == nullptr) {
		font = new sf::Font;
		font->loadFromFile("Arial.ttf");
	}
	return *font;
}

// ��� Ŭ������ �ݵ�� �̺�Ʈ �ڵ鸵 �Լ� �����ؾ� �� 
void SampleGame::handle(sf::Event& ev)
{
	// SampleGame�� ���� �Է� �̺�Ʈ ó�� 
	switch (ev.type)
	{
	case sf::Event::Closed: // ������ ���� �� x
		// �������� x ��ư ������ �����Ѵ� 
		window->close();
		break;

	case sf::Event::KeyPressed:
		// Ű���� �̺�Ʈ 
		if (ev.key.code == sf::Keyboard::Escape)
		{
			// TODO: game paused 
			// TODO: call sample GUI 
		}
		break;

	case sf::Event::MouseMoved:
		// ���콺 ������ �̺�Ʈ 
		mouseXY.x = (float)ev.mouseMove.x;
		mouseXY.y = (float)ev.mouseMove.y;
		break;

	case sf::Event::MouseButtonPressed:
		// ���콺 ��ư ���� �̺�Ʈ 
		if (ev.mouseButton.button == sf::Mouse::Left)
		{
			for (SampleBilliardObject* obj : gameObjects)
			{
				// SampleBilliardBall�� �ν��Ͻ��� �ƴ� ��� pass
				SampleBilliardGameBall* gameBall = dynamic_cast<SampleBilliardGameBall*>(obj);
				if (gameBall == nullptr)
				{
					continue;
				}

				// Ŀ���� ���� ���ΰ� �ƴ� ��� pass 
				if (!gameBall->isIntersecting(mouseXY))
				{
					continue;
				}

				// ���� Playable�� �ƴ� ��� pass 
				if (!gameBall->isPlayable()) {
					continue;
				}

				// �巡�� ������ �� �ӽ� ���� 
				draggedBall = gameBall;
				isDraggingBall = true;
			}
		}
		break;
	case sf::Event::MouseButtonReleased:
		// ���콺 ��ư �� �̺�Ʈ 
		if (ev.mouseButton.button == sf::Mouse::Left && isDraggingBall)
		{
			isDraggingBall = false;
		}
		break;
	}
}

// ��� Ŭ������ �ݵ�� ���� ���� ���� �Լ� �����ؾ� �� 
// ��ü���� �ʵ尪
void SampleGame::update(void)
{
	// ���� ������Ʈ ������Ʈ 
	for (SampleBilliardObject* obj : gameObjects)
	{
		obj->update(clock.getElapsedTime().asSeconds());
	}

	// ���� ������Ʈ �浹 �˻�
	for (SampleBilliardObject* obj1 : gameObjects)
	{
		for (SampleBilliardObject* obj2 : gameObjects)
		{
			obj1->collide(*obj2);
		}
	}

	
	// �����ٰ� ���� ���� �ӵ��� �����ϰ� ǥ�� ���� 
	if (!isDraggingBall && draggedBall != nullptr)
	{
		draggedBall->setVelocity(draggedBall->getPosition().x - mouseXY.x, draggedBall->getPosition().y - mouseXY.y);
		draggedBall = nullptr;
	}

	// ���� ���� �ð��� ���� �ʱ�ȭ 
	clock.restart();
}

// ��� Ŭ������ �ݵ�� ��ü ������ �Լ� �����ؾ� �� 
void SampleGame::render(sf::RenderTarget& target)
{
	// ȭ�� Ŭ���� 
	window->clear(sf::Color(75, 103, 163));

	// ���� ������Ʈ ������ 
	for (SampleBilliardObject* obj : gameObjects)
	{
		obj->render(target);
	}

	// ���� �巡�� �ϸ� ���� ǥ�� (���� �� ��)
	renderDragpower(target);

	// ���� UI ������ 
}

void SampleGame::renderDragpower(sf::RenderTarget& target)
{
	if (isDraggingBall)
	{
		sf::Vector2f distance = (mouseXY - draggedBall->getPosition());
		float distanceBetween = sqrt(distance.x * distance.x + distance.y * distance.y);
		sf::Vector2f invert = distance / distanceBetween;
		sf::Color directionColor = sf::Color(255, (255 - ((int)distanceBetween / 2) % 255), 0);
		if (distanceBetween > 510)
		{
			directionColor = sf::Color::Red;
		}

		sf::Vector2f toSubtract(distanceBetween * invert.x, distanceBetween * invert.y);
		sf::Vertex start = sf::Vertex(draggedBall->getPosition(), directionColor);
		sf::Vertex end = sf::Vertex(draggedBall->getPosition() - toSubtract, directionColor);

		sf::VertexArray points; 
		points.setPrimitiveType(sf::LineStrip);
		points.append(start);
		points.append(end);

		target.draw(points);
	}
}
