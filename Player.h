#pragma once

#include "GenericPlayer.h"

class Player : public GenericPlayer {
public:
	Player(std::string newName) : GenericPlayer(newName) {}
	virtual ~Player() {}
	bool isHitting() const ;
	void Win() const;
	void Lose() const;
	void Push() const;
};
