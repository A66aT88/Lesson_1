#pragma once

#include <vector>
#include "Deck.h"
#include "House.h"
#include "Player.h"

class Game
{
public:
    Game(const std::vector<std::string>& names);

    ~Game();

    // �������� ���� � Blackjack
    void Play();

private:
    Deck m_Deck;
    House m_House;
    std::vector<Player> m_Players;
};

// ����������� ����� ������ ��������� ������ �� ������ �����, ��������������
// ����� �������-�����. ����������� ������� ������ ������ Player ��� ������� �����
Game::Game(const std::vector<std::string>& names)
{
    // ������� ������ ������� �� ������� � �������
    std::vector<std::string>::const_iterator pName;
    for (pName = names.begin(); pName != names.end(); ++pName)
    {
        m_Players.push_back(Player(*pName));
    }

    // ��������� ��������� ��������� �����
    srand(static_cast<unsigned int>(time(0)));
    m_Deck.Populate();
    m_Deck.Shuffle();
}

Game::~Game()
{}

void Game::Play()
{
    // ������� ������� �� ��� ��������� �����
    std::vector<Player>::iterator pPlayer;
    for (int i = 0; i < 2; ++i)
    {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        {
            m_Deck.Deal(*pPlayer);
        }
        m_Deck.Deal(m_House);
    }

    // ������ ������ ����� ������
    m_House.flipTopCard();

    // ��������� ���� ���� �������
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
    {
        std::cout << *pPlayer << std::endl;
    }
    std::cout << m_House << std::endl;

    // ������� ������� �������������� �����
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
    {
        m_Deck.AdditionalCards(*pPlayer);
    }

    // ���������� ������ ����� ������
    m_House.flipTopCard();
    std::cout << std::endl << m_House;

    // ������� ������ �������������� �����
    m_Deck.AdditionalCards(m_House);

    if (m_House.isBoosted())
    {
        // ���, ��� ������� � ����, ���������
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        {
            if (!(pPlayer->isBoosted()))
            {
                pPlayer->Win();
            }
        }
    }
    else
    {
        // ���������� ����� ����� ���� ���������� ������� � ������ ����� ������
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end();
            ++pPlayer)
        {
            if (!(pPlayer->isBoosted()))
            {
                if (pPlayer->GetValue() > m_House.GetValue())
                {
                    pPlayer->Win();
                }
                else if (pPlayer->GetValue() < m_House.GetValue())
                {
                    pPlayer->Lose();
                }
                else
                {
                    pPlayer->Push();
                }
            }
        }

    }

    // ������� ���� ���� �������
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
    {
        pPlayer->clear();
    }
    m_House.clear();
}
