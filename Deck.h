#pragma once

#include <algorithm>
#include <random>
#include "Hand.h"
#include "GenericPlayer.h"

class Deck : public Hand {
public:
    Deck() {
        cards.reserve(52);
        Populate();
    };

    virtual ~Deck() {};

    // ������� ����������� ������ �� 52 ����
    void Populate();

    // ������ �����
    void Shuffle();

    // ������� ���� ����� � ����
    void Deal(Hand& aHand);

    // ���� �������������� ����� ������
    void AdditionalCards(GenericPlayer& aGenericPlayer);
};
