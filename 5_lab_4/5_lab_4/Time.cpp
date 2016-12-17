#include "stdafx.h"
#include "Time.h"

const unsigned MAX_TIME = 86399; // 23:59:59

CTime::CTime(unsigned hours, unsigned minutes, unsigned seconds)
{
	if (hours >= 24 || minutes >= 60 || seconds >= 60)
	{
		throw std::invalid_argument("incorrectly specified time");
	}

	m_time = (hours * 60 + minutes) * 60 + seconds;
}

CTime::CTime(unsigned timeStamp)
{
	if (timeStamp > MAX_TIME)
	{
		timeStamp = timeStamp % 60;
	}

	m_time = timeStamp;
}

unsigned CTime::GetHours()const
{
	return m_time / 3600;
}

unsigned CTime::GetMinutes()const
{
	return (m_time / 60) % 60;
}

unsigned CTime::GetSeconds()const
{
	return m_time % 60;
}

unsigned CTime::GetTimeStamp()const
{
	return m_time;
}

const CTime CTime::operator ++ ()
{
	m_time++;
	if (m_time > MAX_TIME)
	{
		m_time = m_time % 60;
	}
	return *this;
}

const CTime CTime::operator ++ (int)
{
	CTime temp = *this;
	++*this;
	return temp;
}

const CTime CTime::operator -- ()
{
	m_time--;
	return *this;
}

const CTime CTime::operator -- (int)
{
	CTime temp = *this;
	--*this;
	return temp;
}

CTime const CTime::operator + (CTime const& time)const
{
	if (m_time + time.GetTimeStamp() > 86399)
	{
		return CTime((m_time + time.GetTimeStamp()) % 60);
	}
	else
	{
		return CTime(m_time + time.GetTimeStamp());
	}
}

CTime const CTime::operator - (CTime const& time)const
{
	return CTime(m_time - time.GetTimeStamp());
}

CTime& CTime::operator += (CTime const& time)
{
	m_time += time.GetTimeStamp();
	if (m_time > 86399)
	{
		m_time = m_time % 60;
	}
	return *this;
}

CTime& CTime::operator -= (CTime const& time)
{
	m_time -= time.GetTimeStamp();
	return *this;
}

CTime const CTime::operator * (unsigned multiplier)const
{
	if (m_time * multiplier > MAX_TIME)
	{
		return CTime((m_time * multiplier) % 60);
	}
	else
	{
		return CTime(m_time * multiplier);
	}
}

CTime const operator * (unsigned multiplier, CTime const& time)
{
	if (multiplier * time.GetTimeStamp() > MAX_TIME)
	{
		return CTime((multiplier * time.GetTimeStamp()) % 60);
	}
	else
	{
		return CTime(multiplier * time.GetTimeStamp());
	}
}

CTime const CTime::operator / (unsigned divider)const
{
	return CTime(m_time / divider);
}

CTime& CTime::operator *= (unsigned multiplier)
{
	m_time *= multiplier;
	if (m_time > MAX_TIME)
	{
		m_time = m_time % 60;
	}
	return *this;
}

CTime const operator *= (unsigned multiplier, CTime const& time)
{
	if (time.GetTimeStamp() * multiplier > MAX_TIME)
	{
		return CTime((time.GetTimeStamp() * multiplier) % 60);
	}
	else
	{
		return CTime(time.GetTimeStamp() * multiplier);
	}
}

CTime& CTime::operator /= (CTime const& time)
{
	m_time /= time.GetTimeStamp();
	return *this;
}

bool CTime::operator == (CTime const& time)const
{
	return m_time == time.GetTimeStamp();
}

bool CTime::operator != (CTime const& time)const
{
	return m_time != time.GetTimeStamp();
}

bool CTime::operator > (CTime const& time)const
{
	return m_time > time.GetTimeStamp();
}

bool CTime::operator < (CTime const& time)const
{
	return m_time < time.GetTimeStamp();
}

bool CTime::operator >= (CTime const& time)const
{
	return m_time >= time.GetTimeStamp();
}

bool CTime::operator <= (CTime const& time)const
{
	return m_time <= time.GetTimeStamp();
}

std::ostream& operator << (std::ostream& stream, const CTime & time)
{
	stream << time.GetHours() << ':' << time.GetMinutes() << ':' << time.GetSeconds();
	return stream;
};

std::istream & operator >> (std::istream & stream, CTime & time)
{
	unsigned hours, minutes, seconds;
	if (
		(stream >> hours) &&
		(stream.get() == ':') &&
		(stream >> minutes) &&
		(stream.get() == ':') &&
		(stream >> seconds)
		)
	{
		time = CTime(hours, minutes, seconds);
	}
	return stream;
}