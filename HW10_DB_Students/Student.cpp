#include "Student.h"
#include <iostream>
#include <fstream>

// конструктор
Student::Student() {}
Student::Student(std::string  Name,
	std::string SecondName,
	int YearBirth,
	int YearReceipt,
	double Scholarship,
	int BudCon)
{
	m_name = Name;
	m_secondName = SecondName;
	m_yearBirth = YearBirth;
	m_yearReceipt = YearReceipt;
	m_scholarship = Scholarship;
	m_budCon = BudCon;
}


// функции-сеттеры
void Student::setName(std::string  Name)
{
	m_name = Name;
}


void Student::setSecondName(std::string  SecondName)
{
	m_secondName = SecondName;
}


void Student::setYearBirth(int YearBirth)
{
	m_yearBirth = YearBirth;
}


void Student::setYearReceipt(int YearReceipt)
{
	m_yearReceipt = YearReceipt;
}


void Student::setScholarship(double Scholarship)
{
	m_scholarship = Scholarship;
}


void Student::setBudCon(int BudCon)
{
	m_budCon = BudCon;
}



// функции-геттеры
std::string  Student::getName() const
{
	return m_name;
}


std::string  Student::getSecondName() const
{
	return m_secondName;
}


int Student::getYearBirth() const
{
	return m_yearBirth;
}


int Student::getYearReceipt() const
{
	return m_yearReceipt;
}


double Student::getScholarship() const
{
	return m_scholarship;
}


int Student::getBudCon() const
{
	return m_budCon;
}


// перегрузка оператора "<" 
bool operator<(const Student &a, const Student &b)
{
	return a.getYearBirth() < b.getYearBirth();
}



// служебные функции

// функция вывода студентов которые на бюджете
void PrintStudBud(Student *Arr, int Size)
{
	int Num = 0;
	for (int i = 0; i < Size; i++)
	{
		if (Arr[i].getBudCon() == 1)
		{
			std::cout << "Имя: " << Arr[i].getName() << std::endl;
			std::cout << "Фамилия: " << Arr[i].getSecondName() << std::endl;
			std::cout << std::endl;
			Num++;
		}
	}
	if (Num == 0)
		std::cout << "\nНет студентов на бюджете!\n" << std::endl;
}


// функция вывода студентов которые поступили в N-м году 
void PrintStudReceipt(Student *Arr, int Size, int nYear)
{
	int Num = 0;
	for (int i = 0; i < Size; i++)
	{
		if (Arr[i].getYearReceipt() == nYear)
		{
			std::cout << "Имя: " << Arr[i].getName() << std::endl;
			std::cout << "Фамилия: " << Arr[i].getSecondName() << std::endl;
			std::cout << std::endl;
			Num++;
		}
	}
	if (Num == 0)
		std::cout << "\nНет студентов поступивших в " << nYear << " году!\n" << std::endl;
}



// функция вывода имени, фамилии, года рождения студента
void PrintStudName(Student *Arr, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		std::cout << "Информация о студенте №" << i + 1 << std::endl;
		std::cout << "Имя: " << Arr[i].getName() << std::endl;
		std::cout << "Фамилия: " << Arr[i].getSecondName() << std::endl;
		std::cout << "Год рождения: " << Arr[i].getYearBirth() << std::endl;
		std::cout << std::endl;
	}
}



// функция сортировки студентов по возрасту 
// (если год рождения одинаковый – смотрим на фамилию)
void SortStudAge(Student *Arr, int Size)
{
	for (int i = 0; i < Size - 1; i++)
	{
		for (int j = 0; j < Size - 1; j++)
		{
			if (Arr[j + 1].getYearBirth() != Arr[j].getYearBirth())
			{				
				if (Arr[j + 1] < Arr[j])
				{
					Student temp;
					temp = Arr[j];
					Arr[j] = Arr[j + 1];
					Arr[j + 1] = temp;
				}
			}
			else
			{
				if (Arr[j + 1].getSecondName() < Arr[j].getSecondName())
				{
					Student temp;
					temp = Arr[j];
					Arr[j] = Arr[j + 1];
					Arr[j + 1] = temp;
				}
			}
		}
	}
}



// функция заполнения БД студентов (c клавиатуры или с файла)
void FillStudAllDB(Student *Arr, int Size, int FillType)
{
	std::string Name;				// имя
	std::string SecondName;			// фамилия
	int	YearBirth = 0;				// год рождения
	int	YearReceipt = 0;			// год поступления
	double Scholarship = 0.0;		// стипендия
	int	BudCon = 0;					// бюджет/контракт ("1" - бюджет; "2" - контракт)

	// заполнение с клавиатуры
	if (FillType == 1)
	{
		for (int i = 0; i < Size; i++)
		{
			std::cout << "Введите информацию о студенте №" << i + 1 << std::endl;
			std::cout << "Введите имя: ";
			std::cin >> Name;
			Arr[i].setName(Name);

			std::cout << "Введите фамилию: ";
			std::cin >> SecondName;
			Arr[i].setSecondName(SecondName);

			std::cout << "Введите год рождения: ";
			std::cin >> YearBirth;
			Arr[i].setYearBirth(YearBirth);

			std::cout << "Введите год поступления: ";
			std::cin >> YearReceipt;
			Arr[i].setYearReceipt(YearReceipt);

			std::cout << "Введите стипендию: ";
			std::cin >> Scholarship;
			Arr[i].setScholarship(Scholarship);

			std::cout << "Введите форму обучения (""1"" - бюджет; ""2"" - контракт): ";
			std::cin >> BudCon;
			Arr[i].setBudCon(BudCon);
			std::cout << std::endl << std::endl;
		}
	}
	// заполнение с файла
	else if (FillType == 2)
	{
		std::ifstream fin("DB_Stud.txt");				// открытие файла с БД
		if (!fin.is_open())								// проверка что файл открылся
		{
			std::cout << "\nФайл не может быть открыт!\n";
			system("pause");
		}
		else
		{
			for (int i = 0; i < Size; i++)
			{
				fin >> Name;
				Arr[i].setName(Name);

				fin >> SecondName;
				Arr[i].setSecondName(SecondName);

				fin >> YearBirth;
				Arr[i].setYearBirth(YearBirth);

				fin >> YearReceipt;
				Arr[i].setYearReceipt(YearReceipt);

				fin >> Scholarship;
				Arr[i].setScholarship(Scholarship);

				fin >> BudCon;
				Arr[i].setBudCon(BudCon);
			}
			fin.close();								// закрытие файла с БД
			std::cout << "\nФайл прочитан успешно!\n";
			system("pause");
		}
	}
}


// функция вывода всей БД студентов 
void PrintStudAllDB(Student *Arr, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		std::cout << "Информация о студенте №" << i + 1 << std::endl;
		std::cout << "Имя: " << Arr[i].getName() << std::endl;
		std::cout << "Фамилия: " << Arr[i].getSecondName() << std::endl;
		std::cout << "Год рождения: " << Arr[i].getYearBirth() << std::endl;
		std::cout << "Год поступления: " << Arr[i].getYearReceipt() << std::endl;
		std::cout << "Стипендия: " << Arr[i].getScholarship() << std::endl;
		std::cout << "Форма обучения: ";
		if (Arr[i].getBudCon() == 1)
			std::cout << "бюджет" << std::endl << std::endl;
		else if (Arr[i].getBudCon() == 2)
			std::cout << "контракт" << std::endl << std::endl;
	}
}
