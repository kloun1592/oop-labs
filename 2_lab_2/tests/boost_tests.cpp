#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_NO_MAIN
#include <boost/test/unit_test.hpp>
#include "../2_lab_2/main.cpp"

BOOST_AUTO_TEST_CASE(str_without_html_symbols)
{
    string testStr = "test",
           correctStr = "test";
    BOOST_CHECK(HTMLEncode(testStr) == "test");
}

BOOST_AUTO_TEST_CASE(str_with_html_symbols)
{
    string testStr = "Cat <says> \"Meow\". M&M's",
           correctStr = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
    BOOST_CHECK(HTMLEncode(testStr) == correctStr);
}

BOOST_AUTO_TEST_CASE(empty_str)
{
    string testStr = "",
           correctStr = "";
    BOOST_CHECK(HTMLEncode(testStr) == correctStr);
}
