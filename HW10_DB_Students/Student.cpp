#include "Student.h"
#include <iostream>
#include <fstream>

// �����������
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


// �������-�������
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



// �������-�������
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


// ���������� ��������� "<" 
bool operator<(const Student &a, const Student &b)
{
	return a.getYearBirth() < b.getYearBirth();
}



// ��������� �������

// ������� ������ ��������� ������� �� �������
void PrintStudBud(Student *Arr, int Size)
{
	int Num = 0;
	for (int i = 0; i < Size; i++)
	{
		if (Arr[i].getBudCon() == 1)
		{
			std::cout << "���: " << Arr[i].getName() << std::endl;
			std::cout << "�������: " << Arr[i].getSecondName() << std::endl;
			std::cout << std::endl;
			Num++;
		}
	}
	if (Num == 0)
		std::cout << "\n��� ��������� �� �������!\n" << std::endl;
}


// ������� ������ ��������� ������� ��������� � N-� ���� 
void PrintStudReceipt(Student *Arr, int Size, int nYear)
{
	int Num = 0;
	for (int i = 0; i < Size; i++)
	{
		if (Arr[i].getYearReceipt() == nYear)
		{
			std::cout << "���: " << Arr[i].getName() << std::endl;
			std::cout << "�������: " << Arr[i].getSecondName() << std::endl;
			std::cout << std::endl;
			Num++;
		}
	}
	if (Num == 0)
		std::cout << "\n��� ��������� ����������� � " << nYear << " ����!\n" << std::endl;
}



// ������� ������ �����, �������, ���� �������� ��������
void PrintStudName(Student *Arr, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		std::cout << "���������� � �������� �" << i + 1 << std::endl;
		std::cout << "���: " << Arr[i].getName() << std::endl;
		std::cout << "�������: " << Arr[i].getSecondName() << std::endl;
		std::cout << "��� ��������: " << Arr[i].getYearBirth() << std::endl;
		std::cout << std::endl;
	}
}



// ������� ���������� ��������� �� �������� 
// (���� ��� �������� ���������� � ������� �� �������)
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



// ������� ���������� �� ��������� (c ���������� ��� � �����)
void FillStudAllDB(Student *Arr, int Size, int FillType)
{
	std::string Name;				// ���
	std::string SecondName;			// �������
	int	YearBirth = 0;				// ��� ��������
	int	YearReceipt = 0;			// ��� �����������
	double Scholarship = 0.0;		// ���������
	int	BudCon = 0;					// ������/�������� ("1" - ������; "2" - ��������)

	// ���������� � ����������
	if (FillType == 1)
	{
		for (int i = 0; i < Size; i++)
		{
			std::cout << "������� ���������� � �������� �" << i + 1 << std::endl;
			std::cout << "������� ���: ";
			std::cin >> Name;
			Arr[i].setName(Name);

			std::cout << "������� �������: ";
			std::cin >> SecondName;
			Arr[i].setSecondName(SecondName);

			std::cout << "������� ��� ��������: ";
			std::cin >> YearBirth;
			Arr[i].setYearBirth(YearBirth);

			std::cout << "������� ��� �����������: ";
			std::cin >> YearReceipt;
			Arr[i].setYearReceipt(YearReceipt);

			std::cout << "������� ���������: ";
			std::cin >> Scholarship;
			Arr[i].setScholarship(Scholarship);

			std::cout << "������� ����� �������� (""1"" - ������; ""2"" - ��������): ";
			std::cin >> BudCon;
			Arr[i].setBudCon(BudCon);
			std::cout << std::endl << std::endl;
		}
	}
	// ���������� � �����
	else if (FillType == 2)
	{
		std::ifstream fin("DB_Stud.txt");				// �������� ����� � ��
		if (!fin.is_open())								// �������� ��� ���� ��������
		{
			std::cout << "\n���� �� ����� ���� ������!\n";
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
			fin.close();								// �������� ����� � ��
			std::cout << "\n���� �������� �������!\n";
			system("pause");
		}
	}
}


// ������� ������ ���� �� ��������� 
void PrintStudAllDB(Student *Arr, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		std::cout << "���������� � �������� �" << i + 1 << std::endl;
		std::cout << "���: " << Arr[i].getName() << std::endl;
		std::cout << "�������: " << Arr[i].getSecondName() << std::endl;
		std::cout << "��� ��������: " << Arr[i].getYearBirth() << std::endl;
		std::cout << "��� �����������: " << Arr[i].getYearReceipt() << std::endl;
		std::cout << "���������: " << Arr[i].getScholarship() << std::endl;
		std::cout << "����� ��������: ";
		if (Arr[i].getBudCon() == 1)
			std::cout << "������" << std::endl << std::endl;
		else if (Arr[i].getBudCon() == 2)
			std::cout << "��������" << std::endl << std::endl;
	}
}
