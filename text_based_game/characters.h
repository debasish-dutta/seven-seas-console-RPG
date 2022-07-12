#ifndef CHARACTER_H
#define CHARACTER_H

#include"STLIBINCLUDE.h"
// using namespace std;

class Character
{
    // Traits that are common to both players and monsters.
    private:

        std::string name;
        
        int Exp;
        int Lvl;
        int Hp;
        int maxHp; 
        int Atk;
        int expReq;
    
    public:
        Character();
        virtual ~Character();

        void levelUp();
		void initialize(const std::string name);


        inline void gainExp(const int Exp) { this->Exp += Exp; }
	
		// Accessors
	inline const std::string& getName() const { return this->name;}
	inline const int& getLvl() const { return this->Lvl;}
	inline const int& getExp() const { return this->Exp;}
	inline const int& getexpReq() const { return this->expReq;}
	inline const int& getHp() const { return this->Hp;}
	inline const int& getmaxHp() const { return this->maxHp;}
	inline const int& getAtk() const { return this->Atk;}
	

};

#endif
