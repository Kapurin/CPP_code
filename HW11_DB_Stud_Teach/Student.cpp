#include "Student.h"
#include <iostream>


// �����������
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

// ����������
Student::~Student() {}


// �������-�������
void Student::setWorkTime(int Course)
{
	m_course = Course;
}

void Student::setMoney(double Scholarship)
{
	m_scholarship = Scholarship;
}


// �������-�������
int Student::getWorkTime() const
{
	return m_course;
}

double Student::getMoney() const
{
	return m_scholarship;
}



