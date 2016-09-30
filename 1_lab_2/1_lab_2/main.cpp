#include <iostream>

using namespace std;

string convertDec2Bin(const int decNumber)
{
    string binNum = "";
    const int binNumLength = 8;
    for (int i = binNumLength; i >= 0; i--)
    {
        if ((1 << i) & decNumber)
        {
            binNum = binNum + "1";
        }
        else
        {
            binNum = binNum + "0";
        }
    }
    return binNum;
}

bool isIntNumber(const char *number)
{
    while (*number)
    {
        if (!isdigit(*number++))
        {
            return false;
        }
    }
    return true;
}

bool isArgumentsExist(int argc, const int argumentsQuantity)
{
    if (argc != argumentsQuantity)
    {
        cout << "Invalid arguments count" << endl
        << "Usage: copyfile.exe <input file> <output file>" << endl;
        return false;
    };
    return true;
}

int main(int argc, char * argv[])
{
    if(isArgumentsExist(argc, 2))
    {
        if(isIntNumber(argv[1]))
        {
            cout << convertDec2Bin(atoi(argv[1])) << endl;
            return 0;
        }
        else
        {
            cout << "\"" << argv[1] << "\" is incorrect input data" << endl;
            return 1;
        }
    }
    else
    {
        return 1;
    }
}
