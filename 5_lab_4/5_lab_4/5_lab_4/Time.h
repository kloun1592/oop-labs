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