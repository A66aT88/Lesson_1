#include "House.h"

House::House(const std::string name) : GenericPlayer(name) {}
House::~House() {}
bool House::isHitting() const {
    return (GetValue() <= 16);
}

void House::flipTopCard() {
    if (!(cards.empty()))
        cards[0]->flip();
    else
        std::cout << "No card to flip!\n";
}