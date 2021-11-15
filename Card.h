#pragma once
#include "iostream"

enum cardSuit {
	HEARTS,
	SPADES,
	DIAMONDS,
	CLUBS
};

enum cardValue {
	TWO = 2,
	THREE = 3,
	FOUR = 4,
	FIVE = 5,
	SIX = 6,
	SEVEN = 7,
	EIGHT = 8,
	NINE = 9,
	TEN = 10,
	JACK = 11,
	QUEEN = 12,
	KING = 13,
	ACE = 1
};

class Card {
	cardSuit suit;
	cardValue value;
	bool cardPos;
public:
	Card(cardSuit newSuit, cardValue newValue, bool newPos) : suit(newSuit), value(newValue), cardPos(newPos) {}
	virtual ~Card() {}

	cardSuit getSuit() const;
	cardValue getValue() const;
	bool getPos() const;

	void flip();

	friend std::ostream& operator<< (std::ostream& out, const Card& string);
};