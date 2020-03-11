#include "Human.h"
#include <iostream>



// �����������
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

// ����������
Human::~Human() {}


// �������-�������
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




// �������-�������
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

// ����������� ���� �������
const char* Human::getType()
{
	return "Human";
}



// ��������� ��� ��������
std::string Human::getFullName()
{
	return (m_secondName + " " + m_name + " " + m_middleName);
}




