#include "Teacher.h"
#include <iostream>


// �����������
Teacher::Teacher() {}
Teacher::Teacher(std::string Name,
	std::string SecondName,
	std::string MiddleName,
	int YearBirth,
	int Experience,
	double Salary)
{
	m_name = Name;
	m_secondName = SecondName;
	m_middleName = MiddleName;
	m_yearBirth = YearBirth;
	m_experience = Experience;
	m_salary = Salary;
}

// ����������
Teacher::~Teacher() {}


// �������-�������
void Teacher::setExperience(int Experience)
{
	m_experience = Experience;
}

void Teacher::setSalary(double Salary)
{
	m_salary = Salary;
}


// �������-�������
int Teacher::getExperience() const
{
	return m_experience;
}

double Teacher::getSalary() const
{
	return m_salary;
}

// ����������� ���� �������
const char* Teacher::getType()
{
	return "Teacher";
}


