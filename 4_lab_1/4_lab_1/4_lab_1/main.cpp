#include "stdafx.h"
#include "Body.h"
#include "Cone.h"
#include "Cylinder.h"
#include "Compound.h"
#include "Sphere.h"


int main()
{
	double height = 10;
	double baseRadius = 10;
	double density = 1000;
	CCylinder cone(density, baseRadius, height);
	CCompound body = CCompound();
	std::shared_ptr<CBody> sphere = std::make_shared<CSphere>(2, 1);
	body.AddChildBody(sphere);
	std::cout << sphere->GetMass() << std::endl;
	std::cout << body.GetParent() << std::endl;
    return 0;
}

