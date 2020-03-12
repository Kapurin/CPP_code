#pragma once
#include <iostream>
#include <fstream>
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
void PrintPlayHealth(Boxer* P, int Num, std::ofstream &log);

// ������� ������ ���������� � ������ �����
void PrintFightStartInfo(int Num1, int Num2, std::ofstream &log);

// ������� ������ ���������� � ����� �����
void PrintFightEndInfo(Boxer *P2, int Num1, int Num2, std::ofstream &log);

// ������� ��������� �����
void FightPunch(Boxer *P1, Boxer *P2, std::ofstream &log);