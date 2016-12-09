// ���������� ����� �����, ���������� ����������� ����� (0-23), ����� (0-59) � 
// ������ (0-59)
class CTime
{
public:
	// �������������� ����� �������� ����������� �����, ����� � ������
	CTime(unsigned hours, unsigned minutes, unsigned seconds = 0);

	// �������������� ����� ����������� ������ ����� ��������
	CTime(unsigned timeStamp = 0);

	// ���������� ���������� �����
	unsigned GetHours()const;

	// ���������� ���������� �����
	unsigned GetMinutes()const;

	// ���������� ���������� ������
	unsigned GetSeconds()const;

	unsigned GetTimeStamp()const;

	// ���������� ���������� � ������������ �������.
	// ��������, ����� ������ ������������ CTime time(99, 32, 83);
	//	����� time.IsValid() ������ ���������� false
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