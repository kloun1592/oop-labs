#define BOOST_TEST_NO_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../3_lab_1/Rectangle.h"

struct Rectanglefixture
{
    int leftX = 10;
    int topY = 10;
    int width = 110;
    int height = 12;
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

void VerifyRectanglesIntersection(Rectanglefixture & recParam1, Rectanglefixture & recParam2, RecParam &expectedIntersectedRecParam)
{
    CRectangle rectangle1(recParam1.leftX, recParam1.topY, recParam1.width, recParam1.height);
    CRectangle rectangle2(recParam2.leftX, recParam2.topY, recParam2.width, recParam2.height);
    
    if (rectangle1.Intersect(rectangle2))
    {
        RecParam intersectRec = rectangle1.GetIntersectRecParam(rectangle2);
        
        BOOST_CHECK_EQUAL(intersectRec.leftX, expectedIntersectedRecParam.leftX);
        BOOST_CHECK_EQUAL(intersectRec.topY, expectedIntersectedRecParam.topY);
        BOOST_CHECK_EQUAL(intersectRec.width, expectedIntersectedRecParam.width);
        BOOST_CHECK_EQUAL(intersectRec.height, expectedIntersectedRecParam.height);
        BOOST_CHECK_EQUAL(intersectRec.leftX + intersectRec.width, expectedIntersectedRecParam.leftX + expectedIntersectedRecParam.width);
        BOOST_CHECK_EQUAL(intersectRec.topY + intersectRec.height , expectedIntersectedRecParam.topY + expectedIntersectedRecParam.height);
        int intersectRecPerimetr = 2 * (intersectRec.width + intersectRec.height);
        int expectedIntersectedRecPerimeter = 2 * (expectedIntersectedRecParam.width + expectedIntersectedRecParam.height);
        BOOST_CHECK_EQUAL(intersectRecPerimetr, expectedIntersectedRecPerimeter);
        int intersectRecArea = intersectRec.width * intersectRec.height;
        int expectedIntersectedRecArea = expectedIntersectedRecParam.width * expectedIntersectedRecParam.height;
        BOOST_CHECK_EQUAL(intersectRecArea, expectedIntersectedRecArea);
    }
    else
    {
        RecParam intersectRec = rectangle1.GetIntersectRecParam(rectangle2);

        BOOST_CHECK_EQUAL(intersectRec.leftX, expectedIntersectedRecParam.leftX);
        BOOST_CHECK_EQUAL(intersectRec.topY, expectedIntersectedRecParam.topY);
    }
}

BOOST_FIXTURE_TEST_SUITE(Rectangle, Rectanglefixture)

    BOOST_AUTO_TEST_CASE(after_creating_has_parametrs_which_were_send_in_constructor)
    {
        ExpectRectangle(leftX, topY, width, height);
    }

    BOOST_AUTO_TEST_CASE(after_moving_change_its_coordinates_and_do_not_change_sizes)
    {
        CRectangle rectangle(leftX, topY, width, height);
        rectangle.Move(1, 1);
        BOOST_CHECK_EQUAL(rectangle.GetLeftTopPoint().x, leftX + 1);
        BOOST_CHECK_EQUAL(rectangle.GetLeftTopPoint().y, topY + 1);
    }

    BOOST_AUTO_TEST_CASE(after_scaling_change_its_sizes_and_do_not_change_left_top_point_coordinates)
    {
        CRectangle rectangle(leftX, topY, width, height);
        rectangle.Scale(2, 2);
        BOOST_CHECK_EQUAL(rectangle.GetSize().width, width * 2);
        BOOST_CHECK_EQUAL(rectangle.GetSize().height, height * 2);
    }
}

