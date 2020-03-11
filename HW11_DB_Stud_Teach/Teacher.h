#pragma once
#include "Human.h"



class Teacher : public Human
{
private:
	int	m_experience;	// стаж
	double m_salary;	// зарплата

public:
	// конструктор
	Teacher();
	Teacher(std::string Name,
		std::string SecondName,
		std::string MiddleName,
		int YearBirth,
		int Experience,
		double Salary);

	// деструктор
	~Teacher();


	// функции-сеттеры
	void setExperience(int Experience);
	void setSalary(double Salary);

	// функции-геттеры
	int getExperience() const;
	double getSalary() const;

	// возвращение типа объекта
	virtual const char* getType();
};


