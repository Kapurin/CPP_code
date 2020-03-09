#pragma once
#include "Human.h"



class Student :public Human
{
private:
	int	m_course;			// ����
	double m_scholarship;	// ���������

public:
	// �����������
	Student();
	Student(std::string Name,
		std::string SecondName,
		std::string MiddleName,
		int YearBirth,
		int Course,
		double Scholarship);

	// ����������
	~Student();


	// �������-�������
	virtual void setWorkTime(int Course);
	virtual void setMoney(double Scholarship);

	// �������-�������
	virtual int getWorkTime() const;
	virtual double getMoney() const;
};

