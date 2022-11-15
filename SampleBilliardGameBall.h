#pragma once

#include <cmath>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "SampleBilliardBall.h"

class SampleBilliardGameBall : public SampleBilliardBall
{
public: 
	using SampleBilliardBall::SampleBilliardBall;

	bool isIntersecting(sf::Vector2f point);

	bool isPlayable(void);
	void setPlayable(bool playable);

	void setOwner(std::string owner);
	bool isOwner(std::string owner);
	std::string getOwner(void);

	// ���� ���� ���ڸ� �׸��� ���� virtual �Լ� ������ 
	void render(sf::RenderTarget& window);

private:
	bool playable;
	std::string owner;
};