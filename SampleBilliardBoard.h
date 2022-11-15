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
	// ����Ŭ���� - �籸�� ������ ���
	class Border
	{
	public:
		// �ϳ��� ������ �ϳ��� Border ��ü�� �ȴ�. 
		Border(float x1, float y1, float x2, float y2)
		{
			this->points.setPrimitiveType(sf::LineStrip);// ���� �׸��� ���ؼ�
			this->points.append(sf::Vertex(sf::Vector2f(x1, y1))); // x y �� ����
			this->points.append(sf::Vertex(sf::Vector2f(x2, y2)));
		}
		~Border(void) { points.clear(); }
		const sf::VertexArray& getPoints(void) const { return points; }
		sf::VertexArray points; // (x,y) ��ǥ�� �����ϴ� �迭 
	};
	// ����Ŭ���� - �籸�� ������ ����
	class Hole
	{
	public :
		Hole(float x1, float y1, float x2, float y2)
		{
			this->points.setPrimitiveType(sf::LineStrip);// ���� �׸��� ���ؼ�
			this->points.append(sf::Vertex(sf::Vector2f(x1, y1))); // x y �� ����
			this->points.append(sf::Vertex(sf::Vector2f(x2, y2)));
		}
		~Hole(void) { points.clear(); }
		const sf::VertexArray& getPoints(void) const { return points; }
		sf::VertexArray points; // (x,y) ��ǥ�� �����ϴ� �迭 


	};





public: 
	// ������ 
	SampleBilliardBoard(void);

	// �Ҹ��� 
	~SampleBilliardBoard(void);

	// Sample Game�� ��ü���� �ݵ�� ���� ���� �Լ� �����ؾ� �� 
	virtual void update(float timeElapsed);

	// Sample Game�� ��ü���� �ݵ�� �浹 ���� �����ؾ� ��
	virtual void collide(SampleBilliardObject& other);

	// Sample Game�� ��ü���� �ݵ�� ������ �Լ� �����ؾ� ��  
	virtual void render(sf::RenderTarget& target);

	// �籸�븦 �����ϴ� ��� ��� ��ȯ 
	const std::vector<SampleBilliardBoard::Border>& getBorders(void) const;
	
	// �籸�븦 �����ϴ� ���� ��� ��ȯ 
	const std::vector<SampleBilliardBoard::Hole>& getHoles(void) const;

private:
	// �籸�븦 ��Ÿ���� ��������Ʈ �̹��� 
	sf::Sprite			sprite;

	// �籸�� �ؽ�ó ������
	sf::Texture			texture;

	// �籸�� ������ ���
	std::vector<SampleBilliardBoard::Border>	borderLines;


	// �籸�� ������ ���� ���
	std::vector<SampleBilliardBoard::Hole>	holesLinse;
	//std::vector <Line> holes;

};