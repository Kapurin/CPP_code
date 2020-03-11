/* Программа реализует базу данных студентов и преподавателей.
* Данные принимает от пользователя или читает с файла.
* (реализация через классы с наследованием)
*/

#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <string>

#include "Student.h"
#include "Teacher.h"
#include "Human.h"
#include "service_func.h"

using namespace std;



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "=== Программа реализует базу данных студентов и преподавателей ===\n\n";

	int N = 0;			// кол-во человек в БД
	int Choice = 0;		// переменная выбора действия в меню
	int FillType = 0;	// способ заполнения БД (клавиатура или файл)

	string Name = "";				// имя
	string SecondName = "";			// фамилия
	string MiddleName = "";			// отчество
	int	YearBirth = 0;				// год рождения
	int	WorkTime = 0;				// курс/стаж
	double Money = 0.0;				// стипендия/ЗП
	int	HumanType = 0;				// студент/преподаватель ("1" - студент; "2" - преподаватель)

	Human** Hums = nullptr;
	cout << "Введите размер базы данных: ";
	cin >> N;

	if (N > 0)
	{
		// выделение памяти под БД
		Hums = new Human*[N];

		cout << "Заполните базу данных.\n\n";
		cout << "Примечание 1: при заполнении с файла проверьте наличие файла БД, и кол-во человек в нем!\n";
		cout << "Примечание 2: по умолчанию в файле БД информация о 10 людях.\n";
		cout << "Выберите способ заполнения БД (""1""- с клавиатуры; ""2"" - с файла): \n";
		cin >> FillType;
		//FillHumAllDB(Hums, N, FillType);

		// заполнение с БД
		// заполнение с клавиатуры
		if (FillType == 1)
		{
			for (int i = 0; i < N; i++)
			{
				cout << "Выберите статус человека (""1"" - студент; ""2"" - преподаватель): ";
				cin >> HumanType;

				// студент
				if (HumanType == 1)
				{
					cout << "Введите информацию о студенте: " << endl;
					cout << "Введите имя: ";
					cin >> Name;

					cout << "Введите фамилию: ";
					cin >> SecondName;

					cout << "Введите отчество: ";
					cin >> MiddleName;

					cout << "Введите год рождения: ";
					cin >> YearBirth;

					cout << "Введите курс: ";
					cin >> WorkTime;

					cout << "Введите стипендию: ";
					cin >> Money;
					Hums[i] = new Student (Name, SecondName, MiddleName, YearBirth, WorkTime, Money);
					cout << endl << endl;
				}
				// преподаватель
				else if (HumanType == 2)
				{
					cout << "Введите информацию о преподавателе: " << endl;
					cout << "Введите имя: ";
					cin >> Name;

					cout << "Введите фамилию: ";
					cin >> SecondName;

					cout << "Введите отчество: ";
					cin >> MiddleName;

					cout << "Введите год рождения: ";
					cin >> YearBirth;

					cout << "Введите стаж: ";
					cin >> WorkTime;

					cout << "Введите зарплату: ";
					cin >> Money;
					
					Hums[i] = new Teacher (Name, SecondName, MiddleName, YearBirth, WorkTime, Money);
					cout << endl << endl;
				}
			}
		}
		// заполнение с файла
		else if (FillType == 2)
		{
			ifstream fin("DB_Stud_Teach.txt");			// открытие файла с БД
			if (!fin.is_open())								// проверка что файл открылся
			{
				cout << "\nФайл не может быть открыт!\n";
				system("pause");
			}
			else
			{
				for (int i = 0; i < N; i++)
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
						Hums[i] = new Student(Name, SecondName, MiddleName, YearBirth, WorkTime, Money);
					// преподаватель
					else if (HumanType == 2)
						Hums[i] = new Teacher(Name, SecondName, MiddleName, YearBirth, WorkTime, Money);
				}
				fin.close();								// закрытие файла с БД
				cout << "\nФайл прочитан успешно!\n";
				system("pause");
			}
		}
	
		// очистка экрана
		system("cls");

		cout << "\n\nБаза данных заполнена.\n";

		do
		{
			// меню программы
			cout << "Выберите нужное действие для БД: \n\n";
			cout << "1 - вывод полного ФИО всех, кто в БД;\n";
			cout << "2 - вывод студентов отсортированных по фамилии; \n";
			cout << "3 - вывод преподавателей отсортированных по фамилии; \n";
			cout << "0 - завершение работы программы\n";
			cin >> Choice;


			switch (Choice)
			{
			case 0: // завершение работы программы
				break;
			case 1: // вывод полного ФИО всех, кто в БД
				cout << "Информация о всех, кто в БД: \n";
				PrintHumFullName(Hums, N);
				break;
			case 2:	// вывод студентов отсортированных по фамилии
				cout << "Студенты отсортированные по фамилии: \n";
				SortStudSecondName(Hums, N);
				break;
			case 3:	// вывод преподавателей отсортированных по фамилии
				cout << "Преподаватели отсортированные по фамилии: \n";
				SortTeachSecondName(Hums, N);
				break;
			default:
				cout << "\n\nНеправильный ввод! Повторите попытку.\n\n";
			}

			if (Choice != 0)
			{
				system("pause");
				system("cls");
			}
		} while (Choice != 0);

		// освобождение памяти выделенной под БД
		delete[] Hums;
		Hums = nullptr;
	}
	else
	{
		cout << "\n\nНеправильный ввод! Повторите попытку.\n\n";
		system("pause");
	}
	return 0;
}





