#include "Deck.h"

void Deck::Populate()
{
    clear();
    for (int s = cardSuit::HEARTS; s <= cardSuit::CLUBS; ++s)
    {
        for (int r = cardValue::ACE; r <= cardValue::KING; ++r)
        {
            cards.push_back(new Card(static_cast<cardSuit>(s), static_cast<cardValue>(r), false));
        }
    }
}


void Deck::Shuffle()
{
    std::random_shuffle(cards.begin(), cards.end());
}


void Deck::Deal(Hand& aHand)
{
    if (!cards.empty())
    {
        aHand.add(cards.back());
        cards.pop_back();
    }
    else
    {
        std::cout << "Out of cards. Unable to deal.";
    }
}


void Deck::AdditionalCards(GenericPlayer& aGenericPlayer)
{
    std::cout << std::endl;
    while (!(aGenericPlayer.isBoosted()) && aGenericPlayer.isHitting())
    {
        Deal(aGenericPlayer);
        std::cout << aGenericPlayer << std::endl;

        if (aGenericPlayer.isBoosted())
        {
            aGenericPlayer.Bust();
        }
    }
}
