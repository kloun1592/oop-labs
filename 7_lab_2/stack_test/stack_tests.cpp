#include "stdafx.h"
#include "../7_lab_2/Stack.h"

BOOST_AUTO_TEST_SUITE(Stack)
	BOOST_AUTO_TEST_CASE(has_correct_parametrs_after_creating)
	{
		MyStack<std::string> stack(2);
		BOOST_CHECK_EQUAL(stack.GetSize(), 2);
		BOOST_CHECK_EQUAL(stack.GetTop(), 0);
	}

	BOOST_AUTO_TEST_CASE(has_correct_value_and_parametrs_after_push)
	{
		MyStack<std::string> stack(2);
		stack.Push("str");
		BOOST_CHECK_EQUAL(stack.GetTopElement(), "str");
		BOOST_CHECK_EQUAL(stack.GetSize(), 2);
		BOOST_CHECK_EQUAL(stack.GetTop(), 1);
	}

	BOOST_AUTO_TEST_CASE(has_correct_value_and_parametrs_after_pop)
	{
		MyStack<std::string> stack(2);
		stack.Push("str");
		stack.Push("str2");
		stack.Pop();
		BOOST_CHECK_EQUAL(stack.GetTopElement(), "str");
		BOOST_CHECK_EQUAL(stack.GetSize(), 2);
		BOOST_CHECK_EQUAL(stack.GetTop(), 1);
	}

	BOOST_AUTO_TEST_CASE(has_not_got_any_values)
	{
		MyStack<std::string> stack(2);
		stack.Push("str");
		stack.Push("str2");
		stack.Clear();
		BOOST_CHECK_EQUAL(stack.GetTopElement(), "");
		BOOST_CHECK_EQUAL(stack.GetSize(), 2);
		BOOST_CHECK_EQUAL(stack.GetTop(), 0);
	}
BOOST_AUTO_TEST_SUITE_END()