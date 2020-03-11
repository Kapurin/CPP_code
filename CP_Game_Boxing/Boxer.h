#pragma once
#include <iostream>
#include <ctime>

class Boxer
{
private:
	int m_health;	// ��������

public:
	Boxer();
	Boxer(int Health);

	// �������-�������
	void setHealth(int Health);

	// �������-�������
	int getHealth() const;


	// ������� �����
	int Punch();

};



// ��������� �������

// ������� ������ �������� �������� ������
void PrintPlayHealth(Boxer *P, int Num);

// ������� ������ ���������� � ������ �����
void PrintFightStartInfo(int Num1, int Num2);

// ������� ������ ���������� � ����� �����
void PrintFightEndInfo(Boxer *P2, int Num1, int Num2);

// ������� ��������� �����
void FightPunch(Boxer *P1, Boxer *P2);