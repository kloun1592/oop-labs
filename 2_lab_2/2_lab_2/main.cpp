#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string HTMLEncode(string & uncodedFileString)
{
    string buffer = "";
    buffer.reserve(uncodedFileString.size());
    for (size_t pos = 0; pos != uncodedFileString.size(); ++pos)
    {
        switch (uncodedFileString[pos])
        {
            case '&':  buffer.append("&amp;");       break;
            case '\"': buffer.append("&quot;");      break;
            case '\'': buffer.append("&apos;");      break;
            case '<':  buffer.append("&lt;");        break;
            case '>':  buffer.append("&gt;");        break;
            default:   buffer.append(&uncodedFileString[pos], 1); break;
        }
    }
    uncodedFileString.swap(buffer);
    return uncodedFileString;
}

int main2(int argc, const char * argv[])
{
    string uncodedFileString = codedString = "";
    
    ifstream uncodedFile(argv[1]);
    if (!uncodedFile.is_open())
    {
        cout << "Cannot open file." << endl;
        return false;
    }
    
    while(getline(uncodedFile, uncodedFileString))
    {
        codedString = HTMLEncode(uncodedFileString);
        cout << codedString << endl;
    }

    return 0;
}
