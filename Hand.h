#pragma once
#include "Card.h"

class Hand {
    std::vector<Card*> cards;
public:
    Hand() {}
    void add(Card* card);
    void clear();
    int GetValue();
};