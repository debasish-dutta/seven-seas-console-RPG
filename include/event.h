#ifndef EVENT_H
#define EVENT_H

#include"STLIBINCLUDE.h"
#include "player.h"
#include "puzzle.h"
#include "monster.h"
#include "room.h"

class Event
{
private:

public:
	Event();
	virtual ~Event();
	
	void createEvent(Player &player, dArr<Monster>& monsters);
	void enemyEncounter(Player &player, dArr<Monster>& monsters);
	void puzzleEncounter(Player &player);
	
	static int noOfEvents;

	static dArr<std::string> puzzle_loc;
	static void initLocns();
	
};


#endif
