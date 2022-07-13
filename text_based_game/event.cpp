#include "event.h"

int Event::noOfEvents = 3;

Event::Event() {

}

Event::~Event() {
	
}

void Event::createEvent(Player &player, dArr<Monster>& monsters) {
	int i = rand() % Event::noOfEvents;
	
	switch(i) {
		case 0:
			//Enemy encounter
			this->enemyEncounter(player, monsters);
			break;
		case 1:
			// Puzzle
			this->puzzleEncounter(player);
			break;
		case 2:
			// RescueEncounter
			std::cout << "Rescue Attempt" << "\n";
			break;
		case 3:
			// Boss encounter
			std::cout << "Encounter Boss" << "\n";
			break;
		default:
			break;
	}
}

//Different Events
void Event::enemyEncounter(Player &player, dArr<Monster>& monsters) {
	bool playerTurn = false;
		int choice = 0;

		//Coin toss for turn
		int coinToss = rand() % 2 + 1;

		if (coinToss == 1)
			playerTurn = true;
		else
			playerTurn = false;

		//End conditions
		bool escape = false;
		bool playerDefeated = false;
		bool enemiesDefeated = false;

		//Enemies
		int nrOfEnemies = rand() % 5 + 1;

		for (size_t i = 0; i < nrOfEnemies; i++)
		{
			monsters.push(Monster(player.getLvl() + rand()%3));
		}

		//Battle variables
		int damage = 0;
		int gainExp = 0;
		int gainCoins = 0;
		int playerTotal = 0;
		int enemyTotal = 0;
		int combatTotal = 0;
		int combatRollPlayer = 0;
		int combatRollEnemy = 0;

		while (!escape && !playerDefeated && !enemiesDefeated)
		{
			if (playerTurn && !playerDefeated)
			{
				//Menu
				//system("CLS");

				std::cout << "= PLAYER TURN =" << "\n\n";
				std::cout << "Continue..." << "\n\n";
				std::cin.get();

				std::cout << "= BATTLE MENU =" << "\n\n";
				std::cout << "HP: " << player.getHp() << " / " << player.getmaxHp() << "\n\n";

				std::cout << "0: Escape" << "\n";
				std::cout << "1: Attack" << "\n";
				std::cout << "2: Defend" << "\n";
				std::cout << "3: Use Item" << "\n";
				std::cout << "\n";

				std::cout << "Choice: ";

				std::cin >> choice;

				while (std::cin.fail() || choice > 3 || choice < 0)
				{
					std::cout << "Faulty input!" << "\n";
					std::cin.clear();
					std::cin.ignore(100, '\n');

					std::cout << "= BATTLE MENU =" << "\n\n";

					std::cout << "0: Escape" << "\n";
					std::cout << "1: Attack" << "\n";
					std::cout << "2: Defend" << "\n";
					std::cout << "3: Use Item" << "\n";
					std::cout << "\n";

					std::cout << "Choice: ";
					std::cin >> choice;
				}

				std::cin.ignore(100, '\n');
				std::cout << "\n";

				//Moves
				switch (choice)
				{
				case 0: //ESCAPE
					escape = true;
					break;

				case 1: //ATTACK

					//Select enemy
					std::cout << "Select enemy: " << "\n\n";

					for (int i = 0; i < monsters.size(); i++)
					{
						std::cout << i << ": "
							<< "Level: " << monsters[i].getLvl() << " - " <<
							"HP: " << monsters[i].getHp() << "/" << monsters[i].getmaxHp() << " - " <<
							"Defence: " << monsters[i].getArmour() << " - " <<
							"Accuracy: " << monsters[i].getAcc() << " - " <<
							"Damage: " << monsters[i].getAtkMin() << " - " << monsters[i].getAtkMax() <<
							"\n";
					}

					std::cout << "\n";
						std::cout << "Choice: ";

						std::cin >> choice;

					while (std::cin.fail() || choice >= monsters.size() || choice < 0)
					{
						std::cout << "Faulty input!" << "\n";
						std::cin.clear();
						std::cin.ignore(100, '\n');

						std::cout << "Select enemy: " << "\n\n";
						std::cout << "Choice: ";
						std::cin >> choice;
					}

						std::cin.ignore(100, '\n');
						std::cout << "\n";

					//Attack roll
					combatTotal = monsters[choice].getArmour() + player.getAcc();
					enemyTotal = monsters[choice].getArmour() / (double)combatTotal * 100;
					playerTotal = player.getAcc() / (double)combatTotal * 100;
					combatRollPlayer = rand() % playerTotal + 1;
					combatRollEnemy = rand() % enemyTotal + 1;

					std::cout << "Combat total: " << combatTotal << "\n";
					std::cout << "Enemy percent: " << enemyTotal << "\n";
					std::cout << "Player percent: " << playerTotal << "\n\n";
					std::cout << "Player roll: " << combatRollPlayer << "\n";
					std::cout << "Enemy roll: " << combatRollEnemy << "\n\n";

					if (combatRollPlayer > combatRollEnemy) //Hit
					{
						std::cout << "HIT! " << "\n\n";
						
						damage = player.getAtk();
						monsters[choice].takeDamage(damage);

						std::cout << "Damage: " << damage << "!" << "\n\n";

						if (!monsters[choice].isAlive())
						{
							std::cout << "ENEMY DEFEATED!" << "\n\n";
							gainExp = monsters[choice].getExp();
							player.gainExp(gainExp);
							gainCoins = rand() % monsters[choice].getLvl() * 10 + 1;
							player.gainCoins(gainCoins);
							std::cout << "EXP GAINED: " << gainExp << "\n";
							std::cout << "GOLD GAINED: " << gainCoins << "\n\n";

							//Item roll
							int roll = rand() % 100 + 1;
							int rarity = -1;

							if (roll > 20)
							{
								rarity = 0; //Common
								
								roll = rand() % 100 + 1;
								if (roll > 30)
								{
									rarity = 1; //Uncommon

									roll = rand() % 100 + 1;
									if (roll > 50)
									{
										rarity = 2; //Rare

										roll = rand() % 100 + 1;
										if (roll > 70)
										{
											rarity = 3; //Legendary

											roll = rand() % 100 + 1;
											if (roll > 90)
											{
												rarity = 4; //Mythic
											}
										}
									}
								}
							}

							if (roll >= 0)
							{
								roll = rand() % 100 + 1;

								if (roll > 50)
								{
									Weapon tempW(player.getLvl(), rarity);
									player.addItem(tempW);
									std::cout << "WEAPON DROP!" << "\n";
								}
								else
								{
									Armour tempA(player.getLvl(), rarity);
									player.addItem(tempA);
									std::cout << "ARMOR DROP!" << "\n";
								}
							}

							monsters.remove(choice);
						}
					}
					else //Miss
					{
						std::cout << "MISSED! \n\n";
					}

					break;

				case 2: //DEFEND

					break;

				case 3: //ITEM

					break;

				default:
					break;
				}

				//End turn
				playerTurn = false;
			}
			else if(!playerTurn && !playerDefeated && !escape && !enemiesDefeated)
			{
				std::cout << "= ENEMY TURN =" << "\n";

				std::cout << "Continue..." << "\n\n";
				std::cin.get();

				//Enemy attack
				for (int i = 0; i < monsters.size(); i++)
				{
					std::cout << "Continue..." << "\n\n";
					std::cin.get();
					
					std::cout << "Enemy: " << i << "\n\n";

					//Attack roll
					combatTotal = monsters[i].getAcc() + (player.getArmour() + player.getExtraArmour());
					enemyTotal = monsters[i].getAcc() / (double)combatTotal * 100;
					playerTotal = (player.getArmour() + player.getExtraArmour()) / (double)combatTotal * 100;
					combatRollPlayer = rand() % playerTotal + 1;
					combatRollEnemy = rand() % enemyTotal + 1;

					std::cout << "Combat total: " << combatTotal << "\n";
					std::cout << "Enemy percent: " << enemyTotal << "\n";
					std::cout << "Player percent: " << playerTotal << "\n\n";
					std::cout << "Player roll: " << combatRollPlayer << "\n";
					std::cout << "Enemy roll: " << combatRollEnemy << "\n\n";

					if (combatRollPlayer < combatRollEnemy) //Hit
					{
						std::cout << "HIT! " << "\n\n";

						damage = monsters[i].getArmour();
						player.takeDamage(damage);

						std::cout << "Damage: " << damage << "!" << "\n";
						std::cout << "HP: " << player.getHp() << " / " << player.getmaxHp() << "\n\n";

						if (!player.isAlive())
						{
							std::cout << "YOU ARE DEFEATED!" << "\n\n";
							playerDefeated = true;
						}
					}
					else //Miss
					{
						std::cout << "MISSED! \n\n";
					}
				}

				//End turn
				playerTurn = true;
			}

			//Conditions
			if (!player.isAlive())
			{
				playerDefeated = true;
			}
			else if (monsters.size() <= 0)
			{
				enemiesDefeated = true;
			}
		}
}

