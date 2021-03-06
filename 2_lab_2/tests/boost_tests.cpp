#define BOOST_TEST_NO_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../2_lab_2/main.cpp"

BOOST_AUTO_TEST_CASE(str_without_html_symbols)
{
    BOOST_CHECK_EQUAL(HTMLEncode("test"), "test");
}

BOOST_AUTO_TEST_CASE(str_with_html_symbols)
{
    string testStr = "Cat <says> \"Meow\". M&M's",
           correctStr = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
    BOOST_CHECK_EQUAL(HTMLEncode(testStr),
                      correctStr);
}

BOOST_AUTO_TEST_CASE(empty_str)
{
    string testStr = "",
           correctStr = "";
    BOOST_CHECK(HTMLEncode(testStr) == correctStr);
}
