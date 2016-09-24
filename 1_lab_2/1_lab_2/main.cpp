#include <iostream>
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <boost/test/output/compiler_log_formatter.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;

void PrintBinaryNumber(int number)
{
    if (number / 2 != 0)
    {
        PrintBinaryNumber(number / 2);
    }
    cout << number % 2;
}



class SpecLogFormatter : public boost::unit_test::output::compiler_log_formatter
{
public:
    SpecLogFormatter() : m_indent(0) {}
private:
    void test_unit_start(std::ostream &os,
                         boost::unit_test::test_unit const& tu)
    {
        os << std::string(m_indent, ' ') <<
        boost::replace_all_copy(tu.p_name.get(), "_", " ") << std::endl;
        m_indent += 2;
    }
    void test_unit_finish(std::ostream &os,
                          boost::unit_test::test_unit const& tu, unsigned long elapsed)
    {
        (void)&elapsed;
        (void)&tu;
        (void)&os;
        m_indent -= 2;
    }
    int m_indent;
};


bool init_unit_test_suite()
{
    boost::unit_test::unit_test_log.set_formatter(new SpecLogFormatter);
    boost::unit_test::framework::master_test_suite().p_name.value = "All tests";
    return true;
}


int main(int argc, char * argv[])
{
    int testResult = boost::unit_test::unit_test_main(&init_unit_test_suite, argc, argv);
    if (testResult != 0)
    {
        // тесты завершились с ошибкой
    }
    if (argc != 2)
    {
        cout << "Invalid arguments count\n"
        << "Usage: copyfile.exe <input file> <output file>\n";
        return 1;
    }
    PrintBinaryNumber(atoi(argv[1]));
    cout << endl;
    return 0;
}
