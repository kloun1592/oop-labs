#include "stdafx.h"
#include "Cylinder.h"

CCylinder::CCylinder(double density, double baseRadius, double height)
	: CBody("Cylinder", density)
	, m_baseRadius(baseRadius)
	, m_height(height)
{
	if (height <= 0 || baseRadius <= 0 || density <= 0)
	{
		throw std::invalid_argument("Arguments should be bigger than 0 and not equally to 0");
	}
}

double CCylinder::GetBaseRadius() const
{
	return m_baseRadius;
}

double CCylinder::GetHeight() const
{
	return m_height;
}

double CCylinder::GetVolume() const
{
	return m_baseRadius * m_baseRadius * M_PI * m_height * 2;
}

void CCylinder::AppendProperties(std::ostream & strm) const
{
	strm << "\tbaseRadius = " << GetBaseRadius() << std::endl;
	strm << "\theight = " << GetHeight() << std::endl;
}
