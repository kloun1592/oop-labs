#define BOOST_TEST_NO_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../3_lab_1/main.cpp"

struct RectangleSetfixture
{
    CRectangle rectangle;
};

RecParam CreateBasicRecParam()
{
    RecParam recParam;
    recParam.leftX = 5;
    recParam.topY = 5;
    recParam.width = 10;
    recParam.height = 10;
    return recParam;
}

BOOST_FIXTURE_TEST_SUITE(RectangleSet, RectangleSetfixture)

    BOOST_AUTO_TEST_CASE(is_rectangle_has_right_parametrs)
    {
        RecParam recParam = CreateBasicRecParam();
        rectangle.SetRectangleParametrs(recParam);
        BOOST_CHECK_EQUAL(rectangle.GetParametrs().leftX, recParam.leftX);
        BOOST_CHECK_EQUAL(rectangle.GetParametrs().topY, recParam.topY);
        BOOST_CHECK_EQUAL(rectangle.GetParametrs().width, recParam.width);
        BOOST_CHECK_EQUAL(rectangle.GetParametrs().height, recParam.height);
    }

    BOOST_AUTO_TEST_CASE(get_left_top_parametrs)
    {
        RecParam recParam = CreateBasicRecParam();
        rectangle.SetRectangleParametrs(recParam);
        BOOST_CHECK_EQUAL(rectangle.GetLeftTopPoint().x, recParam.leftX);
        BOOST_CHECK_EQUAL(rectangle.GetLeftTopPoint().y, recParam.topY);
    }

    BOOST_AUTO_TEST_CASE(get_bottom_right_parametrs)
    {
        RecParam recParam = CreateBasicRecParam();
        rectangle.SetRectangleParametrs(recParam);
        BOOST_CHECK_EQUAL(rectangle.GetRightBottomPoint().x, recParam.leftX + recParam.width);
        BOOST_CHECK_EQUAL(rectangle.GetRightBottomPoint().y, recParam.topY + recParam.height);
    }

    BOOST_AUTO_TEST_CASE(get_rectangle_size)
    {
        RecParam recParam = CreateBasicRecParam();
        rectangle.SetRectangleParametrs(recParam);
        BOOST_CHECK_EQUAL(rectangle.GetSize().width, recParam.width);
        BOOST_CHECK_EQUAL(rectangle.GetSize().height, recParam.height);
    }

    BOOST_AUTO_TEST_CASE(count_rectangle_perimetr)
    {
        RecParam recParam = CreateBasicRecParam();
        rectangle.SetRectangleParametrs(recParam);
        int recPerimetr = 2 * (recParam.width + recParam.height);
        BOOST_CHECK_EQUAL(rectangle.CountPerimetr(), recPerimetr);
    }

    BOOST_AUTO_TEST_CASE(count_rectangle_area)
    {
        RecParam recParam = CreateBasicRecParam();
        rectangle.SetRectangleParametrs(recParam);
        int recArea = recParam.width * recParam.height;
        BOOST_CHECK_EQUAL(rectangle.CountArea(), recArea);
    }

    BOOST_AUTO_TEST_CASE(move_rectangle)
    {
        RecParam recParam = CreateBasicRecParam();
        rectangle.SetRectangleParametrs(recParam);
        rectangle.Move(1, 1);
        BOOST_CHECK_EQUAL(rectangle.GetLeftTopPoint().x, recParam.leftX + 1);
        BOOST_CHECK_EQUAL(rectangle.GetLeftTopPoint().y, recParam.topY + 1);
    }

    BOOST_AUTO_TEST_CASE(scale_rectangle)
    {
        RecParam recParam = CreateBasicRecParam();
        rectangle.SetRectangleParametrs(recParam);
        rectangle.Scale(2, 2);
        BOOST_CHECK_EQUAL(rectangle.GetSize().width, recParam.width * 2);
        BOOST_CHECK_EQUAL(rectangle.GetSize().height, recParam.height * 2);
    }
}

struct RectangleSetfixture2
{
    CRectangle rectangle1;
    CRectangle rectangle2;
};

BOOST_FIXTURE_TEST_SUITE(RectangleSet2, RectangleSetfixture2)

    BOOST_AUTO_TEST_CASE(intersect_of_two_rectangles)
    {
        RecParam recParam = CreateBasicRecParam();
        rectangle1.SetRectangleParametrs(recParam);
        rectangle2.SetRectangleParametrs(recParam);
        BOOST_CHECK_EQUAL(rectangle1.Intersect(rectangle2), true);
    }

    BOOST_AUTO_TEST_CASE(not_intersect_of_two_rectangles)
    {
        RecParam recParam = CreateBasicRecParam();
        rectangle1.SetRectangleParametrs(recParam);
        recParam.leftX = recParam.topY = 125;
        rectangle2.SetRectangleParametrs(recParam);
        BOOST_CHECK_EQUAL(rectangle1.Intersect(rectangle2), false);
    }
}
