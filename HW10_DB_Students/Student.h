#pragma once
#include <string>


class Student
{
private:
	std::string m_name;			// ���
	std::string m_secondName;	// �������
	int	m_yearBirth;			// ��� ��������
	int	m_yearReceipt;			// ��� �����������
	double m_scholarship;		// ���������
	int	m_budCon;				// ������/�������� ("1" - ������; "2" - ��������)

public:
	// �����������
	Student();
	Student(std::string  Name,
		std::string  SecondName,
		int YearBirth,
		int YearReceipt,
		double Scholarship,
		int BudCon);

	// �������-�������
	void setName(std::string  Name);
	void setSecondName(std::string  SecondName);
	void setYearBirth(int YearBirth);
	void setYearReceipt(int YearReceipt);
	void setScholarship(double Scholarship);
	void setBudCon(int BudCon);

	// �������-�������
	std::string getName() const;
	std::string getSecondName() const;
	int getYearBirth() const;
	int getYearReceipt() const;
	double getScholarship() const;
	int getBudCon() const;

};


// ���������� ��������� "<" 
bool operator<(const Student &a, const Student &b);


// ��������� �������

// ������� ������ ��������� ������� �� �������
void PrintStudBud(Student *Arr, int Size);

// ������� ������ ��������� ������� ��������� � N-� ���� 
void PrintStudReceipt(Student *Arr, int Size, int nYear);

// ������� ������ �����, �������, ���� �������� ��������
void PrintStudName(Student *Arr, int Size);

// ������� ���������� ��������� �� �������� 
void SortStudAge(Student *Arr, const int Size);

// ������� ���������� �� ��������� (c ���������� ��� � �����)
void FillStudAllDB(Student *Arr, int Size, int FillType);

// ������� ������ ���� �� ��������� 
void PrintStudAllDB(Student *Arr, int Size);


