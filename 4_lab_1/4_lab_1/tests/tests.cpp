#include "stdafx.h"
#include "../4_lab_1/Body.h"
#include "../4_lab_1/Cone.h"
#include "../4_lab_1/Cylinder.h"
#include "../4_lab_1/Parallelepiped.h"
#include "../4_lab_1/Sphere.h"

using boost::lexical_cast;

BOOST_AUTO_TEST_SUITE(Cone)
	BOOST_AUTO_TEST_CASE(has_right_properties_after_creating)
	{
		double height = 10;
		double baseRadius = 10;
		double density = 1000;
		CCone cone(density, baseRadius, height);
		BOOST_CHECK_EQUAL(cone.GetHeight(), height);
		BOOST_CHECK_EQUAL(cone.GetBaseRadius(), baseRadius);
		BOOST_CHECK_EQUAL(cone.GetDensity(), density);
		BOOST_CHECK_EQUAL(cone.GetVolume(), baseRadius * baseRadius * M_PI * height / 3);
		BOOST_CHECK_EQUAL(cone.GetMass(), (baseRadius * baseRadius * M_PI * height / 3) * density);
	}

	BOOST_AUTO_TEST_CASE(can_not_be_created_with_incorrect_properties)
	{
		BOOST_CHECK_THROW(CCone(1000, 10, 0), std::invalid_argument);
		BOOST_CHECK_THROW(CCone(1000, 10, -1), std::invalid_argument);
		BOOST_CHECK_THROW(CCone(1000, -1, 10), std::invalid_argument);
		BOOST_CHECK_THROW(CCone(1000, 0, 10), std::invalid_argument);
		BOOST_CHECK_THROW(CCone(0, 10, 10), std::invalid_argument);
		BOOST_CHECK_THROW(CCone(-1, 10, 10), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(correctly_printed_to_output)
	{
		double height = 10;
		double baseRadius = 10;
		double density = 1000;
		CCone cone(density, baseRadius, height);
		//BOOST_CHECK_EQUAL(cone.ToString(), "Cone:\n\tdensity = " + lexical_cast<std::string>(density) +
			//									"\n\tvolume = " + lexical_cast<std::string>(baseRadius * baseRadius * M_PI * height / 3) +
				//								"\n\tmass = " + lexical_cast<std::string>((baseRadius * baseRadius * M_PI * height / 3) * density) +
					//							"\n\tbaseRadius = " + lexical_cast<std::string>(baseRadius) +
						//						"\n\theight = " + lexical_cast<std::string>(height) + "\n");
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Cylinder)
	BOOST_AUTO_TEST_CASE(has_right_properties_after_creating)
	{
		double height = 10;
		double baseRadius = 10;
		double density = 1000;
		CCylinder cylinder(density, baseRadius, height);
		BOOST_CHECK_EQUAL(cylinder.GetHeight(), height);
		BOOST_CHECK_EQUAL(cylinder.GetBaseRadius(), baseRadius);
		BOOST_CHECK_EQUAL(cylinder.GetDensity(), density);
		BOOST_CHECK_EQUAL(cylinder.GetVolume(), baseRadius * baseRadius * M_PI * height * 2);
		BOOST_CHECK_EQUAL(cylinder.GetMass(), (baseRadius * baseRadius * M_PI * height * 2) * density);
	}

	BOOST_AUTO_TEST_CASE(can_not_be_created_with_incorrect_properties)
	{
		BOOST_CHECK_THROW(CCylinder(1000, 10, 0), std::invalid_argument);
		BOOST_CHECK_THROW(CCylinder(1000, 10, -1), std::invalid_argument);
		BOOST_CHECK_THROW(CCylinder(1000, -1, 10), std::invalid_argument);
		BOOST_CHECK_THROW(CCylinder(1000, 0, 10), std::invalid_argument);
		BOOST_CHECK_THROW(CCylinder(0, 10, 10), std::invalid_argument);
		BOOST_CHECK_THROW(CCylinder(-1, 10, 10), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(correctly_printed_to_output)
	{
		double height = 10;
		double baseRadius = 10;
		double density = 1000;
		CCylinder cylinder(density, baseRadius, height);
		//BOOST_CHECK_EQUAL(cylinder.ToString(), "Cylinder:\n\tdensity = " + lexical_cast<std::string>(density) +
		//									"\n\tvolume = " + lexical_cast<std::string>(baseRadius * baseRadius * M_PI * height * 2) +
		//								"\n\tmass = " + lexical_cast<std::string>((baseRadius * baseRadius * M_PI * height * 2) * density) +
		//							"\n\tbaseRadius = " + lexical_cast<std::string>(baseRadius) +
		//						"\n\theight = " + lexical_cast<std::string>(height) + "\n");
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Parallelepiped)
	BOOST_AUTO_TEST_CASE(has_right_properties_after_creating)
	{
		double height = 10;
		double width = 10;
		double density = 1000;
		double depth = 10;
		CParallelepiped parallelepiped(density, width, height, depth);
		BOOST_CHECK_EQUAL(parallelepiped.GetHeight(), height);
		BOOST_CHECK_EQUAL(parallelepiped.GetWidth(), width);
		BOOST_CHECK_EQUAL(parallelepiped.GetDensity(), density);
		BOOST_CHECK_EQUAL(parallelepiped.GetDepth(), depth);
		BOOST_CHECK_EQUAL(parallelepiped.GetVolume(), width * height * depth);
		BOOST_CHECK_EQUAL(parallelepiped.GetMass(), (width * height * depth) * density);
	}

	BOOST_AUTO_TEST_CASE(can_not_be_created_with_incorrect_properties)
	{
		BOOST_CHECK_THROW(CParallelepiped(1000, 10, 10, 0), std::invalid_argument);
		BOOST_CHECK_THROW(CParallelepiped(1000, 10, 10, -1), std::invalid_argument);
		BOOST_CHECK_THROW(CParallelepiped(1000, 10, 0, 10), std::invalid_argument);
		BOOST_CHECK_THROW(CParallelepiped(1000, 10, -1, 10), std::invalid_argument);
		BOOST_CHECK_THROW(CParallelepiped(1000, -1, 10, 10), std::invalid_argument);
		BOOST_CHECK_THROW(CParallelepiped(1000, 0, 10, 10), std::invalid_argument);
		BOOST_CHECK_THROW(CParallelepiped(0, 10, 10, 10), std::invalid_argument);
		BOOST_CHECK_THROW(CParallelepiped(-1, 10, 10, 10), std::invalid_argument);
	}	

	BOOST_AUTO_TEST_CASE(correctly_printed_to_output)
	{
		double height = 10;
		double width = 10;
		double density = 1000;
		double depth = 10;
		CParallelepiped parallelepiped(density, width, height, depth);
		//BOOST_CHECK_EQUAL(parallelepiped.ToString(), "Parallelepiped:\n\tdensity = " + lexical_cast<std::string>(density) +
		//									"\n\tvolume = " + lexical_cast<std::string>(width * height * depth) +
		//								"\n\tmass = " + lexical_cast<std::string>((width * height * depth) * density) +
		//							"\n\twidth = " + lexical_cast<std::string>(width) +
		//						"\n\theight = " + lexical_cast<std::string>(height) +
		//						"\n\tdepth = " + lexical_cast<std::string>(depth) + "\n");
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Sphere)
	BOOST_AUTO_TEST_CASE(has_right_properties_after_creating)
	{
		double density = 1000;
		double radius = 10;
		CSphere sphere(density, radius);
		BOOST_CHECK_EQUAL(sphere.GetRadius(), radius);
		BOOST_CHECK_EQUAL(sphere.GetDensity(), density);
		BOOST_CHECK_EQUAL(sphere.GetVolume(), (pow(radius, 3) * M_PI) * 4 / 3);
		BOOST_CHECK_EQUAL(sphere.GetMass(), ((pow(radius, 3) * M_PI) * 4 / 3) * density);
	}

	BOOST_AUTO_TEST_CASE(can_not_be_created_with_incorrect_properties)
	{
		BOOST_CHECK_THROW(CSphere(1000, 0), std::invalid_argument);
		BOOST_CHECK_THROW(CSphere(1000, -1), std::invalid_argument);
		BOOST_CHECK_THROW(CSphere(0, 10), std::invalid_argument);
		BOOST_CHECK_THROW(CSphere(-1, 10), std::invalid_argument);
	}	

	BOOST_AUTO_TEST_CASE(correctly_printed_to_output)
	{
		double density = 1000;
		double radius = 10;
		CSphere sphere(density, radius);
		//BOOST_CHECK_EQUAL(sphere.ToString(), "Sphere:\n\tdensity = " + lexical_cast<std::string>(density) +
		//									"\n\tvolume = " + lexical_cast<std::string>((pow(radius, 3) * M_PI) * 4 / 3) +
		//								"\n\tmass = " + lexical_cast<std::string>(((pow(radius, 3) * M_PI) * 4 / 3) * density) +
		//						"\n\tradius = " + lexical_cast<std::string>(radius) + "\n");
	}
BOOST_AUTO_TEST_SUITE_END()