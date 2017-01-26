#include "stdafx.h"
#include "../7_lab_2/Stack.h"
#include <stack>

using boost::test_tools::output_test_stream;

void PrintStack(std::ostream & output, const CMyStack<std::string> & stack)
{
	for (int i = stack.GetTop() - 1; i >= 0; i--)
	{
		output << stack.GetPtr()[i] << std::endl;
	}
}

BOOST_AUTO_TEST_SUITE(Stack)
	BOOST_AUTO_TEST_CASE(has_correct_parametrs_after_creating)
	{
		CMyStack<std::string> stack(2);
		BOOST_CHECK_EQUAL(stack.GetStackSize(), 2);
		BOOST_CHECK_EQUAL(stack.GetTop(), 0);
	}

	BOOST_AUTO_TEST_CASE(has_correct_value_and_parametrs_after_push)
	{
		CMyStack<std::string> stack(2);
		stack.Push("str");
		BOOST_CHECK_EQUAL(stack.GetTopElement(), "str");
		BOOST_CHECK_EQUAL(stack.GetStackSize(), 2);
		BOOST_CHECK_EQUAL(stack.GetTop(), 1);
	}

	BOOST_AUTO_TEST_CASE(has_correct_value_and_parametrs_after_pop)
	{
		CMyStack<std::string> stack(2);
		stack.Push("str");
		stack.Push("str2");
		stack.Pop();
		BOOST_CHECK_EQUAL(stack.GetTopElement(), "str");
		BOOST_CHECK_EQUAL(stack.GetStackSize(), 2);
		BOOST_CHECK_EQUAL(stack.GetTop(), 1);
	}

	BOOST_AUTO_TEST_CASE(has_not_got_any_values)
	{
		CMyStack<std::string> stack(1);
		BOOST_CHECK_EQUAL(stack.IsEmpty(), true);
		stack.Push("str");
		BOOST_CHECK_EQUAL(stack.IsEmpty(), false);
	}

	BOOST_AUTO_TEST_CASE(has_not_got_any_values_after_clear)
	{
		CMyStack<std::string> stack(2);
		stack.Push("str");
		stack.Push("str2");
		stack.Clear();
		BOOST_CHECK_THROW(stack.GetTopElement(), std::bad_alloc);
		BOOST_CHECK_EQUAL(stack.GetStackSize(), 2);
		BOOST_CHECK_EQUAL(stack.GetTop(), 0);
	}

	BOOST_AUTO_TEST_CASE(has_correct_values_after_printing)
	{
		CMyStack<std::string> stack(2);
		stack.Push("str");
		output_test_stream output("out.txt", true);
		PrintStack(output, stack);
		BOOST_CHECK(output.match_pattern());
	}

	BOOST_AUTO_TEST_CASE(has_correct_values_after_replace_operator)
	{
		CMyStack<std::string> stack(2);
		stack.Push("str");
		CMyStack<std::string> stack2(2);
		stack2 = move(stack);
		output_test_stream output("out.txt", true);
		PrintStack(output, stack2);
		BOOST_CHECK(output.match_pattern());
	}

	BOOST_AUTO_TEST_CASE(has_correct_values_after_replace_constructor)
	{
		CMyStack<std::string> stack(2);
		stack.Push("str");
		CMyStack<std::string> stack2(move(stack));
		output_test_stream output("out.txt", true);
		PrintStack(output, stack2);
		BOOST_CHECK(output.match_pattern());
	}

	BOOST_AUTO_TEST_CASE(has_correct_values_after_copying_operator)
	{
		CMyStack<std::string> stack(2);
		stack.Push("str");
		CMyStack<std::string> stack2(2);
		stack2 = stack;
		output_test_stream output("out.txt", true);
		PrintStack(output, stack2);
		BOOST_CHECK(output.match_pattern());
	}

	BOOST_AUTO_TEST_CASE(has_correct_values_after_copying_constructor)
	{
		CMyStack<std::string> stack(2);
		stack.Push("str");
		CMyStack<std::string> stack2(stack);
		output_test_stream output("out.txt", true);
		PrintStack(output, stack2);
		BOOST_CHECK(output.match_pattern());
	}
BOOST_AUTO_TEST_SUITE_END()
