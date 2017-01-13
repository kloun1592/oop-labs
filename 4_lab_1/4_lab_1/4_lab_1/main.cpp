#include "stdafx.h"
#include "Body.h"
#include "Cone.h"
#include "Cylinder.h"


int main()
{
	double height = 10;
	double baseRadius = 10;
	double density = 1000;
	CCylinder cone(density, baseRadius, height);
	std::cout << cone.ToString();
    return 0;
}

