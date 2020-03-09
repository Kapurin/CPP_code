#include "Human.h"
#include <iostream>



// конструктор
Human::Human() {}
Human::Human(std::string Name,
	std::string SecondName,
	std::string MiddleName,
	int YearBirth,
	int WorkTime,
	double Money
)
{
	m_name = Name;
	m_secondName = SecondName;
	m_middleName = MiddleName;
	m_yearBirth = YearBirth;
	m_workTime = WorkTime;
	m_money = Money;
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

void Human::setWorkTime(int WorkTime)
{
	m_workTime = WorkTime;
}

void Human::setMoney(double Money)
{
	m_money = Money;
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

int Human::getWorkTime() const
{
	return m_workTime;
}

double Human::getMoney() const
{
	return m_money;
}



// получение ФИО человека
std::string Human::getFullName() const
{
	return m_secondName + " " + m_name + " "+ m_middleName;
}




