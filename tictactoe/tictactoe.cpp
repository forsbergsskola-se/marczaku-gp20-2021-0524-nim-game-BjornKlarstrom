#include <iostream>

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
        if (ShowPlayerTwo(PlayerTwo, i))
        {
            std::cout << " " << "o" << " ";
        }
        else
            std::cout << " " << "i" << " ";

        if (i == 2 || i == 5 || i == 8)
        {
            std::cout << "" << std::endl;
            continue;
        }

        std::cout << "|";
    }
}

int main()
{
    int PlayerOne[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int PlayerTwo[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    ShowGrid(PlayerOne, PlayerTwo);
}