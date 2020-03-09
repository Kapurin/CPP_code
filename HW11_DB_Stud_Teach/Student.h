#pragma once
#include "Human.h"



class Student :public Human
{
private:
	int	m_course;			// курс
	double m_scholarship;	// стипендия

public:
	// конструктор
	Student();
	Student(std::string Name,
		std::string SecondName,
		std::string MiddleName,
		int YearBirth,
		int Course,
		double Scholarship);

	// деструктор
	~Student();


	// функции-сеттеры
	virtual void setWorkTime(int Course);
	virtual void setMoney(double Scholarship);

	// функции-геттеры
	virtual int getWorkTime() const;
	virtual double getMoney() const;
};

