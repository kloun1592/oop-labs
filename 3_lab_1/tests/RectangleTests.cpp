#define BOOST_TEST_NO_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../3_lab_1/Rectangle.cpp"

struct Rectanglefixture
{
    int leftX = 5;
    int topY = 5;
    int width = 10;
    int height = 11;
};

void ExpectRectangle(int leftX, int topY, int width, int height)
{
    CRectangle rectangle(leftX, topY, width, height);
    BOOST_CHECK_EQUAL(rectangle.GetLeftTopPoint().x, leftX);
    BOOST_CHECK_EQUAL(rectangle.GetLeftTopPoint().y, topY);
    BOOST_CHECK_EQUAL(rectangle.GetSize().width, width);
    BOOST_CHECK_EQUAL(rectangle.GetSize().height, height);
    BOOST_CHECK_EQUAL(rectangle.GetRightBottomPoint().x, leftX + width);
    BOOST_CHECK_EQUAL(rectangle.GetRightBottomPoint().y, topY + height);
    int recPerimetr = 2 * (width + height);
    BOOST_CHECK_EQUAL(rectangle.CalculatePerimeter(), recPerimetr);
    int recArea = width * height;
    BOOST_CHECK_EQUAL(rectangle.CalculateArea(), recArea);
    
}

BOOST_FIXTURE_TEST_SUITE(Rectangle, Rectanglefixture)

    BOOST_AUTO_TEST_CASE(after_creating_has_parametrs_which_were_send_in_constructor)
    {
        ExpectRectangle(leftX, topY, width, height);
    }

    BOOST_AUTO_TEST_CASE(after_moving_change_his_coordinates_and_do_not_change_sizes)
    {
        CRectangle rectangle(leftX, topY, width, height);
        rectangle.Move(1, 1);
        BOOST_CHECK_EQUAL(rectangle.GetLeftTopPoint().x, leftX + 1);
        BOOST_CHECK_EQUAL(rectangle.GetLeftTopPoint().y, topY + 1);
    }

    BOOST_AUTO_TEST_CASE(after_scaling_change_his_sizes_and_do_not_change_left_top_point_coordinates)
    {
        CRectangle rectangle(leftX, topY, width, height);
        rectangle.Scale(2, 2);
        BOOST_CHECK_EQUAL(rectangle.GetSize().width, width * 2);
        BOOST_CHECK_EQUAL(rectangle.GetSize().height, height * 2);
    }
}

BOOST_FIXTURE_TEST_SUITE(Rectangle_after_intersection_with_other_rectangls, Rectanglefixture)

    BOOST_AUTO_TEST_CASE(change_coordiantes_sizes_to_cover_their_total_area)
    {
        CRectangle rectangle1(leftX, topY, width, height);
        CRectangle rectangle2(leftX, topY, width, height);
        BOOST_CHECK_EQUAL(rectangle1.Intersect(rectangle2), true);
    }

    BOOST_AUTO_TEST_CASE(change_coordiantes_and_reset_sizes)
    {
        CRectangle rectangle1(leftX, topY, width, height);
        CRectangle rectangle2(leftX + 100, topY + 100, width, height);
        BOOST_CHECK_EQUAL(rectangle1.Intersect(rectangle2), false);
    }
}
