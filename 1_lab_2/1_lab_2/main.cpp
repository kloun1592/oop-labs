#include <iostream>

using namespace std;

void PrintBinaryNumber(int number)
{
    if (number / 2 != 0)
    {
        PrintBinaryNumber(number / 2);
    }
    cout << number % 2;
}

int main(int argc, char * argv[])
{
    if (argc != 2)
    {
        cout << "Invalid arguments count\n"
        << "Usage: copyfile.exe <input file> <output file>\n";
        return 1;
    }
    PrintBinaryNumber(atoi(argv[1]));
    cout << endl;
    return 0;
}
