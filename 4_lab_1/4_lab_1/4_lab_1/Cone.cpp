#include "stdafx.h"
#include "Cone.h"

CCone::CCone(double density, double baseRadius, double height)
	: CBody("Cone", density)
	, m_baseRadius(baseRadius)
	, m_height(height)
{
	if (height <= 0 || baseRadius <= 0 || density <= 0)
	{
		throw std::invalid_argument("Arguments should be bigger than 0 and not equally to 0");
	}
}

double CCone::GetBaseRadius() const
{
	return m_baseRadius;
}

double CCone::GetHeight() const
{
	return m_height;
}

double CCone::GetVolume() const
{
	return m_baseRadius * m_baseRadius * M_PI * m_height / 3;
}

void CCone::AppendProperties(std::ostream & strm) const
{
	strm << "\tbaseRadius = " << GetBaseRadius() << std::endl;
	strm << "\theight = " << GetHeight() << std::endl;
}
