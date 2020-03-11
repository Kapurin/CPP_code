#include <iostream>
#include <fstream>
#include <string>

#include "service_func.h"


// ��������� �������

// ������� ���������� �� (c ���������� ��� � �����)
//void FillHumAllDB(Human **Arr, int Size, int FillType)
//{
//	std::string Name = "";			// ���
//	std::string SecondName = "";	// �������
//	std::string MiddleName = "";	// ��������
//	int	YearBirth = 0;				// ��� ��������
//	int	WorkTime = 0;				// ����/����
//	double Money = 0.0;				// ���������/��
//	int	HumanType = 0;				// �������/������������� ("1" - �������; "2" - �������������)
//
//	// ���������� � ����������
//	if (FillType == 1)
//	{
//		for (int i = 0; i < Size; i++)
//		{
//			std::cout << "�������� ������ �������� (""1"" - �������; ""2"" - �������������): ";
//			std::cin >> HumanType;
//
//			// �������
//			if (HumanType == 1)
//			{
//				std::cout << "������� ���������� � ��������: " << std::endl;
//				std::cout << "������� ���: ";
//				std::cin >> Name;
//
//				std::cout << "������� �������: ";
//				std::cin >> SecondName;
//
//				std::cout << "������� ��������: ";
//				std::cin >> MiddleName;
//
//				std::cout << "������� ��� ��������: ";
//				std::cin >> YearBirth;
//
//				std::cout << "������� ����: ";
//				std::cin >> WorkTime;
//
//				std::cout << "������� ���������: ";
//				std::cin >> Money;
//				Student S1(Name, SecondName, MiddleName, YearBirth, WorkTime, Money);
//				Arr[i] = &S1;
//				std::cout << std::endl << std::endl;
//			}
//			// �������������
//			else if (HumanType == 2)
//			{
//				std::cout << "������� ���������� � �������������: " << std::endl;
//				std::cout << "������� ���: ";
//				std::cin >> Name;
//
//				std::cout << "������� �������: ";
//				std::cin >> SecondName;
//
//				std::cout << "������� ��������: ";
//				std::cin >> MiddleName;
//
//				std::cout << "������� ��� ��������: ";
//				std::cin >> YearBirth;
//
//				std::cout << "������� ����: ";
//				std::cin >> WorkTime;
//
//				std::cout << "������� ��������: ";
//				std::cin >> Money;
//				Teacher T1(Name, SecondName, MiddleName, YearBirth, WorkTime, Money);
//				Arr[i] = &T1;
//				std::cout << std::endl << std::endl;
//			}
//		}
//	}
//	// ���������� � �����
//	else if (FillType == 2)
//	{
//		std::ifstream fin("DB_Stud_Teach.txt");			// �������� ����� � ��
//		if (!fin.is_open())								// �������� ��� ���� ��������
//		{
//			std::cout << "\n���� �� ����� ���� ������!\n";
//			system("pause");
//		}
//		else
//		{
//			for (int i = 0; i < Size; i++)
//			{
//				fin >> HumanType;
//				fin >> Name;
//				fin >> SecondName;
//				fin >> MiddleName;
//				fin >> YearBirth;
//				fin >> WorkTime;
//				fin >> Money;
//
//				// �������
//				if (HumanType == 1)
//				{
//					Student S1(Name, SecondName, MiddleName, YearBirth, WorkTime, Money);
//					Arr[i] = &S1;
//				}
//				// �������������
//				else if (HumanType == 2)
//				{
//					Teacher T1(Name, SecondName, MiddleName, YearBirth, WorkTime, Money);
//					Arr[i] = &T1;
//				}
//			}
//			fin.close();								// �������� ����� � ��
//			std::cout << "\n���� �������� �������!\n";
//			system("pause");
//		}
//	}
//}


// ������� ������ ������� ��� � ������� ����, ��� � ��
void PrintHumFullName(Human **Arr, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		std::cout << "�.�.�.: " << Arr[i]->getFullName() << std::endl;
		if (Arr[i]->getType() == "Student")
			std::cout << "������: �������" << std::endl << std::endl;
		else if (Arr[i]->getType() == "Teacher")
			std::cout << "������: �������������" << std::endl << std::endl;
	}
}


// ������� ���������� ��������� �� ������� 
void SortStudSecondName(Human **Arr, int Size)
{
	int Num1 = -1, Num2 = -1;
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			if (Arr[j]->getType() == "Student")
			{
				if (Num1 < 0)
				{
					Num1 = j;
				}
				else if (Num1 >= 0)
				{
					Num2 = j;
				}

				// ����� ��������� ���������
				if ((Num1 >= 0) && (Num2 >= 0) && ((Arr[Num2]->getSecondName()) < (Arr[Num1]->getSecondName())))
				{
					Human *temp = new Human;
					temp = Arr[Num2];
					Arr[Num2] = Arr[Num1];
					Arr[Num1] = temp;
					Num1 = Num2;
					Num2 = -1;
				}
				else if ((Num1 >= 0) && (Num2 >= 0))
					Num1 = Num2;
					Num2 = -1;
			}
		}
		Num1 = -1;
		Num2 = -1;
	}

	// ����� ��������������� �� ������� ���������  
	for (int i = 0; i < Size; i++)
	{
		if (Arr[i]->getType() == "Student")
		{
			std::cout << "�������: " << Arr[i]->getSecondName() << std::endl;
			std::cout << "���: " << Arr[i]->getName() << std::endl;
			std::cout << std::endl;
		}
	}
}


// ������� ���������� �������������� �� ������� 
void SortTeachSecondName(Human **Arr, int Size)
{
	int Num1 = -1, Num2 = -1;

	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			if (Arr[j]->getType() == "Teacher")
			{
				if (Num1 < 0)
				{
					Num1 = j;
				}
				else if (Num1 >= 0)
				{
					Num2 = j;
				}

				// ����� ��������� ���������
				if ((Num1 >= 0) && (Num2 >= 0) && ((Arr[Num2]->getSecondName()) < (Arr[Num1]->getSecondName())))
				{
					Human* temp = new Human;
					temp = Arr[Num2];
					Arr[Num2] = Arr[Num1];
					Arr[Num1] = temp;
					Num1 = Num2;
					Num2 = -1;
				}
				else if ((Num1 >= 0) && (Num2 >= 0))
					Num1 = Num2;
				Num2 = -1;
			}
		}
		Num1 = -1;
		Num2 = -1;
	}

	// ����� ��������������� �� ������� ��������������  
	for (int i = 0; i < Size; i++)
	{
		if (Arr[i]->getType() == "Teacher")
		{
			std::cout << "�������: " << Arr[i]->getSecondName() << std::endl;
			std::cout << "���: " << Arr[i]->getName() << std::endl;
			std::cout << std::endl;
		}
	}
}


