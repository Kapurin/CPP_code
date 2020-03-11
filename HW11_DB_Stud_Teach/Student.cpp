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
void Student::setCourse(int Course)
{
	m_course = Course;
}

void Student::setScholarship(double Scholarship)
{
	m_scholarship = Scholarship;
}


// функции-геттеры
int Student::getCourse() const
{
	return m_course;
}

double Student::getScholarship() const
{
	return m_scholarship;
}

// возвращение типа объекта
const char* Student::getType()
{
	return "Student";
}
