#include <iostream>
#include <vector>

#include "Hand.h"

void Hand::add(Card* card) {
    cards.push_back(card);
};

void Hand::clear() {
    cards.clear();
};

int Hand::GetValue() const {
    int result = 0;
    for (auto const& i : cards) {
        if (result < 21 && i->getValue() == ACE) {
            result += 11;
        }
        else {
            result += i->getValue();
        }
    }
    return result;
}