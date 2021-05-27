#include <iostream>
#include <ctime>

int GetPlayerChoice()
{
    return 1;
}

int GetAiChoice()
{
    return 2;
}


int main()
{
    const int MatchesToStartWith = 24;
    int MatchesLeft = MatchesToStartWith;
    bool IsPlayerOnesTurn = rand() % 2;
    srand(time(NULL));

    std::cout << "\n               -----------------------------\n";
    std::cout << "                        WELCOME TO\n";
    std::cout << "                      THE N.I.M GAME!";
    std::cout << "\n               -----------------------------\n";
    std::cout << "\n     A game about picking matches and avoiding the last one";
    std::cout << "\n     Picking the last one will result in death\n\n";


    std::cout << "\n     ";
    for (int i = 0; i < MatchesLeft; i++)
    {
        std::cout << "|";
    }

    while (MatchesLeft > 0)
    {
        IsPlayerOnesTurn = !IsPlayerOnesTurn;
        MatchesLeft -= IsPlayerOnesTurn ? GetPlayerChoice() : GetAiChoice();
    }

    std::cout << "\n\n";
    return 0;
}
