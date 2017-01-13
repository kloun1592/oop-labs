#include "stdafx.h"
#include "Compound.h"

bool CCompound::SetParent(CCompound * compound)
{
	if (m_parent == nullptr)
	{
		m_parent = compound;
		return true;
	}
	return false;
}

CCompound * CCompound::GetParent() const
{
	return m_parent;
}

void CCompound::AppendProperties(std::ostream & strm) const
{
}

CCompound::CCompound()
	: CBody("Compound", 0)
{
}

double CCompound::GetVolume() const
{
	return m_volume;
}

double CCompound::GetMass() const
{
	return m_mass;
}

double CCompound::GetDensity() const
{
	return GetMass() / GetVolume();
}

bool CCompound::AddChildBody(const std::shared_ptr<CBody>& child)
{
	if (child != nullptr && SetParent(this))
	{
		m_children.emplace_back(child);
		m_mass += child->GetMass();
		m_volume += child->GetVolume();
		return true;
	}
	return false;
}

bool CCompound::IsEmpty() const
{
	return m_children.empty();
}

size_t CCompound::GetChildQuantity() const
{
	return m_children.size();
}
