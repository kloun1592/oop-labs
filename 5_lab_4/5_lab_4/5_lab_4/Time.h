// моделирует время суток, задаваемое количеством часов (0-23), минут (0-59) и 
// секунд (0-59)
class CTime
{
public:
	// инициализирует время заданным количеством часов, минут и секунд
	CTime(unsigned hours, unsigned minutes, unsigned seconds = 0);

	// инициализирует время количеством секунд после полуночи
	CTime(unsigned timeStamp = 0);

	// возвращает количество часов
	unsigned GetHours()const;

	// возвращает количество минут
	unsigned GetMinutes()const;

	// возвращает количество секунд
	unsigned GetSeconds()const;

	unsigned GetTimeStamp()const;

	// возвращает информацию о корректности времени.
	// Например, после вызова конструктора CTime time(99, 32, 83);
	//	метод time.IsValid() должен возвращать false
	bool IsValid()const;

	const CTime operator + (const CTime time);
	const CTime operator - (const CTime time);
	const CTime operator * (unsigned multiplier);
	const CTime operator / (unsigned divider);

	const CTime operator *= (unsigned multiplier);
	const CTime operator /= (unsigned divider);

	const CTime operator += (const CTime time);
	const CTime operator -= (const CTime time);

	const bool operator == (const CTime time);
	const bool operator != (const CTime time);
	const bool operator > (const CTime time);
	const bool operator < (const CTime time);
	const bool operator >= (const CTime time);
	const bool operator <= (const CTime time);
private:
	unsigned m_time;
	bool m_isTimeValid = true;
};

std::ostream& operator << (std::ostream& stream, const CTime & time);
std::istream& operator >> (std::istream& stream, const CTime & time);