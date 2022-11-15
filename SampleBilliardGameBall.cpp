#include "SampleBilliardGameBall.h"
#include "SampleGame.h"

bool SampleBilliardGameBall::isIntersecting(sf::Vector2f mouse)
{
	// mouse�� XY�� radius �ȿ� �������� �˻� 
	
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

//target�� ��½�ų ������ 
void SampleBilliardGameBall::render(sf::RenderTarget& target)
{
	// �� ���� �׸� 
	target.draw(getVertices());

	// SampleGame������ �� ���� �÷��̾� ���� ǥ�� 
	sf::Text ballText; // �ؽ�Ʈ ��ü ����
	//�ؽ�Ʈ ��ü ���� �ʱ�ȭ
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
	//�����쿡 �ؽ�Ʈ �׸�
	target.draw(ballText);
}