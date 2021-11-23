#include <iostream>

#include "GenericPlayer.h"

bool GenericPlayer::isBoosted() {
	return (this->GetValue() > 21);
}

void GenericPlayer::Bust() {
	std::cout << "Players name: " << name << ". Status: Bust" << std::endl;
}

std::ostream& operator<< (std::ostream& out, const GenericPlayer& player) {
	const std::string RANKS[] = { "0", "ACE", "2", "3", "4", "5", "6", "7", "8", "9", "10", "JACK", "QUEEN", "KONG" };
	const std::string SUITS[] = { "Clubs", "Diamonds", "Hearts", "Spades" };

	out << "Players name: " << player.getName() << "\n";

	for (int i = 0; i < player.cards.size(); i++) {
		out << SUITS[player.cards[i]->getSuit()] << " " << RANKS[player.cards[i]->getValue()] << "\n";
	}
	return out;
};
