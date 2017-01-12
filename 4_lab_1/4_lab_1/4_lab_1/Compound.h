#pragma once
#include "Body.h"
class CCompound final :
	public CBody
{
public:
	double GetVolume() const override;
	double GetMass() const;
	double GetDensity() const;
	bool AddChildBody(const std::shared_ptr<CBody> & childBody);
	bool IsEmpty() const;
	size_t GetChildQuantity() const;
	CCompound * GetParent() const;
	bool SetParent(CCompound * compound);
	bool IsCanAddedToCompound(CCompound * compound) const;
private:
	CCompound * m_parent;
	std::vector<std::shared_ptr<CBody>> m_children;
	double m_volume = 0;
	double m_mass = 0;

};