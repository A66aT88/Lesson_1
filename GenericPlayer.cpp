#include <iostream>

#include "GenericPlayer.h"

bool GenericPlayer::isBoosted() {
	return (this->GetValue() > 21);
}
void GenericPlayer::Bust() {
	std::cout << "Players name: " << name << ". Status: Bust" << std::endl;
}