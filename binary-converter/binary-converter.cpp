#include <iostream>
#include <string>
using namespace std;

string DecimalToBinaryString(int userNumber)
{
    const int numberOfBits = 32;
    string binaryString;
    
    for (int i = 0; i < numberOfBits; i++)
    {
        if (userNumber % 2 == 0)
        {
            binaryString.append("0");
        }
        else
        {
            binaryString.append("1");
        }

       userNumber = userNumber / 2;
    }

    string reversed = string(binaryString.rbegin(), binaryString.rend());
    reversed.insert(0, "0b");
    return reversed;
}

string GetWithBinaryOperator(int userNumber)
{
    const int numberOfBits = 32;
    string binaryString;

    for (int i = numberOfBits - 1; i >= 0; i--) 
    {
        int b = userNumber >> i;
        if (b & 1)
        {
            binaryString.append("1");
        }
        else
        {
            binaryString.append("0");
        }
    }
    binaryString.insert(0, "0b");
    return binaryString;
}

int main()
{
    cout << "Hello Binary Converter\n\n";

    int UserNumber;
    cout << "\n\nInput a number (positive): ";
    cin >> UserNumber;
    cin.clear();
    cin.ignore();

    string binary1 = DecimalToBinaryString(UserNumber);
    cout << binary1;
    cout << endl << endl;

    string binary2 = GetWithBinaryOperator(UserNumber);
    cout << binary2;
    cout << endl << endl;

    cout << endl << endl;
    return 0;
}