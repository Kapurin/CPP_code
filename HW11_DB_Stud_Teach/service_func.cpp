#include <iostream>
#include <fstream>
#include <string>
#include "service_func.h"
#include "Student.h"
#include "Teacher.h"


// служебные функции

// функция заполнения БД (c клавиатуры или с файла)
void FillHumAllDB(Human *Arr, int Size, int FillType)
{
	std::string Name = "";			// имя
	std::string SecondName = "";		// фамилия
	std::string MiddleName = "";		// отчество
	int	YearBirth = 0;			// год рождения
	int	WorkTime = 0;			// курс/стаж
	double Money = 0.0;			// стипендия/ЗП
	int	HumanType = 0;			// студент/преподаватель ("1" - студент; "2" - преподаватель)

	// заполнение с клавиатуры
	if (FillType == 1)
	{
		for (int i = 0; i < Size; i++)
		{
			std::cout << "Выберите статус человека (""1"" - студент; ""2"" - преподаватель): ";
			std::cin >> HumanType;

			// студент
			if (HumanType == 1)
			{
				std::cout << "Введите информацию о студенте: " << std::endl;
				std::cout << "Введите имя: ";
				std::cin >> Name;

				std::cout << "Введите фамилию: ";
				std::cin >> SecondName;

				std::cout << "Введите отчество: ";
				std::cin >> MiddleName;

				std::cout << "Введите год рождения: ";
				std::cin >> YearBirth;

				std::cout << "Введите курс: ";
				std::cin >> WorkTime;

				std::cout << "Введите стипендию: ";
				std::cin >> Money;
				Student S1(Name, SecondName, MiddleName, YearBirth, WorkTime, Money);
				Arr[i] = S1;
				std::cout << std::endl << std::endl;
			}
			// преподаватель
			else if (HumanType == 2)
			{
				std::cout << "Введите информацию о преподавателе: " << std::endl;
				std::cout << "Введите имя: ";
				std::cin >> Name;

				std::cout << "Введите фамилию: ";
				std::cin >> SecondName;

				std::cout << "Введите отчество: ";
				std::cin >> MiddleName;

				std::cout << "Введите год рождения: ";
				std::cin >> YearBirth;

				std::cout << "Введите стаж: ";
				std::cin >> WorkTime;

				std::cout << "Введите зарплату: ";
				std::cin >> Money;
				Teacher T1(Name, SecondName, MiddleName, YearBirth, WorkTime, Money);
				Arr[i] = T1;
				std::cout << std::endl << std::endl;
			}
		}
	}
	// заполнение с файла
	else if (FillType == 2)
	{
		std::ifstream fin("DB_Stud_Teach.txt");			// открытие файла с БД
		if (!fin.is_open())								// проверка что файл открылся
		{
			std::cout << "\nФайл не может быть открыт!\n";
			system("pause");
		}
		else
		{
			for (int i = 0; i < Size; i++)
			{
				fin >> HumanType;
				fin >> Name;
				fin >> SecondName;
				fin >> MiddleName;
				fin >> YearBirth;
				fin >> WorkTime;
				fin >> Money;

				// студент
				if (HumanType == 1)
				{
					Student S1(Name, SecondName, MiddleName, YearBirth, WorkTime, Money);
					Arr[i] = S1;
				}
				// преподаватель
				else if (HumanType == 2)
				{
					Teacher T1(Name, SecondName, MiddleName, YearBirth, WorkTime, Money);
					Arr[i] = T1;
				}
			}
			fin.close();								// закрытие файла с БД
			std::cout << "\nФайл прочитан успешно!\n";
			system("pause");
		}
	}
}


// функция вывода полного ФИО всех, кто в БД
void PrintHumFullName(Human *Arr, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		std::cout << "Ф.И.О.: " << Arr[i].getFullName() << std::endl;
	}
}

// функция вывода фамилии, имени всех, кто в БД
void PrintHumName(Human *Arr, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		std::cout << "Фамилия: " << Arr[i].getSecondName() << std::endl;
		std::cout << "Имя: " << Arr[i].getName() << std::endl;
		std::cout << std::endl;
	}
}


// функция сортировки студентов/преподавателей по фамилии 
void SortHumSecondName(Human *Arr, int Size)
{
	for (int i = 0; i < Size - 1; i++)
	{
		for (int j = 0; j < Size - 1; j++)
		{
			if (Arr[j + 1].getSecondName() < Arr[j].getSecondName())
			{
				Human temp;
				temp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = temp;
			}
		}
	}
}



