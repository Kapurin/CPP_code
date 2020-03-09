#pragma once
#include <string>


class Human
{

protected:
	std::string m_name;			// имя
	std::string m_secondName;	// фамилия
	std::string m_middleName;	// отчество
	int	m_yearBirth;			// год рождения
	int	m_workTime;				// курс/стаж
	double m_money;				// стипендия/ЗП
public:
	// конструктор
	Human();
	Human(std::string Name,
		std::string SecondName,
		std::string MiddleName,
		int YearBirth,
		int WorkTime,
		double Money
	);

	// деструктор
	~Human();


	// функции-сеттеры
	void setName(std::string Name);
	void setSecondName(std::string SecondName);
	void setMiddleName(std::string MiddleName);
	void setYearBirth(int YearBirth);
	virtual void setWorkTime(int WorkTime);
	virtual void setMoney(double Money);

	// функции-геттеры
	std::string getName() const;
	std::string getSecondName() const;
	std::string getMiddleName() const;
	int getYearBirth() const;
	virtual int getWorkTime() const;
	virtual double getMoney() const;

	// получение ФИО человека
	std::string getFullName() const;

};




 



