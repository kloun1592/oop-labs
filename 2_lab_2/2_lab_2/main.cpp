#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string HTMLEncode(string & codedString)
{
    string encodeString = "";
    for (char& letter : codedString)
    {
        switch (letter)
        {
            case '&':  encodeString += " &amp; ";  break;
            case '\"': encodeString += " &quot; "; break;
            case '\'': encodeString += " &apos; "; break;
            case '<':  encodeString += " &lt; ";   break;
            case '>':  encodeString += " &gt; ";   break;
            default:   encodeString += letter;     break;
        }
    }
    return encodeString;
}

int main(int argc, const char * argv[])
{
    string codedString = "";
    
    while(true)
    {
        cin >> codedString;
        cout << HTMLEncode(codedString);
    }

    return 0;
}
