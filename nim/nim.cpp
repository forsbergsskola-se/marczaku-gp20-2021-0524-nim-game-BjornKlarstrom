#include <iostream>
#include <ctime>

int GetPlayerChoice()
{
    int Choice;
    
    do
    {
        std::cout << "\n     How many matches do you want to draw? (max 3): ";
        std::cin >> Choice;

        if (Choice >= 1 && Choice <= 3)
        {
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

    std::cout << "\n     Ai draws " << AiChoice << " matches";

    return AiChoice;
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


    std::cout << "\n     ";
    for (int i = 0; i < MatchesLeft; i++)
    {
        std::cout << "| ";
    }

    while (MatchesLeft > 0)
    {
        IsPlayerOnesTurn = !IsPlayerOnesTurn;
        MatchesLeft -= IsPlayerOnesTurn ? GetPlayerChoice() : GetAiChoice();

        std::cout << MatchesLeft;
    }

    std::cout << "\n\n";
    return 0;
}
