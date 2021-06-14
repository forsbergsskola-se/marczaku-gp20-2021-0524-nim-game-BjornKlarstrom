#include <iostream>
#include <ctime>
#include "nim.h"
using namespace std;

int GetPlayerChoice()
{
    int Choice;
    
    do
    {
        cout << "\n     How many matches do you want to draw? (max 3): ";
        cin >> Choice;

        if (Choice >= 1 && Choice <= 3)
        {
            cout << "\n     You draw " << Choice << " matches";
            return Choice;
        }
        else 
        {
            cout << "\n     Try again.. Input not correct";
        }
        cin.clear();
        cin.ignore();
    }     
    while (true);
}

int GetAiChoice()
{
    int AiChoice = rand() % 3 + 1;

    cout << "\n\n     Ai draws " << AiChoice << " matches";

    return AiChoice;
}


void ShowMatchesLeft(int MatchesLeft)
{
    cout << "\n     ";
    for (int i = 0; i < MatchesLeft; i++)
    {
        cout << "| ";
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
    cout << (IsPlayerOnesTurn ? "\n\n     To bad.. Ai won the game :(" :
        "\n\n     Concratulations! you won the game!");

    cout << "\n\n";
}

void PlayerVsPlayer(int& MatchesLeft, bool& IsPlayerOnesTurn)
{
    ShowMatchesLeft(MatchesLeft);

    while (MatchesLeft > 0)
    {
        IsPlayerOnesTurn = !IsPlayerOnesTurn;

        cout << (IsPlayerOnesTurn ? "\n     Player One. How many matches do you want to draw? (max 3)" :
                                         "\n     Player Two. How many matches do you want to draw? (max 3)");

        MatchesLeft -= GetPlayerChoice();

        ShowMatchesLeft(MatchesLeft);
    }

    cout << (IsPlayerOnesTurn ? "\n\n     Player One " : "\n\n     Player Two ") << "WON!!!";
    cout << "\n\n";
}

int main()
{
    const int MatchesToStartWith = 24;
    int MatchesLeft = MatchesToStartWith;
    srand(time(NULL));
    bool IsPlayerOnesTurn = rand() % 2;
    int PlayerMode;
   

    cout << "\n               -----------------------------\n";
    cout << "                        WELCOME TO\n";
    cout << "                      THE N.I.M GAME!";
    cout << "\n               -----------------------------\n";
    cout << "\n     A game about picking matches and avoiding the last one";
    cout << "\n     Picking the last one will result in death\n\n";


    cout << "\n     How whould you like to play?";
    cout << "\n     Player vs Ai (Enter number 1)";
    cout << "\n     Player vs Player (Enter number 2)";

    do
    {
        cout << "\n     ";
        cin >> PlayerMode;

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

        cin.clear();
        cin.ignore();
    }   
    while (true);
        
    return 0;
}