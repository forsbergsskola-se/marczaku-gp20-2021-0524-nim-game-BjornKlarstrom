#include <iostream>

bool IsValid(int Input)
{
    return Input >= 0 && Input < 9;
}

bool IsPlaceable (int PlayerOne[], int PlayerTwo[], int Input)
{
    return PlayerOne[Input] == 0 && PlayerTwo[Input] == 0 && IsValid(Input);
}

void HandleInputOne(int* PlayerOne, int* PlayerTwo)
{
    while (true) 
    {
        int Input;
        std::cin >> Input;

        if (IsPlaceable(PlayerOne, PlayerTwo, Input))
        {
            PlayerOne[Input] = 1;
            break;
        }

        std::cout << "\nTry again.. (0 - 8)";
    }
}

void HandleInputTwo(int* PlayerOne, int* PlayerTwo)
{
    while (true)
    {
        int Input;
        std::cin >> Input;

        if (IsPlaceable(PlayerOne, PlayerTwo, Input))
        {
            PlayerTwo[Input] = 2;
            break;
        }

        std::cout << "\nTry again.. (0 - 8)";
    }
}

bool ShowPlayerOne(int* PlayerOne, int index)
{
    return PlayerOne[index] > 0;
}

bool ShowPlayerTwo(int* PlayerTwo, int index)
{
    return PlayerTwo[index] > 0;
}

void ShowGrid(int* PlayerOne, int* PlayerTwo)
{
    const int GridSize = 9;

    for (int i = 0; i < GridSize; i++)
    {
        if (ShowPlayerOne(PlayerOne, i))
        {
            std::cout << " " << "x" << " ";
        }

        else if (ShowPlayerTwo(PlayerTwo, i))
        {
            std::cout << " " << "o" << " ";
        }

        else
            std::cout << " " << i << " ";

        if (i == 2 || i == 5 || i == 8)
        {
            std::cout << "" << std::endl;
            continue;
        }

        std::cout << "|";
    }
}

bool IsTopRow(int* Player) {
    return Player[0] > 0 && Player[1] > 0 && Player[2] > 0;
}

bool IsMiddleRow(int* Player) {
    return Player[3] > 0 && Player[4] > 0 && Player[5] > 0;
}

bool IsBottomRow(int* Player) {
    return Player[6] > 0 && Player[7] > 0 && Player[8] > 0;
}

bool IsLeftColumn(int* Player) {
    return Player[0] > 0 && Player[3] > 0 && Player[6] > 0;
}

bool IsMiddleColumn(int* Player) {
    return Player[1] > 0 && Player[4] > 0 && Player[7] > 0;
}

bool IsRightColumn(int* Player) {
    return Player[2] > 0 && Player[5] > 0 && Player[8] > 0;
}

bool IsDiagonalLeft(int* Player) {
    return Player[0] > 0 && Player[4] > 0 && Player[8] > 0;
}

bool IsDiagonalRight(int* Player) {
    return Player[2] > 0 && Player[4] > 0 && Player[6] > 0;
}

bool IsHorizontalRow(int* Player)
{
    return IsTopRow(Player) || IsMiddleRow(Player) || IsBottomRow(Player);
}

bool IsVerticalRow(int* Player)
{
    return IsLeftColumn(Player) || IsMiddleColumn(Player) || IsRightColumn(Player);
}

bool IsDiagonal(int* Player)
{
    return IsDiagonalLeft(Player) || IsDiagonalRight(Player);
}

bool IsWinner(int* Player)
{
    return IsHorizontalRow(Player) || IsVerticalRow(Player) || IsDiagonal(Player);
}


int main()
{
    int PlayerOne[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int PlayerTwo[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    ShowGrid(PlayerOne, PlayerTwo);

    while (true)
    {
        std::cout << "\nPlayer One! Place your pick (0 - 8)";
        HandleInputOne(PlayerOne, PlayerTwo);
        ShowGrid(PlayerOne, PlayerTwo);
        if (IsWinner(PlayerOne)) 
        {
            std::cout << "\nPlayer One Won!";
            break;
        }

        std::cout << "\nPlayer Two! Place your pick (0 - 8)";
        HandleInputTwo(PlayerOne, PlayerTwo);
        ShowGrid(PlayerOne, PlayerTwo);
        if (IsWinner(PlayerTwo))
        {
            std::cout << "\nPlayer Two Won!";
            break;
        }       
    }

    std::cout << std::endl << std::endl;
    return 0;
}