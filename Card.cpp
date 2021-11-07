#include "Card.h"

cardSuit Card::getSuit() { return suit; }

cardValue Card::getValue() { return value; }
bool Card::getPos() { return cardPos; }

void Card::flip() {
	cardPos = !cardPos;
}