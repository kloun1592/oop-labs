#include "stdafx.h"

#include "../5_lab_4/5_lab_4/Time.h"

BOOST_AUTO_TEST_SUITE(Time)

	BOOST_AUTO_TEST_CASE(has_correct_hours_minutes_seconds)
	{
	    unsigned hours = 6;
		unsigned minutes = 10;
		unsigned seconds = 42;
		CTime time(hours, minutes, seconds);
		BOOST_CHECK(time.GetHours(), hours);
		BOOST_CHECK(time.GetMinutes(), minutes);
		BOOST_CHECK(time.GetSeconds(), seconds);
	}

    BOOST_AUTO_TEST_CASE(has_incorrect_hours)
    {
	    unsigned hours = 25;
	    unsigned minutes = 10;
	    unsigned seconds = 42;
     	CTime time(hours, minutes, seconds);
	    BOOST_CHECK(time.IsValid(), false);
    }

	BOOST_AUTO_TEST_CASE(has_incorrect_minutes)
	{
		unsigned hours = 23;
		unsigned minutes = 100;
		unsigned seconds = 42;
		CTime time(hours, minutes, seconds);
		BOOST_CHECK(time.IsValid(), false);
	}

	BOOST_AUTO_TEST_CASE(has_incorrect_seconds)
	{
		unsigned hours = 13;
		unsigned minutes = 10;
		unsigned seconds = 365;
		CTime time(hours, minutes, seconds);
		BOOST_CHECK(time.IsValid(), false);
	}

	BOOST_AUTO_TEST_CASE(increase_by_1_second)
	{
		unsigned hours = 13;
		unsigned minutes = 10;
		unsigned seconds = 11;
		CTime time(hours, minutes, seconds);
		unsigned currTime = time.GetTimeStamp();
		++time;
		BOOST_CHECK(time.GetTimeStamp(), currTime + 1);
		time++;
		BOOST_CHECK(time.GetTimeStamp(), currTime + 2);
	}

	BOOST_AUTO_TEST_CASE(decrease_by_1_second)
	{
		unsigned hours = 13;
		unsigned minutes = 10;
		unsigned seconds = 11;
		CTime time(hours, minutes, seconds);
		unsigned currTime = time.GetTimeStamp();
		--time;
		BOOST_CHECK(time.GetTimeStamp(), currTime - 1);
		time--;
		BOOST_CHECK(time.GetTimeStamp(), currTime - 2);
	}

	BOOST_AUTO_TEST_CASE(increase_by_other_time_by_1_command)
	{
		unsigned hours = 13;
		unsigned minutes = 10;
		unsigned seconds = 11;
		CTime time(hours, minutes, seconds);
		CTime anotherTime(1, 1, 1);
		CTime resultTime = time + anotherTime;
		BOOST_CHECK(resultTime.GetHours(), hours + 1);
		BOOST_CHECK(resultTime.GetMinutes(), minutes + 1);
		BOOST_CHECK(resultTime.GetSeconds(), seconds + 1);
	}


	BOOST_AUTO_TEST_CASE(decrease_by_other_time_by_1_command)
	{
		unsigned hours = 13;
		unsigned minutes = 10;
		unsigned seconds = 11;
		CTime time(hours, minutes, seconds);
		CTime anotherTime(1, 1, 1);
		CTime resultTime = time - anotherTime;
		BOOST_CHECK(resultTime.GetHours(), hours - 1);
		BOOST_CHECK(resultTime.GetMinutes(), minutes - 1);
		BOOST_CHECK(resultTime.GetSeconds(), seconds - 1);
	}

	BOOST_AUTO_TEST_CASE(increase_by_other_time_by_2_command)
	{
		unsigned hours = 13;
		unsigned minutes = 10;
		unsigned seconds = 11;
		CTime time(hours, minutes, seconds);
		CTime anotherTime(1, 1, 1);
		time += anotherTime;
		BOOST_CHECK(time.GetHours(), hours + 1);
		BOOST_CHECK(time.GetMinutes(), minutes + 1);
		BOOST_CHECK(time.GetSeconds(), seconds + 1);
	}


	BOOST_AUTO_TEST_CASE(decrease_by_other_time_by_2_command)
	{
		unsigned hours = 13;
		unsigned minutes = 10;
		unsigned seconds = 11;
		CTime time(hours, minutes, seconds);
		CTime anotherTime(1, 1, 1);
		time -= anotherTime;
		BOOST_CHECK(time.GetHours(), hours - 1);
		BOOST_CHECK(time.GetMinutes(), minutes - 1);
		BOOST_CHECK(time.GetSeconds(), seconds - 1);
	}

	BOOST_AUTO_TEST_CASE(divided_by_the_divisor_by_1_command)
	{
		unsigned hours = 12;
		unsigned minutes = 15;
		unsigned seconds = 21;
		CTime time(hours, minutes, seconds);
		time = time / 3;
		BOOST_CHECK(time.GetHours(), hours / 3);
		BOOST_CHECK(time.GetMinutes(), minutes / 3);
		BOOST_CHECK(time.GetSeconds(), seconds / 3);
	}

	BOOST_AUTO_TEST_CASE(divided_by_the_divisor_by_2_command)
	{
		unsigned hours = 12;
		unsigned minutes = 15;
		unsigned seconds = 21;
		CTime time(hours, minutes, seconds);
		time /= 3;
		BOOST_CHECK(time.GetHours(), hours / 3);
		BOOST_CHECK(time.GetMinutes(), minutes / 3);
		BOOST_CHECK(time.GetSeconds(), seconds / 3);
	}

	BOOST_AUTO_TEST_CASE(multiplied_by_a_multiplier_by_1_command)
	{
		unsigned hours = 1;
		unsigned minutes = 2;
		unsigned seconds = 3;
		CTime time(hours, minutes, seconds);
		time = time * 3;
		BOOST_CHECK(time.GetHours(), hours * 3);
		BOOST_CHECK(time.GetMinutes(), minutes * 3);
		BOOST_CHECK(time.GetSeconds(), seconds * 3);
	}

	BOOST_AUTO_TEST_CASE(multiplied_by_a_multiplier_by_2_command)
	{
		unsigned hours = 1;
		unsigned minutes = 2;
		unsigned seconds = 3;
		CTime time(hours, minutes, seconds);
		time *= 3;
		BOOST_CHECK(time.GetHours(), hours * 3);
		BOOST_CHECK(time.GetMinutes(), minutes * 3);
		BOOST_CHECK(time.GetSeconds(), seconds * 3);
	}

	BOOST_AUTO_TEST_CASE(is_smaller_than_another_time)
	{
		unsigned hours = 5;
		unsigned minutes = 6;
		unsigned seconds = 3;
		CTime time(hours, minutes, seconds);
		CTime anotherTime(13, 10, 11);
		BOOST_CHECK(time < anotherTime, true);
	}

	BOOST_AUTO_TEST_CASE(is_smaller_or_equal_than_another_time)
	{
		unsigned hours = 5;
		unsigned minutes = 6;
		unsigned seconds = 3;
		CTime time(hours, minutes, seconds);
		CTime anotherTime(13, 10, 11);
		BOOST_CHECK(time <= anotherTime, true);
	}

	BOOST_AUTO_TEST_CASE(is_bigger_than_another_time)
	{
		unsigned hours = 13;
		unsigned minutes = 10;
		unsigned seconds = 11;
		CTime time(hours, minutes, seconds);
		CTime anotherTime(5, 6, 3);
		BOOST_CHECK(time > anotherTime, true);
	}

	BOOST_AUTO_TEST_CASE(is_bigger_or_equal_than_another_time)
	{
		unsigned hours = 13;
		unsigned minutes = 10;
		unsigned seconds = 11;
		CTime time(hours, minutes, seconds);
		CTime anotherTime(5, 6, 3);
		BOOST_CHECK(time >= anotherTime, true);
	}

	BOOST_AUTO_TEST_CASE(equally_to_another_time)
	{
		unsigned hours = 13;
		unsigned minutes = 10;
		unsigned seconds = 11;
		CTime time(hours, minutes, seconds);
		CTime anotherTime(hours, minutes, seconds);
		BOOST_CHECK(time == anotherTime, true);
		BOOST_CHECK_EQUAL(time != anotherTime, false);
	}

	BOOST_AUTO_TEST_CASE(not_equally_to_another_time)
	{
		unsigned hours = 13;
		unsigned minutes = 10;
		unsigned seconds = 11;
		CTime time(hours, minutes, seconds);
		CTime anotherTime(14, minutes, seconds);
		//BOOST_CHECK(time == anotherTime, false);
		//BOOST_CHECK_EQUAL(time != anotherTime, true);
	}


BOOST_AUTO_TEST_SUITE_END()