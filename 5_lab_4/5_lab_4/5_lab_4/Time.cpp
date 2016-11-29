#include "stdafx.h"
#include "Time.h"

CTime::CTime(unsigned hours, unsigned minutes, unsigned seconds)
   : m_time((hours > 24 || minutes > 60 || seconds > 60) ? (0, m_isTimeValid = false) : ((hours * 60 + minutes) * 60 + seconds))
{}

CTime::CTime(unsigned timeStamp)
	: m_time(timeStamp)
{}

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

bool CTime::IsValid()const
{
	return m_isTimeValid;
}


CTime operator ++ (CTime &other)
{
	unsigned time = other.GetTimeStamp();
	time++;
	CTime newTime(time);
	return newTime;
}

CTime operator -- (CTime &other)
{
	unsigned time = other.GetTimeStamp();
	time--;
	CTime newTime(time);
	return newTime;
}

const CTime CTime::operator + (const CTime time)
{
	return m_time + time.GetTimeStamp();
}

const CTime CTime::operator - (const CTime time)
{
	return m_time - time.GetTimeStamp();
}

const CTime CTime::operator += (const CTime time)
{
	return m_time + time.GetTimeStamp();
}

const CTime CTime::operator -= (const CTime time)
{
	return m_time - time.GetTimeStamp();
}

const CTime CTime::operator * (unsigned multiplier)
{
	return m_time *= multiplier;
}

const CTime CTime::operator / (unsigned divider)
{
	return m_time /= divider;
}

const CTime CTime::operator *= (unsigned multiplier)
{
	return m_time *= multiplier;
}

const CTime CTime::operator /= (unsigned divider)
{
	return m_time /= divider;
}

const bool CTime::operator == (const CTime time)
{
	return (m_time == time.GetTimeStamp()) ? true : false;
}

const bool CTime::operator != (const CTime time)
{
	return (m_time != time.GetTimeStamp()) ? true : false;
}

const bool CTime::operator > (const CTime time)
{
	return (m_time > time.GetTimeStamp()) ? true : false;
}

const bool CTime::operator < (const CTime time)
{
	return (m_time < time.GetTimeStamp()) ? true : false;
}

const bool CTime::operator >= (const CTime time)
{
	return (m_time >= time.GetTimeStamp()) ? true : false;
}

const bool CTime::operator <= (const CTime time)
{
	return (m_time <= time.GetTimeStamp()) ? true : false;
}

std::ostream& operator << (std::ostream& stream, const CTime & time)
{
	if (time.IsValid())
	{
		stream << time.GetHours() << ':' << time.GetMinutes() << ':' << time.GetSeconds();
		return stream;
	}
	else
	{
		stream << "INVALID";
		return stream;
	}
	return stream;
};

std::istream& operator >> (std::istream& stream, const CTime & time)
{
    unsigned hours, minutes, seconds;
    stream >> hours >> minutes >> seconds;
    CTime time2(hours, minutes, seconds);
    if (time2.IsValid())
    {
        return stream;
    }
    return stream;
};