#include "Human.h"
#include <iostream>



// конструктор
Human::Human() {}
Human::Human(std::string Name,
	std::string SecondName,
	std::string MiddleName,
	int YearBirth)
{
	m_name = Name;
	m_secondName = SecondName;
	m_middleName = MiddleName;
	m_yearBirth = YearBirth;
}

// деструктор
Human::~Human() {}


// функции-сеттеры
void Human::setName(std::string Name)
{
	m_name = Name;
}

void Human::setSecondName(std::string SecondName)
{
	m_secondName = SecondName;
}

void Human::setMiddleName(std::string MiddleName)
{
	m_middleName = MiddleName;
}

void Human::setYearBirth(int YearBirth)
{
	m_yearBirth = YearBirth;
}




// функции-геттеры
std::string Human::getName() const
{
	return m_name;
}

std::string Human::getSecondName() const
{
	return m_secondName;
}

std::string Human::getMiddleName() const
{
	return m_middleName;
}

int Human::getYearBirth() const
{
	return m_yearBirth;
}

// возвращение типа объекта
const char* Human::getType()
{
	return "Human";
}



// получение ФИО человека
std::string Human::getFullName()
{
	return (m_secondName + " " + m_name + " " + m_middleName);
}




