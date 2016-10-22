#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string HTMLEncode(string const & codedString)
{
    string encodeString = "";
    for (char letter : codedString)
    {
        switch (letter)
        {
            case '&':  encodeString.append("&amp;");    break;
            case '\"': encodeString.append("&quot;");   break;
            case '\'': encodeString.append("&apos;");   break;
            case '<':  encodeString.append("&lt;");     break;
            case '>':  encodeString.append("&gt;");     break;
            default:   encodeString.append(&letter, 1); break;
        }
    }
    return encodeString;
}

int main2(int argc, const char * argv[])
{
    string codedString = "";
    
    while(true)
    {
        cin >> codedString;
        cout << HTMLEncode(codedString);
    }
    
    return 0;
}
