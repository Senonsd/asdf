#include "BaseGame.h"
#include "SampleGame.h"

int main(void)
{
	// ���� ���� 
	BaseGame&& game = SampleGame(1024, 1024, 60);
	
	// ���� ���� 
	game.run();

	return 0;
}
