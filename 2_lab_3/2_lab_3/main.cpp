#include <iostream>
#include <fstream>
#include <map>


using namespace std;

void printDictionary(map <string, string> const& dictonary)
{
    for (auto it = dictonary.begin(); it != dictonary.end(); it++)
    {
        cout << it->first << " : " << it->second << endl;
    }
}

string findWordInDictionary(string const& word, istream & dicitonaryFile, map <string, string> dictionary, map <string, string> newWordsdictionary)
{
    string originalWord = "";
    string translate = "";
    
    while (dicitonaryFile >> originalWord && dicitonaryFile >> translate)
    {
        dictionary[originalWord] = translate;
    };
    
    for (auto it = dictionary.begin(); it != dictionary.end(); it++)
    {
        if (it->first == word)
        {
            return it->second;
        }
    }
    
    for (auto it = newWordsdictionary.begin(); it != newWordsdictionary.end(); it++)
    {
        if (it->first == word)
        {
            return it->second;
        }
    }
    
    return "";
}

void addWordInDictionary(string const& engWord, string const& translate, map <string, string> *dictionary)
{
    dictionary->insert(pair<string,string>(engWord, translate));
}

void saveDictionaryChanges(const map <string, string> dictionary, ofstream & dictionaryFile)
{
    for (auto it = dictionary.begin(); it != dictionary.end(); it++)
    {
        dictionaryFile << endl << it->first << " " << it->second;
    }
}

string enterWord()
{
    string engWord = "";
    cout << "Введите слово: ";
    cin >> engWord;
    transform(engWord.begin(), engWord.end(), engWord.begin(), ::tolower);
    return engWord;
}

int main(int argc, const char * argv[])
{
    string word;
    string translate;
    string findableWord;
    string saveChangesStatus;
    map <string, string> dictionary;
    map <string, string> newWordsdictionary;
    
    while (true)
    {
        word = enterWord();
        if (word == "...")
        {
            if(newWordsdictionary.size() > 0)
            {
                cout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом." << endl;
                cin >> saveChangesStatus;
                if (saveChangesStatus == "Y" || saveChangesStatus == "y")
                {
                    ofstream dictionaryFile(argv[1], ofstream::app);
                    saveDictionaryChanges(newWordsdictionary, dictionaryFile);
                    cout << "Изменения были сохранены. До свидания." << endl;
                    break;
                }
                else
                {
                    cout << "Изменения НЕ были сохранены. До свидания." << endl;
                    break;
                }
            }
            else
            {
                cout << "Изменения не были внесены. До свидания." << endl;
                break;
            }
        }
        
        ifstream dictionaryFile(argv[1]);
        if (!dictionaryFile.is_open())
        {
            cout << "Не получается открыть словарь '" << argv[1] << "'" << endl;
            return 1;
        }
        findableWord = findWordInDictionary(word, dictionaryFile, dictionary, newWordsdictionary);
        
        if (findableWord != "")
        {
            cout << findableWord << endl;
        }
        else
        {
            cout << "Неизвестное слово '" << word << "'. Введите перевод или пустую строку для отказа." << endl;
            cin >> translate;
            if (translate == "")
            {
                cout << "Слово '" << word << "' было проигнорировано.";
            }
            else
            {
                addWordInDictionary(word, translate, &newWordsdictionary);
                cout << "Слово '" << word << "' сохранено в словаре как '" << translate << "'." << endl;
                continue;
            }
        }
    };
    return 0;
}
