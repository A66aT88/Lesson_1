#include "Card.h"

cardSuit Card::getSuit() const { return suit; }

cardValue Card::getValue() const { return value; }
bool Card::getPos() const { return cardPos; }

void Card::flip() {
	cardPos = !cardPos;
}