#include"game.h"
//using namespace std;

Game::Game() {
	choice = 0;
    playing = true;
	activePlayer = 0;
	fileName = "doc/characters.txt";
}

Game::~Game() {

}


void Game::initGame() {
	std::ifstream in;
		in.open("doc/characters.txt");

		Weapon::initNames();
		Armour::initNames();

		if (in.is_open())
			this->loadPlayer();
		else
		{
			createNewCharacter();
			this->savePlayer();
		}

	in.close();
	
	
}


void Game::mainMenu() {

		if (this->players[activePlayer].isAlive())
		{
			if (this->players[activePlayer].getExp() >=
				this->players[activePlayer].getexpReq())
			{
				std::cout << "LEVEL UP AVAILABLE! \n\n";
			}

			std::cout << "= MAIN MENU =" << "\n" << "\n";

			std::cout << "= Active character: " <<
				this->players[activePlayer].getName() << " Total: " <<
				this->activePlayer + 1 << "/" << this->players.size() <<
				" =" << "\n" << "\n";
				
			std::cout << "0: Quit" << "\n";
			std::cout << "1: Travel" << "\n";
			std::cout << "2: Level up" << "\n";
			std::cout << "3: Rest" << "\n";
			std::cout << "4: Character sheet" << "\n";
			std::cout << "5: Create new character" << "\n";
			std::cout << "6: Select Player" << "\n";
			std::cout << "7: Save Player" << "\n";
			std::cout << "8: Load Player" << "\n";

			std::cout << "\n";

			std::cout << "\n" << "Choice: ";
			std::cin >> this->choice;

			while (std::cin.fail() || this->choice > 9)
			{
				std::cout << "Faulty input!" << "\n";
				std::cin.clear();
				std::cin.ignore(100, '\n');

				std::cout << "\n" << "Choice (0 - 8): ";
				std::cin >> this->choice;
			}

			std::cin.ignore(100, '\n');
			std::cout << "\n";

			switch (this->choice)
			{
			case 0: //QUIT
				playing = false;
					std::cout << "Come back to continue your adventure!!!!" << "\n";
				this->savePlayer();

				break;

			case 1: //TRAVEL
				Travel();

				break;

			case 2: //LEVEL UP
				this->levelUpPlayer();

				break;

			case 3: //REST
//				rest();

				break;

			case 4: //CHAR SHEET
				this->characterMenu();
				break;

			case 5: //CREATE NEW CHAR
				createNewCharacter();
				savePlayer();
				break;

			case 6: //SELECT CHAR
				selectPlayer();
				break;

			case 7: //SAVE CHARS
				savePlayer();
				break;

			case 8: //LOAD CHARS
				loadPlayer();
				break;

			default:
				break;
			}
		}
		else
		{
			std::cout << "= YOU ARE DEAD, LOAD? =" << "\n" << "\n";
			std::cout << "(0) Yes, (1) No " << "\n";
			std::cin >> this->choice;

			while (std::cin.fail() || this->choice < 0 || this->choice > 1)
			{
				std::cout << "Faulty input!" << "\n";
				std::cin.clear();
				std::cin.ignore(100, '\n');
				
				std::cout << "(0) Yes, (1) No " << "\n";
				std::cin >> this->choice;
			}

			std::cin.ignore(100, '\n');
			std::cout << "\n";

			if (this->choice == 0)
				this->loadPlayer();
			else
				playing = false;
		}
	

		

}

void Game::createNewCharacter() {
	std::string name = "";
	std::cout<<"Welcome!"<<std::endl;
	std::cout << "What is your name warrior!?  " ;
	getline(std::cin, name);

	for (size_t i = 0; i < this->players.size(); i++)
	{
		while (name == this->players[i].getName())
		{
			std::cout << "Error! Character already exists!" << "\n";
			std::cout << "Character name: ";
			getline(std::cin, name);
		}
	}
	
	std::cout<<"Hello brave adventurer, "<<name<<"!"<<std::endl;
	std::cout<<"Welcome to the land of 7 Seas! Your goal is to become the emperor of the 7 kingdoms in these 7 seas."<<std::endl;
	std::cout<<"And each kingdom is occupied by different monsters & magical creatures!"<<std::endl;
	std::cout<<"Fight through numerous monsters & magical creatures to win the throne!!"<<std::endl;
	std::cout<<"Level Up, Collect Items and Weapons and Armour along the way to conquer the final land to become the emperor of the 7 seas!"<<std::endl;
	std::cout<<"Best of luck!!!"<<std::endl;
	std::cout <<"\n";
	std::cout << "\n";

	players.push_back(Player());
	activePlayer = players.size() - 1.0;
	players[activePlayer].initialize(name);
}

