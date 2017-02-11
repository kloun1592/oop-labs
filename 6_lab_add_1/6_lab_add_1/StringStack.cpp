#include "stdafx.h"
#include "StringStack.h"


CStringStack CStringStack::Reverse() const
{
	CStringStack tmp;
	for (auto it = m_topElem.get(); it != nullptr; it = it->next.get())
	{
		tmp.Push(it->data);
	}
	return tmp;
}

CStringStack::CStringStack(const CStringStack & other)
{
	auto tmp = other.Reverse();
	tmp = tmp.Reverse();
	std::swap(tmp, *this);
}

CStringStack::CStringStack(CStringStack && other)
{
	m_topElem = std::move(other.m_topElem);
	m_size = other.m_size;
	other.m_size = 0;
}

CStringStack::~CStringStack()
{
	Clear();
}

void CStringStack::Push(const std::string &value)
{
	m_topElem = std::make_unique<Node>(value, m_topElem);
	++m_size;
}

void CStringStack::Pop()
{
	if (IsEmpty())
	{
		throw std::logic_error("Stack is empty");
	}
	m_topElem = std::move(m_topElem->next);
	--m_size;
}

size_t CStringStack::GetStackSize() const
{
	return m_size;
}

std::string CStringStack::GetTopElement() const
{
	if (IsEmpty())
	{
		throw std::logic_error("Stack is empty");
	}
	return m_topElem->data;
}

bool CStringStack::IsEmpty() const
{
	return m_size == 0;
}

void CStringStack::Clear()
{
	while (!IsEmpty())
	{
		Pop();
	}
}

CStringStack & CStringStack::operator=(const CStringStack & otherStack)
{
	if (&otherStack != this)
	{
		CStringStack tmp(otherStack);
		std::swap(tmp, *this);
	}
	return *this;
}

CStringStack & CStringStack::operator=(CStringStack && otherStack)
{
	if (&otherStack != this)
	{
		Clear();
		m_topElem = std::move(otherStack.m_topElem);
		m_size = otherStack.m_size;
		otherStack.m_size = 0;
	}
	return *this;
}
