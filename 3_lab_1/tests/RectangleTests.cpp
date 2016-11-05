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

void ExpectRectangle(int const& leftX, int const& topY, int const& width, int const& height)
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

    BOOST_AUTO_TEST_CASE(expect_correct_param)
    {
        ExpectRectangle(leftX, topY, width, height);
    }

    BOOST_AUTO_TEST_CASE(correctly_moved)
    {
        CRectangle rectangle(leftX, topY, width, height);
        rectangle.Move(1, 1);
        BOOST_CHECK_EQUAL(rectangle.GetLeftTopPoint().x, leftX + 1);
        BOOST_CHECK_EQUAL(rectangle.GetLeftTopPoint().y, topY + 1);
    }

    BOOST_AUTO_TEST_CASE(correctly_scaled)
    {
        CRectangle rectangle(leftX, topY, width, height);
        rectangle.Scale(2, 2);
        BOOST_CHECK_EQUAL(rectangle.GetSize().width, width * 2);
        BOOST_CHECK_EQUAL(rectangle.GetSize().height, height * 2);
    }
}

BOOST_FIXTURE_TEST_SUITE(Two_Rectangles, Rectanglefixture)

    BOOST_AUTO_TEST_CASE(intersect)
    {
        CRectangle rectangle1(leftX, topY, width, height);
        CRectangle rectangle2(leftX, topY, width, height);
        BOOST_CHECK_EQUAL(rectangle1.Intersect(rectangle2), true);
    }

    BOOST_AUTO_TEST_CASE(do_not_intersect)
    {
        CRectangle rectangle1(leftX, topY, width, height);
        CRectangle rectangle2(leftX + 100, topY + 100, width, height);
        BOOST_CHECK_EQUAL(rectangle1.Intersect(rectangle2), false);
    }
}
