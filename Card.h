#pragma once
#include "iostream"

enum cardSuit {
	HEARTS,
	SPADES,
	DIAMONDS,
	CLUBS
};

enum cardValue {
	ACE = 1,
	TWO = 2,
	THREE = 3,
	FOUR = 4,
	FIVE = 5,
	SIX = 6,
	SEVEN = 7,
	EIGHT = 8,
	NINE = 9,
	TEN = 10,
	JACK = 10,
	QUEEN = 10,
	KING = 10
};

class Card {
public:
	cardSuit suit;
	cardValue value;
	bool cardPos;
	Card(cardSuit newSuit, cardValue newValue, bool newPos) : suit(newSuit), value(newValue), cardPos(newPos) {}
	virtual ~Card() {}

	cardSuit getSuit() const;
	cardValue getValue() const;
	bool getPos() const;

	void flip();

	friend std::ostream& operator<< (std::ostream& out, const Card& string);
};