#pragma once
#include <iostream>
#include <fstream>
#include <ctime>

class Boxer
{
private:
	int m_health;	// здоровье

public:
	Boxer();
	Boxer(int Health);

	// функции-сеттеры
	void setHealth(int Health);

	// функции-геттеры
	int getHealth() const;


	// функция удара
	int Punch();

};



// служебные функции

// функция вывода текущего здоровья игрока
void PrintPlayHealth(Boxer* P, int Num, std::ofstream &log);

// функция вывода информации в начале атаки
void PrintFightStartInfo(int Num1, int Num2, std::ofstream &log);

// функция вывода информации в конце атаки
void PrintFightEndInfo(Boxer *P2, int Num1, int Num2, std::ofstream &log);

// функция нанесения удара
void FightPunch(Boxer *P1, Boxer *P2, std::ofstream &log);