#include "puzzle.h"

Puzzle::Puzzle(std::string fileName) {
	std::ifstream inFile(fileName);
	int noOfAns = 0;
	std::string ans = "";
	this->correctAns = 0;
	int correctAnsw = 0;
	
	if(inFile.is_open()) {
		std::getline(inFile, this->ques);
		inFile >> noOfAns;
		inFile.ignore();
		for (size_t i =0; i< noOfAns; i++) {
			std::getline(inFile, ans);
			this->ans.push_back(ans);
		}
		inFile >> correctAnsw;
		this->correctAns = correctAnsw;
		inFile.ignore();
		
		}
	else
		
		throw ("Could not open Puzzle!!");
	
	inFile.close();
}

Puzzle::~Puzzle() {
	
}

std::string Puzzle::getString() {
	std::string ans = "";
	
	for(size_t i =0; i< this->ans.size(); i++) {
		ans += std::to_string(i) + ": " + this->ans[i] + "\n";
	}
	
	
	return this->ques + "\n" + "\n"
					+ ans + "\n" ;
}
