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

bool CCompound::IsCanAddedToCompound(CCompound * compound) const
{
	auto currentParent = compound;
	while (currentParent)
	{
		if (currentParent == this)
		{
			return false;
		}
		currentParent = currentParent->GetParent();
	}
	return true;
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

bool CCompound::AddChildBody(const std::shared_ptr<CBody>& childBody)
{
	if (childBody != nullptr && SetParent(this) && IsCanAddedToCompound(this))
	{
		m_children.emplace_back(childBody);
		m_mass += childBody->GetMass();
		m_volume += childBody->GetVolume();
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
