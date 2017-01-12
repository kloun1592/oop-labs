#pragma once
#include "Body.h"

class CCylinder final :
	public CBody
{
public:
	CCylinder(double density, double baseRadius, double height);

	double GetBaseRadius() const;
	double GetHeight() const;
	double GetVolume() const;
protected:
	void AppendProperties(std::ostream & strm) const override;
private:
	double m_height;
	double m_baseRadius;
};

