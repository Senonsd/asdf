#pragma once

#include <iostream>
#include <vector> 

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "SampleBilliardObject.h"

class SampleBilliardBoard : public SampleBilliardObject
{
public:
	// 내부클래스 - 당구대 물리적 경계
	class Border
	{
	public:
		// 하나의 직선이 하나의 Border 객체가 된다. 
		Border(float x1, float y1, float x2, float y2)
		{
			this->points.setPrimitiveType(sf::LineStrip);// 선을 그리기 위해서
			this->points.append(sf::Vertex(sf::Vector2f(x1, y1))); // x y 점 저장
			this->points.append(sf::Vertex(sf::Vector2f(x2, y2)));
		}
		~Border(void) { points.clear(); }
		const sf::VertexArray& getPoints(void) const { return points; }
		sf::VertexArray points; // (x,y) 좌표를 저장하는 배열 
	};
	// 내부클래스 - 당구대 물리적 구멍
	class Hole
	{
	public :
		Hole(float x1, float y1, float x2, float y2)
		{
			this->points.setPrimitiveType(sf::LineStrip);// 선을 그리기 위해서
			this->points.append(sf::Vertex(sf::Vector2f(x1, y1))); // x y 점 저장
			this->points.append(sf::Vertex(sf::Vector2f(x2, y2)));
		}
		~Hole(void) { points.clear(); }
		const sf::VertexArray& getPoints(void) const { return points; }
		sf::VertexArray points; // (x,y) 좌표를 저장하는 배열 


	};





public: 
	// 생성자 
	SampleBilliardBoard(void);

	// 소멸자 
	~SampleBilliardBoard(void);

	// Sample Game의 객체들은 반드시 상태 갱신 함수 구현해야 함 
	virtual void update(float timeElapsed);

	// Sample Game의 객체들은 반드시 충돌 물리 구현해야 함
	virtual void collide(SampleBilliardObject& other);

	// Sample Game의 객체들은 반드시 렌더링 함수 구현해야 함  
	virtual void render(sf::RenderTarget& target);

	// 당구대를 구성하는 경계 요소 반환 
	const std::vector<SampleBilliardBoard::Border>& getBorders(void) const;
	
	// 당구대를 구성하는 구멍 요소 반환 
	const std::vector<SampleBilliardBoard::Hole>& getHoles(void) const;

private:
	// 당구대를 나타내는 스프라이트 이미지 
	sf::Sprite			sprite;

	// 당구대 텍스처 데이터
	sf::Texture			texture;

	// 당구대 물리적 경계
	std::vector<SampleBilliardBoard::Border>	borderLines;


	// 당구대 물리적 구멍 경계
	std::vector<SampleBilliardBoard::Hole>	holesLinse;
	//std::vector <Line> holes;

};