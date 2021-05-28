#include <iostream>

void DecimalToBinary(int UserNumber)
{
     const int NumberOfBits = 32;
     int binaryNum[NumberOfBits];

     std::cout << NumberOfBits;

     unsigned i = 0;
     while (UserNumber > 0)
     {
         binaryNum[i] = UserNumber % 2;
         UserNumber = UserNumber / 2;
           i++;
        }
     for (; i < NumberOfBits; i++)
     {
            binaryNum[i] = 0;
     }

     std::cout << "0b";
     for (int j = NumberOfBits - 1; j >= 0; j--)
          std::cout << binaryNum[j];
}

int main()
{
    std::cout << "Hello Binary Converter\n\n";


    /*int i = 0, j = 0;

    if (++i || ++j)
    {
        std::cout << "YES" << std::endl;
    }

    std::cout << i << " " << j;



    std::cout << "\n\n";
    return 0;*/



    int UserNumber;
    std::cout << "\n\nInput a number (positive): ";
    std::cin >> UserNumber;
    std::cin.clear();
    std::cin.ignore();

    DecimalToBinary(UserNumber);


    std::cout << std::endl << std::endl;
    return 0;
}