#pragma once
#include <string>


class Human
{

protected:
	std::string m_name;			// имя
	std::string m_secondName;	// фамилия
	std::string m_middleName;	// отчество
	int	m_yearBirth;			// год рождения
public:
	// конструктор
	Human();
	Human(std::string Name,
		std::string SecondName,
		std::string MiddleName,
		int YearBirth);

	// деструктор
	~Human();


	// функции-сеттеры
	void setName(std::string Name);
	void setSecondName(std::string SecondName);
	void setMiddleName(std::string MiddleName);
	void setYearBirth(int YearBirth);


	// функции-геттеры
	std::string getName() const;
	std::string getSecondName() const;
	std::string getMiddleName() const;
	int getYearBirth() const;

	// возвращение типа объекта
	virtual const char* getType();

	// получение ФИО человека
	std::string getFullName();

};




 



