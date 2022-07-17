#ifndef GAME_H
#define GAME_H

#include"STLIBINCLUDE.h"
#include "event.h"

class Game {

    private:
        int choice;
        bool playing;
	
		//Main Player
		int activePlayer;
		std::vector<Player> players;
		std::string fileName;
		dArr<Monster> monsters;

    public:

        Game();
        virtual ~Game();

		//Functions
        void initGame();
        void mainMenu();
		void createNewCharacter();
		void levelUpPlayer();
		void characterMenu();
		void savePlayer();
		void loadPlayer();
		void selectPlayer();
		void Travel();

		
		//Accessors
        inline bool getPlaying() const { return this->playing; }
		

};


#endif
