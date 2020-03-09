#include "Student.h"
#include <iostream>


// конструктор
Student::Student() {}
Student::Student(std::string Name,
	std::string SecondName,
	std::string MiddleName,
	int YearBirth,
	int Course,
	double Scholarship)
{
	m_name = Name;
	m_secondName = SecondName;
	m_middleName = MiddleName;
	m_yearBirth = YearBirth;
	m_course = Course;
	m_scholarship = Scholarship;
}

// деструктор
Student::~Student() {}


// функции-сеттеры
void Student::setWorkTime(int Course)
{
	m_course = Course;
}

void Student::setMoney(double Scholarship)
{
	m_scholarship = Scholarship;
}


// функции-геттеры
int Student::getWorkTime() const
{
	return m_course;
}

double Student::getMoney() const
{
	return m_scholarship;
}



