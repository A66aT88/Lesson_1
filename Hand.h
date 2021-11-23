#pragma once
#include "Card.h"
#include "vector"

class Hand {
public:
    std::vector<Card*> cards;
    Hand() {}
    void add(Card* card);
    void clear();
    int GetValue() const;
};