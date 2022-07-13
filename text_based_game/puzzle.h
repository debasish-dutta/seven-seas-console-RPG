#ifndef PUZZLE_H
#define PUZZLE_H

#include"STLIBINCLUDE.h"

class Puzzle
{
private:
	std::string ques;
	std::vector<std::string> ans;
	int correctAns;
public:
	Puzzle(std::string fileName);
	virtual ~Puzzle();
	std::string getString();
	
	inline const int& getCorrectAns()const { return this->correctAns;}
};



#endif
