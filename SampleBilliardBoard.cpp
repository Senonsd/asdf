#include "SampleBilliardBoard.h"

SampleBilliardBoard::SampleBilliardBoard(void)
{
	// Sample Game�� ���� �籸�� �ؽ�ó �̹��� �ε� 
	texture.loadFromFile("textureBoard.png", sf::IntRect(1, 1, 454, 848));
	
	// ��������Ʈ ���� 
	sprite.setTexture(texture);
	sprite.setPosition(572.5f, 25.f);

	// �籸�� ��� �ʱ�ȭ - �����¿� 
	SampleBilliardBoard::Border lineTopL(602.5f, 40.f, 617.f, 55.f);
	SampleBilliardBoard::Border lineTop(617.f, 55.f, 983.5, 55.f);
	SampleBilliardBoard::Border lineTopR(983.5f, 55.f, 998.5f, 40.f);
	borderLines.push_back(lineTopL);
	borderLines.push_back(lineTop);
	borderLines.push_back(lineTopR);

	SampleBilliardBoard::Border lineTopRightL(1012.5f, 54.f, 997.5f, 69.5f);
	SampleBilliardBoard::Border lineTopRight(997.5f, 69.5f, 997.5f, 433.5f);
	SampleBilliardBoard::Border lineTopRightR(997.5f, 433.5f, 1012.5f, 442.f);
	borderLines.push_back(lineTopRightL);
	borderLines.push_back(lineTopRight);
	borderLines.push_back(lineTopRightR);


	SampleBilliardBoard::Border lineDownRightL(1012.5f, 458.5f, 997.5f, 466.5f);
	SampleBilliardBoard::Border lineDownRight(997.5f, 466.5f, 997.5f, 830.5f);
	SampleBilliardBoard::Border lineDownRightR(997.5f, 830.5f, 1012.5f, 846.f);
	borderLines.push_back(lineDownRightL);
	borderLines.push_back(lineDownRight);
	borderLines.push_back(lineDownRightR);


	SampleBilliardBoard::Border lineDownL(998.5f, 860.f, 983.5f, 845.f);
	SampleBilliardBoard::Border lineDown(983.5f, 845.f, 616.5f, 845.f);
	SampleBilliardBoard::Border lineDownR(616.5f, 845.f, 602.5f, 860.5f);
	borderLines.push_back(lineDownL);
	borderLines.push_back(lineDown);
	borderLines.push_back(lineDownR);

	SampleBilliardBoard::Border lineDownLeftL(587.5f, 846.f, 602.5f, 830.5f);
	SampleBilliardBoard::Border lineDownLeft(602.5f, 830.5f, 602.5f, 466.5f);
	SampleBilliardBoard::Border lineDownLeftR(602.5f, 466.5f, 587.5f, 458.5f);
	borderLines.push_back(lineDownLeftL);
	borderLines.push_back(lineDownLeft);
	borderLines.push_back(lineDownLeftR);


	SampleBilliardBoard::Border lineTopLeftL(587.5f, 442.5f, 602.5f, 433.5f);
	SampleBilliardBoard::Border lineTopLeft(602.5f, 433.5f, 602.5f, 69.5f);
	SampleBilliardBoard::Border lineTopLeftR(602.5f, 69.5f, 587.5f, 54.f);
	borderLines.push_back(lineTopLeftL);
	borderLines.push_back(lineTopLeft);
	borderLines.push_back(lineTopLeftR);


	//Ȧ ��� �ʱ�ȭ
	SampleBilliardBoard::Hole holeTopLeft(582.5f, 49.f, 596.5f, 35.f);
	holesLinse.push_back(holeTopLeft);

	SampleBilliardBoard::Hole holeTopRight(1003.5f, 35.f, 1017.5f, 49.f);
	holesLinse.push_back(holeTopRight);

	SampleBilliardBoard::Hole holeRight(1012.5f, 442.f, 1012.5f, 458.5f);
	holesLinse.push_back(holeRight);

	SampleBilliardBoard::Hole holeDownRight(1017.5f, 851.f, 1003.5f, 865.f);
	holesLinse.push_back(holeDownRight);

	SampleBilliardBoard::Hole holeDownLeft(596.5f, 865.5f, 582.5f, 851.f);
	holesLinse.push_back(holeDownLeft);

	SampleBilliardBoard::Hole holeLeft(587.5f, 458.5f, 587.5f, 442.5f);
	holesLinse.push_back(holeLeft);


}

// �Ҹ��� 
SampleBilliardBoard::~SampleBilliardBoard(void)
{
	borderLines.clear();
}

// Sample Game�� ��ü���� �ݵ�� ���� ���� �Լ� �����ؾ� �� 
void SampleBilliardBoard::update(float timeElapsed)
{
	// Sample Game�� �籸��� ���� ���� X 
}

// Sample Game�� ��ü���� �ݵ�� �浹 ���� �����ؾ� ��
void SampleBilliardBoard::collide(SampleBilliardObject& other)
{
	// Sample Game�� �籸��� ���� ������Ʈ�̱� ������ �浹 X 
}

// Sample Game�� ��ü���� �ݵ�� ������ �Լ� �����ؾ� ��  
void SampleBilliardBoard::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}

// �籸�븦 �����ϴ� ��� ��� ��ȯ 
const std::vector<SampleBilliardBoard::Border>& SampleBilliardBoard::getBorders(void) const
{
	return borderLines;
}
// �籸�븦 �����ϴ� ���� ��� ��ȯ
const std::vector<SampleBilliardBoard::Hole>& SampleBilliardBoard::getHoles(void) const
{
	return holesLinse;
}