BOOST_FIXTURE_TEST_SUITE(Rectangle_after_intersection_with_other_rectangle, Rectanglefixture)

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

    BOOST_AUTO_TEST_CASE(with_similar_y_coordinate)
    {
        Rectanglefixture rec1;
        rec1.leftX = 5;
        rec1.topY = 5;
        rec1.width = 5;
        rec1.height = 5;
        
        Rectanglefixture rec2;
        rec2.leftX = 7;
        rec2.topY = 5;
        rec2.width = 10;
        rec2.height = 5;
        
        RecParam intersectedRec;
        intersectedRec.leftX = 7;
        intersectedRec.topY = 5;
        intersectedRec.width = 3;
        intersectedRec.height = 5;
        
        VerifyRectanglesIntersection(rec1, rec2, intersectedRec);
    }

    BOOST_AUTO_TEST_CASE(with_similar_x_coordinate)
    {
        Rectanglefixture rec1;
        rec1.leftX = 1;
        rec1.topY = 1;
        rec1.width = 9;
        rec1.height = 4;
    
        Rectanglefixture rec2;
        rec2.leftX = 1;
        rec2.topY = 4;
        rec2.width = 5;
        rec2.height = 6;
    
        RecParam intersectedRec;
        intersectedRec.leftX = 1;
        intersectedRec.topY = 4;
        intersectedRec.width = 5;
        intersectedRec.height = 1;
    
        VerifyRectanglesIntersection(rec1, rec2, intersectedRec);
    }

    BOOST_AUTO_TEST_CASE(with_similar_x_and_y_coordinate)
    {
        Rectanglefixture rec1;
        rec1.leftX = 1;
        rec1.topY = 1;
        rec1.width = 9;
        rec1.height = 9;
    
        Rectanglefixture rec2;
        rec2.leftX = 1;
        rec2.topY = 1;
        rec2.width = 4;
        rec2.height = 5;
    
        RecParam intersectedRec;
        intersectedRec.leftX = 1;
        intersectedRec.topY = 1;
        intersectedRec.width = 4;
        intersectedRec.height = 5;
    
        VerifyRectanglesIntersection(rec1, rec2, intersectedRec);
    }

    BOOST_AUTO_TEST_CASE(with_different_x_and_y_coordinate)
    {
        Rectanglefixture rec1;
        rec1.leftX = 1;
        rec1.topY = 1;
        rec1.width = 10;
        rec1.height = 5;
    
        Rectanglefixture rec2;
        rec2.leftX = 5;
        rec2.topY = 2;
        rec2.width = 10;
        rec2.height = 7;
    
        RecParam intersectedRec;
        intersectedRec.leftX = 5;
        intersectedRec.topY = 2;
        intersectedRec.width = 6;
        intersectedRec.height = 4;
    
        VerifyRectanglesIntersection(rec1, rec2, intersectedRec);
    }

    BOOST_AUTO_TEST_CASE(when_rectangle_contains_other_rectangle)
    {
        Rectanglefixture rec1;
        rec1.leftX = 1;
        rec1.topY = 1;
        rec1.width = 8;
        rec1.height = 7;
    
        Rectanglefixture rec2;
        rec2.leftX = 5;
        rec2.topY = 3;
        rec2.width = 2;
        rec2.height = 4;
    
        RecParam intersectedRec;
        intersectedRec.leftX = 5;
        intersectedRec.topY = 3;
        intersectedRec.width = 2;
        intersectedRec.height = 4;
    
        VerifyRectanglesIntersection(rec1, rec2, intersectedRec);
    }
}

BOOST_FIXTURE_TEST_SUITE(Rectangle_do_not_intersect_other_rectangle, Rectanglefixture)

    BOOST_AUTO_TEST_CASE(when_they_have_one_own_side)
    {
        Rectanglefixture rec1;
        rec1.leftX = 1;
        rec1.topY = 1;
        rec1.width = 4;
        rec1.height = 4;
    
        Rectanglefixture rec2;
        rec2.leftX = 5;
        rec2.topY = 1;
        rec2.width = 5;
        rec2.height = 6;
    
        RecParam intersectedRec;
        intersectedRec.leftX = 5;
        intersectedRec.topY = 1;
        intersectedRec.width = 0;
        intersectedRec.height = 0;
    
        VerifyRectanglesIntersection(rec1, rec2, intersectedRec);
    }
}
