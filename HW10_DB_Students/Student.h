#pragma once
#include <string>


class Student
{
private:
	std::string m_name;			// имя
	std::string m_secondName;	// фамилия
	int	m_yearBirth;			// год рождения
	int	m_yearReceipt;			// год поступления
	double m_scholarship;		// стипендия
	int	m_budCon;				// бюджет/контракт ("1" - бюджет; "2" - контракт)

public:
	// конструктор
	Student();
	Student(std::string  Name,
		std::string  SecondName,
		int YearBirth,
		int YearReceipt,
		double Scholarship,
		int BudCon);

	// функции-сеттеры
	void setName(std::string  Name);
	void setSecondName(std::string  SecondName);
	void setYearBirth(int YearBirth);
	void setYearReceipt(int YearReceipt);
	void setScholarship(double Scholarship);
	void setBudCon(int BudCon);

	// функции-геттеры
	std::string getName() const;
	std::string getSecondName() const;
	int getYearBirth() const;
	int getYearReceipt() const;
	double getScholarship() const;
	int getBudCon() const;

};


// перегрузка оператора "<" 
bool operator<(const Student &a, const Student &b);


// служебные функции

// функция вывода студентов которые на бюджете
void PrintStudBud(Student *Arr, int Size);

// функция вывода студентов которые поступили в N-м году 
void PrintStudReceipt(Student *Arr, int Size, int nYear);

// функция вывода имени, фамилии, года рождения студента
void PrintStudName(Student *Arr, int Size);

// функция сортировки студентов по возрасту 
void SortStudAge(Student *Arr, const int Size);

// функция заполнения БД студентов (c клавиатуры или с файла)
void FillStudAllDB(Student *Arr, int Size, int FillType);

// функция вывода всей БД студентов 
void PrintStudAllDB(Student *Arr, int Size);


