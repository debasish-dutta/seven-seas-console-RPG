#include"game.h"

using namespace std;




int main()
{
	std::srand( (unsigned int) time(NULL));

	Game Game;

	Game.initGame();

	while(Game.getPlaying())
	{

		Game.mainMenu();
	}


	return 0;
}
