#pragma once

#include "Hand.h"

class GenericPlayer : public Hand {
	std::string name;
public:
	GenericPlayer(std::string newName) : Hand(), name(newName) {}
	std::string getName() const { return name; }
	virtual bool isHitting() = 0;
	bool isBoosted();
	void Bust();

	friend std::ostream& operator<< (std::ostream& out, const GenericPlayer& string);
};