#define BOOST_TEST_NO_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../3_lab_1/main.cpp"

BOOST_AUTO_TEST_CASE(try_enter_test_word)
{
    BOOST_CHECK(EnterWord() == "test");
}
