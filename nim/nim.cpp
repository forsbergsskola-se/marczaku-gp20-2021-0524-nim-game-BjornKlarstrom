#include <iostream>
#include <ctime>
#include "nim.h"

int GetPlayerChoice()
{
    int Choice;
    
    do
    {
        std::cout << "\n     How many matches do you want to draw? (max 3): ";
        std::cin >> Choice;

        if (Choice >= 1 && Choice <= 3)
        {
            std::cout << "\n     You draw " << Choice << " matches";
            return Choice;
        }
        else 
        {
            std::cout << "\n     Try again.. Input not correct";
        }

        std::cin.clear();
        std::cin.ignore();
    }     
    while (true);
}

int GetAiChoice()
{
    int AiChoice = rand() % 3 + 1;

    std::cout << "\n\n     Ai draws " << AiChoice << " matches";

    return AiChoice;
}


void ShowMatchesLeft(int MatchesLeft)
{
    std::cout << "\n     ";
    for (int i = 0; i < MatchesLeft; i++)
    {
        std::cout << "| ";
    }
}

void PlayerVsAi(int& MatchesLeft, bool& IsPlayerOnesTurn)
{
    ShowMatchesLeft(MatchesLeft);

    while (MatchesLeft > 0)
    {
        IsPlayerOnesTurn = !IsPlayerOnesTurn;
        MatchesLeft -= IsPlayerOnesTurn ? GetPlayerChoice() : GetAiChoice();

        ShowMatchesLeft(MatchesLeft);
    }
    std::cout << (IsPlayerOnesTurn ? "\n\n     To bad.. Ai won the game :(" :
        "\n\n     Concratulations! you won the game!");

    std::cout << "\n\n";
}

void PlayerVsPlayer(int& MatchesLeft, bool& IsPlayerOnesTurn)
{
    ShowMatchesLeft(MatchesLeft);

    while (MatchesLeft > 0)
    {
        IsPlayerOnesTurn = !IsPlayerOnesTurn;

        std::cout << (IsPlayerOnesTurn ? "\n     Player One. How many matches do you want to draw? (max 3)" :
                                         "\n     Player Two. How many matches do you want to draw? (max 3)");

        MatchesLeft -= GetPlayerChoice();

        ShowMatchesLeft(MatchesLeft);
    }

    std::cout << (IsPlayerOnesTurn ? "\n\n     Player One " : "\n\n     Player Two ") << "WON!!!";
    std::cout << "\n\n";
}

int main()
{
    const int MatchesToStartWith = 24;
    int MatchesLeft = MatchesToStartWith;
    srand(time(NULL));
    bool IsPlayerOnesTurn = rand() % 2;
    int PlayerMode;
   

    std::cout << "\n               -----------------------------\n";
    std::cout << "                        WELCOME TO\n";
    std::cout << "                      THE N.I.M GAME!";
    std::cout << "\n               -----------------------------\n";
    std::cout << "\n     A game about picking matches and avoiding the last one";
    std::cout << "\n     Picking the last one will result in death\n\n";


    std::cout << "\n     How whould you like to play?";
    std::cout << "\n     Player vs Ai (Enter number 1)";
    std::cout << "\n     Player vs Player (Enter number 2)";

    do
    {
        std::cout << "\n     ";
        std::cin >> PlayerMode;

        if (PlayerMode == 1)
        {
            PlayerVsAi(MatchesLeft, IsPlayerOnesTurn);
            return 0;
        }
        if (PlayerMode == 2)
        {
            PlayerVsPlayer(MatchesLeft, IsPlayerOnesTurn);
            return 0;
        }
        else
        {
            std::cout << "\n     Not a valid choice (choose 1 or 2)";
        }

        std::cin.clear();
        std::cin.ignore();
    }     while (true);
        
    return 0;
}