#include "Teacher.h"
#include <iostream>


// конструктор
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

// деструктор
Teacher::~Teacher() {}


// функции-сеттеры
void Teacher::setExperience(int Experience)
{
	m_experience = Experience;
}

void Teacher::setSalary(double Salary)
{
	m_salary = Salary;
}


// функции-геттеры
int Teacher::getExperience() const
{
	return m_experience;
}

double Teacher::getSalary() const
{
	return m_salary;
}

// возвращение типа объекта
const char* Teacher::getType()
{
	return "Teacher";
}


