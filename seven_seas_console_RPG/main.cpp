#include"game.h"
#include <math.h>

using namespace std;




int main()
{
	srand( (unsigned int) time(NULL));

	Game Game;

	Game.initGame();
	
	while(Game.getPlaying())
	{

		Game.mainMenu();
	}


	return 0;
}
