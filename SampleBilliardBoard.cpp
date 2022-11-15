#include "SampleBilliardBoard.h"

SampleBilliardBoard::SampleBilliardBoard(void)
{
	// Sample Game을 위한 당구대 텍스처 이미지 로드 
	texture.loadFromFile("textureBoard.png", sf::IntRect(1, 1, 454, 848));
	
	// 스프라이트 설정 
	sprite.setTexture(texture);
	sprite.setPosition(572.5f, 25.f);

	// 당구대 경계 초기화 - 상하좌우 
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


	//홀 경계 초기화
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

// 소멸자 
SampleBilliardBoard::~SampleBilliardBoard(void)
{
	borderLines.clear();
}

// Sample Game의 객체들은 반드시 상태 갱신 함수 구현해야 함 
void SampleBilliardBoard::update(float timeElapsed)
{
	// Sample Game의 당구대는 상태 갱신 X 
}

// Sample Game의 객체들은 반드시 충돌 물리 구현해야 함
void SampleBilliardBoard::collide(SampleBilliardObject& other)
{
	// Sample Game의 당구대는 고정 오브젝트이기 때문에 충돌 X 
}

// Sample Game의 객체들은 반드시 렌더링 함수 구현해야 함  
void SampleBilliardBoard::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}

// 당구대를 구성하는 경계 요소 반환 
const std::vector<SampleBilliardBoard::Border>& SampleBilliardBoard::getBorders(void) const
{
	return borderLines;
}
// 당구대를 구성하는 구멍 요소 반환
const std::vector<SampleBilliardBoard::Hole>& SampleBilliardBoard::getHoles(void) const
{
	return holesLinse;
}