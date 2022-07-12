#include"game.h"


using namespace std;




int main()
{
	srand(time(NULL));

	Game Game;
	
	Game.initGame();
	
	while(Game.getPlaying())
	{
		
		Game.mainMenu();
	}


	return 0;
}
