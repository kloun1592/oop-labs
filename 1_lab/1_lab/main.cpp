#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Returns line number where difference was found or 0 if the content is equal

bool CompareContent(istream & firstFile, istream & secondFile)
{
    string string1;
    string string2;
    int j = 0;
    
    while(getline(firstFile, string1) && getline(secondFile, string2))
    {
        j++;
        if(string1 != string2)
        {
            cout << "Files are different. Line number is " << j << endl;
            return 1;
        }
    };
    cout << "Files are equal" << endl;
    
    return 0;
}

int main(int argc, char * argv[])
{
    if (argc != 3)
    {
        cout << "Invalid arguments count" << endl
        << "Usage: copyfile.exe <input file> <output file>" << endl;
        return 1;
    }
    
    ifstream firstFile(argv[1]);
    
    if (!firstFile.is_open())
    {
        cout << "Failed to open " << argv[1] << " for reading" << endl;
        return 1;
    }
    
    ifstream secondFile(argv[2]);
    
    if (!secondFile.is_open())
    {
        cout << "Failed to open " << argv[2] << " for reading" << endl;
        return 1;
    }
    
    return CompareContent(firstFile, secondFile);
}
