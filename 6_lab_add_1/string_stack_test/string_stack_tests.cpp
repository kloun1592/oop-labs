#include "stdafx.h"
#include "../6_lab_add_1/StringStack.h"

using boost::test_tools::output_test_stream;

BOOST_AUTO_TEST_SUITE(Stack)
BOOST_AUTO_TEST_CASE(has_correct_parametrs_after_creating)
{
	CStringStack stack;
	BOOST_CHECK_EQUAL(stack.GetStackSize(), 0);
}

BOOST_AUTO_TEST_CASE(has_correct_value_and_parametrs_after_push)
{
	CStringStack stack;
	stack.Push("str");
	BOOST_CHECK_EQUAL(stack.GetTopElement(), "str");
	BOOST_CHECK_EQUAL(stack.GetStackSize(), 1);
}

BOOST_AUTO_TEST_CASE(has_correct_value_and_parametrs_after_pop)
{
	CStringStack stack;
	stack.Push("str");
	stack.Push("str2");
	stack.Pop();
	BOOST_CHECK_EQUAL(stack.GetTopElement(), "str");
	BOOST_CHECK_EQUAL(stack.GetStackSize(), 1);
}

BOOST_AUTO_TEST_CASE(has_not_got_any_values)
{
	CStringStack stack;
	BOOST_CHECK(stack.IsEmpty() == true);
	stack.Push("str");
	BOOST_CHECK(stack.IsEmpty() == false);
}

BOOST_AUTO_TEST_CASE(has_not_got_any_values_after_clear)
{
	CStringStack stack;
	stack.Push("str");
	stack.Push("str2");
	stack.Clear();
	BOOST_CHECK_EQUAL(stack.GetStackSize(), 0);
}

BOOST_AUTO_TEST_CASE(throw_exception_after_pop_when_stack_is_empty)
{
	CStringStack stack;
	BOOST_CHECK_THROW(stack.Pop(), std::logic_error);
}

BOOST_AUTO_TEST_CASE(throw_exception_after_get_top_element_when_stack_is_empty)
{
	CStringStack stack;
	BOOST_CHECK_THROW(stack.GetTopElement(), std::logic_error);
}

BOOST_AUTO_TEST_CASE(has_correct_values_after_replace_operator)
{
	/*CStringStack stack;
	stack.Push("0");
	stack.Push("1");
	stack.Push("2");
	auto clone = std::move(stack);
	BOOST_CHECK_EQUAL(stack.GetStackSize(), 3);
	BOOST_CHECK_EQUAL(stack.GetTopElement(), "2");
	stack.Pop();
	BOOST_CHECK_EQUAL(stack.GetTopElement(), "1");
	stack.Pop();
	BOOST_CHECK_EQUAL(stack.GetTopElement(), "0");
	stack.Pop();*/
}

BOOST_AUTO_TEST_CASE(has_correct_values_after_copying_operator)
{
	CStringStack stack;
	stack.Push("0");
	stack.Push("1");
	stack.Push("2");
	auto clone = stack;
	BOOST_CHECK_EQUAL(stack.GetStackSize(), 3);
	BOOST_CHECK_EQUAL(stack.GetTopElement(), "2");
	stack.Pop();
	BOOST_CHECK_EQUAL(stack.GetTopElement(), "1");
	stack.Pop();
	BOOST_CHECK_EQUAL(stack.GetTopElement(), "0");
	stack.Pop();
}

BOOST_AUTO_TEST_CASE(has_correct_values_after_copying_constructor)
{
	CStringStack stack;
	stack.Push("0");
	stack.Push("1");
	stack.Push("2");
	auto clone(stack);
	BOOST_CHECK_EQUAL(clone.GetStackSize(), 3);
	BOOST_CHECK_EQUAL(clone.GetTopElement(), "2");
	clone.Pop();
	BOOST_CHECK_EQUAL(clone.GetTopElement(), "1");
	clone.Pop();
	BOOST_CHECK_EQUAL(clone.GetTopElement(), "0");
	clone.Pop();
}
BOOST_AUTO_TEST_SUITE_END()
