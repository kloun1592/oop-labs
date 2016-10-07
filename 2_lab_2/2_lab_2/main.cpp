#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string HTMLEncode(string const& uncodedFileString)
{
    string buffer;
    buffer = uncodedFileString.size() * 1.1;
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
    return buffer;
}

int main(int argc, const char * argv[])
{
    string uncodedFileString;
    string codedString;
    
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
    };
    return 0;
}
