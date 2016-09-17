#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char * argv[])
{
    if (argc != 3)
    {
        cout << "Invalid arguments count\n"
        << "Usage: copyfile.exe <input file> <output file>\n";
        return 1;
    }
    
    ifstream firstFile(argv[1]);
    
    if (!firstFile.is_open())
    {
        cout << "Failed to open " << argv[1] << " for reading\n";
        return 1;
    }
    
    ifstream secondFile(argv[2]);
    
    if (!secondFile.is_open())
    {
        cout << "Failed to open " << argv[2] << " for reading\n";
        return 1;
    }
    
    char string1[256], string2[256];
    int j = 0;
    
    while(!firstFile.eof())
    {
        firstFile.getline(string1,256);
        secondFile.getline(string2,256);
        j++;
        if(strcmp(string1,string2) != 0)
        {
            cout << "Files are different. Line number is " << j << endl;
            return 1;
        }
    };
    cout << "Files are equal" << endl;
    return 0;
}
