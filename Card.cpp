#include "Card.h"

cardSuit Card::getSuit() const { return suit; }

cardValue Card::getValue() const { return value; }
bool Card::getPos() const { return cardPos; }

void Card::flip() {
	cardPos = !cardPos;
}

std::ostream& operator<< (std::ostream& out, const Card& card) {
	if (card.getPos()) {
		out << "Card suite: " << card.getSuit() << ". Card value: " << card.getValue();
	}
	else {
		out << "XX\n";
	}
	return out;
};
