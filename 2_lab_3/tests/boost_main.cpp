#define BOOST_TEST_NO_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../2_lab_3/main.cpp"

BOOST_AUTO_TEST_CASE(try_enter_test_word)
{
    BOOST_CHECK(EnterWord() == "test");
}

BOOST_AUTO_TEST_CASE(create_dictionary)
{
    ifstream dictionaryFile("dictionary.txt");
    int dictionarySize = 4;
    map <string, string> dictionary;
    CreateDictionary(dictionary, dictionaryFile);
    BOOST_CHECK(dictionary.size() == dictionarySize);
}

BOOST_AUTO_TEST_CASE(find_word_in_dictionary)
{
    string word = "cat";
    map <string, string> dictionary, newWordsdictionary = {{"cat", "кошка"}};
    BOOST_CHECK(FindWordInDictionary(word, dictionary, newWordsdictionary) == "кошка");
}

BOOST_AUTO_TEST_CASE(add_word_in_temp_dictionary)
{
    string word = "car";
    string translate = "машина";
    map <string, string> dictionary;
    int dictionarySize = 1;
    dictionary = AddWordInDictionary(word, translate, dictionary);
    BOOST_CHECK(dictionary.size() == dictionarySize);
}
