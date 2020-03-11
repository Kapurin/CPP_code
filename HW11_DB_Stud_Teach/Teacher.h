#pragma once
#include "Human.h"



class Teacher : public Human
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
	void setExperience(int Experience);
	void setSalary(double Salary);

	// �������-�������
	int getExperience() const;
	double getSalary() const;

	// ����������� ���� �������
	virtual const char* getType();
};


