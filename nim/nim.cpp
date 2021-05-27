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

int main()
{
    const int MatchesToStartWith = 24;
    int MatchesLeft = MatchesToStartWith;
    srand(time(NULL));
    bool IsPlayerOnesTurn = rand() % 2;
   

    std::cout << "\n               -----------------------------\n";
    std::cout << "                        WELCOME TO\n";
    std::cout << "                      THE N.I.M GAME!";
    std::cout << "\n               -----------------------------\n";
    std::cout << "\n     A game about picking matches and avoiding the last one";
    std::cout << "\n     Picking the last one will result in death\n\n";


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
    return 0;
}
