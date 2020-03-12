#include "Boxer.h"


// �����������
Boxer::Boxer() {}
Boxer::Boxer(int Health)
{
	m_health = Health;
}


// �������-�������
void Boxer::setHealth(int Health)
{
	m_health = Health;
}



// �������-�������
int Boxer::getHealth() const
{
	return m_health;
}

// ������� �����
int Boxer::Punch()
{
	// ��������� ����� (�� 5 �� 33) 
	return (rand() % 29 + 5);
}



// ��������� �������

// ������� ������ �������� �������� ������
void PrintPlayHealth(Boxer *P, int Num, std::ofstream &log)
{
	std::cout << "�������� ������ � " << Num <<": " << P->getHealth() << " �����.\n";
	log << "�������� ������ � " << Num << ": " << P->getHealth() << " �����.\n";
}


// ������� ������ ���������� � ������ �����
void PrintFightStartInfo(int Num1, int Num2, std::ofstream &log)
{
	std::cout << "\n\n����� � " << Num1 << " ������� ������ � " << Num2 <<"!\n";
	log << "\n\n����� � " << Num1 << " ������� ������ � " << Num2 << "!\n";
}


// ������� ������ ���������� � ����� �����
void PrintFightEndInfo(Boxer *P2, int Num1, int Num2, std::ofstream &log)
{
	std::cout << "����� � " << Num1 << " �������� ������ � " << Num2 << "!\n";
	std::cout << "� ������ � " << Num2 << " �������� " << P2->getHealth() << " ����� ��������.\n\n";
	log << "����� � " << Num1 << " �������� ������ � " << Num2 << "!\n";
	log << "� ������ � " << Num2 << " �������� " << P2->getHealth() << " ����� ��������.\n\n";
}


// ������� ��������� �����
void FightPunch(Boxer *P1, Boxer *P2, std::ofstream &log)
{
	int HealthCurr = 0;
	if (P2->getHealth() > 0)
	{
		HealthCurr = (P2->getHealth() - P1->Punch());
		if (HealthCurr < 0)
			HealthCurr = 0;
		P2->setHealth(HealthCurr);
		std::cout << "\n*** P-U-N-C-H !!! *** \n\n";
		log << "\n*** P-U-N-C-H !!! *** \n\n";
	}
}