#ifndef GAME_H
#define GAME_H

#include"STLIBINCLUDE.h"

class Game {

    private:
        int choice;
        bool playing; 

    public:

        Game();
        virtual ~Game();


        void initGame();
        void mainMenu();
        void characterMenu();

		
        inline bool getPlaying() const { return this->playing; }
		

};


#endif