void Game::characterMenu() {
	
	players[activePlayer].printStats();
	std::cout << this->players[this->activePlayer].getInvAsString();
}


void Game::savePlayer() {
	std::ofstream outFile(fileName);
	if(outFile.is_open()) {
		for (size_t i =0; i< players.size(); i++) {
			outFile << players[i].getAsString() << "\n";
			outFile << this->players[i].getInvAsStringSave() << "\n";
		}
	}
	outFile.close();
}

void Game::loadPlayer() {
	std::ifstream inFile(fileName);
	
	this->players.clear();
	
	std::string name = "";
	int distancetravelled = 0;
	int Exp = 0;
	int Lvl = 0;
	int Hp = 0;
	int maxHp = 0;
	int Atk = 0;
	int expReq = 0;
	int Acc = 0;
	int Armor = 0;
	int Coins = 0;
	
	// Items
	int itemType = 0;
	int level = 0;
	int damageMin = 0;
	int damageMax = 0;
	int defence = 0;
	int sellValue = 0;
	int buyValue = 0;
	int rarity = 0;
	
	Inventory tempItems;
	std::string line = "";
	std::stringstream str;
	
	if(inFile.is_open()) {
		while(std::getline(inFile, line)) {
			str.str(line);
			str >> name;
			str >> distancetravelled;
			str >> Exp;
			str >> Lvl;
			str >> Hp;
			str >> maxHp;
			str >> Atk;
			str >> expReq;
			str >> Acc;
			str >> Armor;
			str >> Coins;
			
			//Create Player
			Player tempP(name, distancetravelled, Exp, Lvl, Hp, maxHp, Atk, expReq, Acc, Armor, Coins);
			//Weapon
			str >> itemType >> name >> level >> rarity >> sellValue >> buyValue >> damageMin >> damageMax;
			Weapon weapon(damageMin, damageMax, name, level, buyValue, sellValue, rarity);
			//Armour
			str >> itemType >> name >> level >> rarity >> sellValue >> buyValue >> defence;
			Armour armour(defence, name, level, buyValue, sellValue, rarity);
			
			tempP.setWeapon(weapon);
			tempP.setArmour(armour);
			
			//Set Inventory
			str.clear();
			line.clear();
			std::getline(inFile, line);
			str.str(line);
			
			while (str >> itemType >> name >> level >> rarity >> buyValue >> sellValue >> damageMin >> damageMax) {
					tempP.addItem(
						Weapon(damageMin, damageMax,name,level,buyValue,sellValue, rarity)
				);
			}
			str.clear();
			line.clear();
			std::getline(inFile, line);
			str.str(line);
			
			while (str >> itemType >> name >> level >> rarity >> buyValue >> sellValue >> defence) {
					tempP.addItem(
						Armour(defence,name,level,buyValue,sellValue,rarity)
					);
			}
			
			this->players.push_back(Player(tempP));
			std::cout << "Player " << tempP.getName() << " loaded!\n";
			str.clear();
		}
	}
	inFile.close();
	if (this->players.size() <= 0)
		{
			throw "ERROR! NO PLAYERS LOADED OR EMPTY FILE!";
		}
}

void Game::selectPlayer()
{
	std::cout << "Select character: " << "\n\n";

	for (int i = 0; i < this->players.size(); i++)
	{
		std::cout << "Index: " << i << " = " << this->players[i].getName() << " Level: " << this->players[i].getLvl() << "\n";
	}

	std::cout << "\n";

	std::cout << "Choice: ";

	std::cin >> this->choice;

	while (std::cin.fail() || this->choice >= this->players.size() || this->choice < 0)
	{
		std::cout << "Faulty input!" << "\n";
		std::cin.clear();
		std::cin.ignore(100, '\n');

		std::cout << "Select character: " << "\n";
		std::cin >> this->choice;
	}

	std::cin.ignore(100, '\n');
	std::cout << "\n";

	this->activePlayer = this->choice;

	std::cout << this->players[this->activePlayer].getName() << " is SELECTED!" << "\n\n";
}


void Game::levelUpPlayer() {
	this->players[activePlayer].levelUp();
}

void Game::Travel() {
	this->players[activePlayer].travel();
	
	Event ev;
	ev.createEvent(this->players[activePlayer], this->monsters);
}
