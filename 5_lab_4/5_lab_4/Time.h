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

	const CTime operator++();
	const CTime operator++(int);
	const CTime operator--();
	const CTime operator--(int);

	CTime const operator+(CTime const & time)const;

	CTime const operator-(CTime const & time) const;

	CTime & operator+=(CTime const & time);

	CTime & operator-=(CTime const & time);

	CTime const operator*(unsigned multiplier) const;

	CTime const operator/(unsigned multiplier) const;
	CTime & operator*=(CTime const & time);
	CTime & operator/=(CTime const & time);

	bool operator==(CTime const & time) const;

	bool operator!=(CTime const & time) const;
	bool operator>(CTime const & time) const;
	bool operator<(CTime const & time) const;
	bool operator>=(CTime const & time) const;
	bool operator<=(CTime const & time) const;
private:
	unsigned m_time;
	bool m_isTimeValid = true;
};

CTime const operator * (unsigned multiplier, CTime const& time);
std::ostream& operator << (std::ostream& stream, const CTime & time);
std::istream & operator >> (std::istream & stream, CTime & time);