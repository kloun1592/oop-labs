#include "stdafx.h"
#include "../6_lab_4/solve.h"

BOOST_AUTO_TEST_SUITE(Solve2_tests)
	BOOST_AUTO_TEST_CASE(count_right_roots)
	{
		auto x = Solve2(1, 10, -24);
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
		auto x = Solve2(3, -18, 27);
		BOOST_CHECK_EQUAL(x.roots[0], 3.0);
	}

	BOOST_AUTO_TEST_CASE(discriminant_is_bigger_than_zero)
	{
		auto x = Solve2(1, -2, -24);
		BOOST_CHECK_EQUAL(x.roots[0], 6.0);
		BOOST_CHECK_EQUAL(x.roots[1], -4.0);
	}
BOOST_AUTO_TEST_SUITE_END()	

BOOST_AUTO_TEST_SUITE(Solve3_tests)
	BOOST_AUTO_TEST_CASE(count_right_roots)
	{
		auto x = Solve3(4, -10, 14, -5);
		BOOST_CHECK_EQUAL(x.roots[0], 0.5);
	}

	BOOST_AUTO_TEST_CASE(has_3_roots)
	{
		auto x = Solve3(1, 2, -5, -6);
		BOOST_CHECK_EQUAL(x.roots[0], -3);
		BOOST_CHECK_EQUAL(x.roots[1], 2);
		BOOST_CHECK_CLOSE_FRACTION(x.roots[2], -1, 10e-6);
	}

	BOOST_AUTO_TEST_CASE(has_1_root)
	{
		auto x = Solve3(1, -1, -1, -2);
		BOOST_CHECK_CLOSE_FRACTION(x.roots[0], 2, 0.3);
		x = Solve3(1, -1, 1, -1);
		BOOST_CHECK_CLOSE_FRACTION(x.roots[0], 1, 0.0001);
		x = Solve3(1, 3, 3, 2);
		BOOST_CHECK_CLOSE_FRACTION(x.roots[0], -2, 0.13);
	}

	BOOST_AUTO_TEST_CASE(has_incorrect_first_argument)
	{
		BOOST_REQUIRE_THROW(Solve3(0, 0, 0, 0), std::invalid_argument);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Solve4_tests)
	BOOST_AUTO_TEST_CASE(count_right_roots)
	{
		auto x = Solve4(1, 0, 0, 0, 0);
		BOOST_CHECK_EQUAL(x.roots[0], 0.0);
		BOOST_CHECK_EQUAL(x.roots[1], 0.0);
	}

	BOOST_AUTO_TEST_CASE(has_only_complex_roots)
	{
		BOOST_CHECK_THROW(Solve4(1, 2, 3, 4, 5), std::domain_error);
	}

	BOOST_AUTO_TEST_CASE(has_only_2_roots)
	{
		auto x = Solve4(2, 0, 5, 0, -3);
		BOOST_CHECK_CLOSE_FRACTION(x.roots[2], 0.7071, 0.0001);
		BOOST_CHECK_CLOSE_FRACTION(x.roots[3], -0.7071, 0.0001);
	}

	BOOST_AUTO_TEST_CASE(has_only_2_roots_in_other_situation)
	{
		auto x = Solve4(1, 9, 8, 7, 6);
		BOOST_CHECK_CLOSE_FRACTION(x.roots[1], -8.1086, 0.0001);
		BOOST_CHECK_CLOSE_FRACTION(x.roots[0], -0.9232, 0.0001);
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
