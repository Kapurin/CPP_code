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
	void setCourse(int Course);
	void setScholarship(double Scholarship);

	// функции-геттеры
	int getCourse() const;
	double getScholarship() const;

	// возвращение типа объекта
	virtual const char* getType();
};