void Event::puzzleEncounter(Player &player) {
	
	bool completed = false;
	int userAns = 0;
	int chances = 3;
	int gainExp = (chances * player.getLvl() * (rand()%10 + 1));
	int gainCoins = (chances * player.getLvl() * (rand() % 10 + 1));
	
	Puzzle puzzle("/Users/debasishdutta/My Programming Stuffs/C_C++/cpp_projects/text-based-game/text_based_game/text_based_game/Puzzles/2.txt");
	
	while(!completed && chances > 0) {
		std::cout << "Chances: " << chances << "\n\n";
		chances--;
		std::cout << puzzle.getString() << "\n";
		std::cout << "Your Answer: ";
		std::cin >> userAns;
		
		while (std::cin.fail()) {
			std::cout << "Faulty input!!" << "\n";
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "\nYour Answer: ";
			std::cin >> userAns;
		}
		std::cin.ignore(100, '\n');
		std::cout << "\n";
		
		if(puzzle.getCorrectAns() == userAns){
			completed = true;
			
			player.gainExp(gainExp);
			player.gainCoins(gainCoins);
			std::cout << "YOU GAINED " << gainExp << " EXP!" << "\n";
			std::cout << "YOU GAINED " << gainCoins << " COINS!" << "\n\n";
		}
	}
	
	if (completed) {
		std::cout << "CONGRATZ YOU SUCCEDED! \n\n";
	}
	else{
		std::cout << "YOU FAILED BRAH! \n\n";
	}
}
