#include "stdafx.h"
#include "../6_lab_4/6_lab_4.h"

BOOST_AUTO_TEST_SUITE(Solve2_tests)
	BOOST_AUTO_TEST_CASE(count_right_roots)
	{
		EquationRoots2 x = Solve2(1, 10, -24);
		BOOST_CHECK_EQUAL(x.roots[0], 2.0);
		BOOST_CHECK_EQUAL(x.roots[1], -12.0);
	}

	BOOST_AUTO_TEST_CASE(has_incorrect_first_argument)
	{
		BOOST_REQUIRE_THROW(Solve2(0, 0, 0), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(discriminant_is_smaller_than_zero)
	{
		BOOST_REQUIRE_THROW(Solve2(1, 1, 1), std::domain_error);
	}

	BOOST_AUTO_TEST_CASE(discriminant_is_equal_to_zero)
	{
		EquationRoots2 x = Solve2(3, -18, 27);
		BOOST_CHECK_EQUAL(x.roots[0], 3.0);
	}

	BOOST_AUTO_TEST_CASE(discriminant_is_bigger_than_zero)
	{
		EquationRoots2 x = Solve2(1, -2, -24);
		BOOST_CHECK_EQUAL(x.roots[0], 6.0);
		BOOST_CHECK_EQUAL(x.roots[1], -4.0);
	}
BOOST_AUTO_TEST_SUITE_END()	

BOOST_AUTO_TEST_SUITE(Solve3_tests)
	BOOST_AUTO_TEST_CASE(count_right_roots)
	{
		EquationRoots3 x = Solve3(4, -10, 14, -5);
		BOOST_CHECK_EQUAL(x.roots[0], 0.5);
	}

	BOOST_AUTO_TEST_CASE(has_incorrect_first_argument)
	{
		BOOST_REQUIRE_THROW(Solve3(0, 0, 0, 0), std::invalid_argument);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Solve4_tests)
	BOOST_AUTO_TEST_CASE(count_right_roots)
	{
		EquationRoots4 x = Solve4(1, 0, 0, 0, 0);
		BOOST_CHECK_EQUAL(x.roots[0], 0.0);
		BOOST_CHECK_EQUAL(x.roots[1], 0.0);
		BOOST_CHECK_EQUAL(x.roots[2], 0.0);
		BOOST_CHECK_EQUAL(x.roots[3], 0.0);
	}

	BOOST_AUTO_TEST_CASE(has_incorrect_first_argument)
	{
		BOOST_REQUIRE_THROW(Solve4(0, 0, 0, 0, 0), std::invalid_argument);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(sgn_tests)
	BOOST_AUTO_TEST_CASE(argument_is_bigger_than_zero)
	{
		BOOST_CHECK_EQUAL(sgn(0.1), 1.0);
	}

	BOOST_AUTO_TEST_CASE(argument_is_equal_to_zero)
	{
		BOOST_CHECK_EQUAL(sgn(0.0), 0.0);
	}

	BOOST_AUTO_TEST_CASE(argument_is_smaller_than_zero)
	{
		BOOST_CHECK_EQUAL(sgn(-0.1), -1.0);
	}
BOOST_AUTO_TEST_SUITE_END()