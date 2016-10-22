#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

string FindWordInDictionary(string const& word, map <string, string> dictionary, map <string, string> newWordsdictionary)
{
    
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

map <string, string> AddWordInDictionary(string const& word, string const& translate, map <string, string> dictionary)
{
    dictionary.insert(pair<string,string>(word, translate));
    return dictionary;
}

void SaveDictionaryChanges(const map <string, string> dictionary, ofstream & dictionaryFile)
{
    for (auto it = dictionary.begin(); it != dictionary.end(); it++)
    {
        dictionaryFile << endl << it->first << "," << it->second;
    }
}

string EnterWord()
{
    string word;
    cout << "Введите слово: ";
    getline(cin, word);
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}

bool CheckForExitDictionary(string const& word, map <string, string> & newWordsdictionary, ofstream & dictionaryFile)
{
    string saveChangesStatus = "";
    if (word == "...")
    {
        if (newWordsdictionary.size() > 0)
        {
            cout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом." << endl;
            cin >> saveChangesStatus;
            if (saveChangesStatus == "Y" || saveChangesStatus == "y")
            {
                SaveDictionaryChanges(newWordsdictionary, dictionaryFile);
                cout << "Изменения были сохранены. До свидания." << endl;
                return true;
            }
            else
            {
                cout << "Изменения НЕ были сохранены. До свидания." << endl;
                return true;
            }
        }
        else
        {
            cout << "Изменения не были внесены. До свидания." << endl;
            return true;
        }
    }
    return false;
}

void TreatmentWordByDictionary(string const& word, map <string, string> & newWordsdictionary, map <string, string> dictionary)
{
    string foundWord;
    foundWord = FindWordInDictionary(word, dictionary, newWordsdictionary);
    
    string translate;
    if (foundWord != "")
    {
        cout << foundWord << endl;
    }
    else
    {
        cout << "Неизвестное слово '" << word << "'. Введите перевод или пустую строку для отказа." << endl;
        getline(cin, translate);
        if (translate == "")
        {
            cout << "Слово '" << word << "' было проигнорировано." << endl;
        }
        else
        {
            newWordsdictionary = AddWordInDictionary(word, translate, newWordsdictionary);
            cout << "Слово '" << word << "' сохранено в словаре как '" << translate << "'." << endl;
        }
    }
}

void CreateDictionary(map <string, string> & dictionary, ifstream & dictionaryFile)
{
    string originalWord, translate;
    
    while (getline(dictionaryFile, originalWord, ',') &&
           getline(dictionaryFile, translate, '\n'))
    {
        dictionary[originalWord] = translate;
    }
    
}

int main2(int argc, const char * argv[])
{
    string word, foundWord;
    map <string, string> dictionary, newWordsdictionary;
    
    ifstream dictionaryFile(argv[1]);
    CreateDictionary(dictionary, dictionaryFile);
    
    while (true)
    {
        word = EnterWord();
        ofstream dictionaryFile(argv[1], ofstream::app);
        if (CheckForExitDictionary(word, newWordsdictionary, dictionaryFile))
        {
            break;
        }
        else
        {
            TreatmentWordByDictionary(word, newWordsdictionary, dictionary);
        }
    };
    return 0;
}
