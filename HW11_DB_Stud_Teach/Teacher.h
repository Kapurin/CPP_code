#pragma once
#include "Human.h"



class Teacher :
	public Human
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
	virtual	void setWorkTime(int Experience);
	virtual void setMoney(double Salary);

	// функции-геттеры
	virtual int getWorkTime() const;
	virtual double getMoney() const;
};


