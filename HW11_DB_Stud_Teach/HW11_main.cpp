/* ��������� ��������� ���� ������ ��������� � ��������������.
* ������ ��������� �� ������������ ��� ������ � �����.
* (���������� ����� ������ � �������������)
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

	cout << "=== ��������� ��������� ���� ������ ��������� � �������������� ===\n\n";

	int N = 0;			// ���-�� ������� � ��
	int Choice = 0;		// ���������� ������ �������� � ����
	int FillType = 0;	// ������ ���������� �� (���������� ��� ����)

	string Name = "";				// ���
	string SecondName = "";			// �������
	string MiddleName = "";			// ��������
	int	YearBirth = 0;				// ��� ��������
	int	WorkTime = 0;				// ����/����
	double Money = 0.0;				// ���������/��
	int	HumanType = 0;				// �������/������������� ("1" - �������; "2" - �������������)

	Human** Hums = nullptr;
	cout << "������� ������ ���� ������: ";
	cin >> N;

	if (N > 0)
	{
		// ��������� ������ ��� ��
		Hums = new Human*[N];

		cout << "��������� ���� ������.\n\n";
		cout << "���������� 1: ��� ���������� � ����� ��������� ������� ����� ��, � ���-�� ������� � ���!\n";
		cout << "���������� 2: �� ��������� � ����� �� ���������� � 10 �����.\n";
		cout << "�������� ������ ���������� �� (""1""- � ����������; ""2"" - � �����): \n";
		cin >> FillType;
		//FillHumAllDB(Hums, N, FillType);

		// ���������� � ��
		// ���������� � ����������
		if (FillType == 1)
		{
			for (int i = 0; i < N; i++)
			{
				cout << "�������� ������ �������� (""1"" - �������; ""2"" - �������������): ";
				cin >> HumanType;

				// �������
				if (HumanType == 1)
				{
					cout << "������� ���������� � ��������: " << endl;
					cout << "������� ���: ";
					cin >> Name;

					cout << "������� �������: ";
					cin >> SecondName;

					cout << "������� ��������: ";
					cin >> MiddleName;

					cout << "������� ��� ��������: ";
					cin >> YearBirth;

					cout << "������� ����: ";
					cin >> WorkTime;

					cout << "������� ���������: ";
					cin >> Money;
					Hums[i] = new Student (Name, SecondName, MiddleName, YearBirth, WorkTime, Money);
					cout << endl << endl;
				}
				// �������������
				else if (HumanType == 2)
				{
					cout << "������� ���������� � �������������: " << endl;
					cout << "������� ���: ";
					cin >> Name;

					cout << "������� �������: ";
					cin >> SecondName;

					cout << "������� ��������: ";
					cin >> MiddleName;

					cout << "������� ��� ��������: ";
					cin >> YearBirth;

					cout << "������� ����: ";
					cin >> WorkTime;

					cout << "������� ��������: ";
					cin >> Money;
					
					Hums[i] = new Teacher (Name, SecondName, MiddleName, YearBirth, WorkTime, Money);
					cout << endl << endl;
				}
			}
		}
		// ���������� � �����
		else if (FillType == 2)
		{
			ifstream fin("DB_Stud_Teach.txt");			// �������� ����� � ��
			if (!fin.is_open())								// �������� ��� ���� ��������
			{
				cout << "\n���� �� ����� ���� ������!\n";
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

					// �������
					if (HumanType == 1)
						Hums[i] = new Student(Name, SecondName, MiddleName, YearBirth, WorkTime, Money);
					// �������������
					else if (HumanType == 2)
						Hums[i] = new Teacher(Name, SecondName, MiddleName, YearBirth, WorkTime, Money);
				}
				fin.close();								// �������� ����� � ��
				cout << "\n���� �������� �������!\n";
				system("pause");
			}
		}
	
		// ������� ������
		system("cls");

		cout << "\n\n���� ������ ���������.\n";

		do
		{
			// ���� ���������
			cout << "�������� ������ �������� ��� ��: \n\n";
			cout << "1 - ����� ������� ��� ����, ��� � ��;\n";
			cout << "2 - ����� ��������� ��������������� �� �������; \n";
			cout << "3 - ����� �������������� ��������������� �� �������; \n";
			cout << "0 - ���������� ������ ���������\n";
			cin >> Choice;


			switch (Choice)
			{
			case 0: // ���������� ������ ���������
				break;
			case 1: // ����� ������� ��� ����, ��� � ��
				cout << "���������� � ����, ��� � ��: \n";
				PrintHumFullName(Hums, N);
				break;
			case 2:	// ����� ��������� ��������������� �� �������
				cout << "�������� ��������������� �� �������: \n";
				SortStudSecondName(Hums, N);
				break;
			case 3:	// ����� �������������� ��������������� �� �������
				cout << "������������� ��������������� �� �������: \n";
				SortTeachSecondName(Hums, N);
				break;
			default:
				cout << "\n\n������������ ����! ��������� �������.\n\n";
			}

			if (Choice != 0)
			{
				system("pause");
				system("cls");
			}
		} while (Choice != 0);

		// ������������ ������ ���������� ��� ��
		delete[] Hums;
		Hums = nullptr;
	}
	else
	{
		cout << "\n\n������������ ����! ��������� �������.\n\n";
		system("pause");
	}
	return 0;
}





