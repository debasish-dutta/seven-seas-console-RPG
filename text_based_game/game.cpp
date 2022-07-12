#include"game.h"
using namespace std;

Game::Game() {
	choice = 0;
    playing = true;
}

Game::~Game() {

}

int gameStart = 0;
char name[50];

void Game::initGame() {
	cout<<"Would you like to play a game? Press the 1 button to start, otherwise hit anything else to end."<<endl;
	cin >> gameStart;
	
	if(gameStart==1) //Go through introduction if user wants to play.
	{
		cout<<"Welcome!"<<endl;
		cout<<"What is your name, warrior?"<<endl;
		cin.getline(name, 50);
		cout<<"Hello brave adventurer,"<<name<<"!"<<endl;
		cout<<"Welcome to the land of 7 Seas! Your goal is to become the emperor of the 7 kingdoms in these 7 seas. And each kingdom is occupied by different monsters & magical creatures!"<<endl;
		cout<<"Fight through numerous monsters & magical creatures to win the throne!!"<<endl;
		cout<<"Level Up, Collect Items and Weapons and Armour along the way to conquer the final land to become the emperor of the 7 seas!"<<endl;
		cout<<"You will be given a stick to fight. Best of luck!"<<endl;
	}
	else
	{
		cout<<"Ending program"<<endl;
	}
}

void Game::mainMenu() {

    cout << "General Gameplay:" << "\n";
	cout << "You can move in four directions" << "\n";
	cout << "And for each new area you arrive you will encounter different things" << "\n";
	cout << "To move: " << "\n";
	cout << "N: North" << "\n";
	cout << "E: East" << "\n";
	cout << "W: West" << "\n";
	cout << "S: South" << "\n";
    cout << "\n";

	cout << "\n" << "Choice: ";
	cin >> choice;

    switch(choice) {
        case 0:
            playing = false;
            break;
		case 'N':
		case 'n':
			playing = false;
			break;
		case 'E':
		case 'e':
			playing = false;
			break;
		case 'W':
		case 'w':
			playing = false;
			break;
		case 'S':
		case 's':
			playing = false;
			break;
		default:
			cout << "Invalid Command!! Cannot understand!!" << endl;

    }
}
