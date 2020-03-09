#pragma once
#include "Human.h"



class Teacher :
	public Human
{
private:
	int	m_experience;	// ����
	double m_salary;	// ��������

public:
	// �����������
	Teacher();
	Teacher(std::string Name,
		std::string SecondName,
		std::string MiddleName,
		int YearBirth,
		int Experience,
		double Salary);

	// ����������
	~Teacher();


	// �������-�������
	virtual	void setWorkTime(int Experience);
	virtual void setMoney(double Salary);

	// �������-�������
	virtual int getWorkTime() const;
	virtual double getMoney() const;
};


