#include "Boxer.h"


// конструктор
Boxer::Boxer() {}
Boxer::Boxer(int Health)
{
	m_health = Health;
}


// функции-сеттеры
void Boxer::setHealth(int Health)
{
	m_health = Health;
}



// функции-геттеры
int Boxer::getHealth() const
{
	return m_health;
}

// функция удара
int Boxer::Punch()
{
	// случайное число (от 5 до 33) 
	return (rand() % 29 + 5);
}



// служебные функции

// функция вывода текущего здоровья игрока
void PrintPlayHealth(Boxer *P, int Num, std::ofstream &log)
{
	std::cout << "Здоровье игрока № " << Num <<": " << P->getHealth() << " очков.\n";
	log << "Здоровье игрока № " << Num << ": " << P->getHealth() << " очков.\n";
}


// функция вывода информации в начале атаки
void PrintFightStartInfo(int Num1, int Num2, std::ofstream &log)
{
	std::cout << "\n\nИгрок № " << Num1 << " атакует игрока № " << Num2 <<"!\n";
	log << "\n\nИгрок № " << Num1 << " атакует игрока № " << Num2 << "!\n";
}


// функция вывода информации в конце атаки
void PrintFightEndInfo(Boxer *P2, int Num1, int Num2, std::ofstream &log)
{
	std::cout << "Игрок № " << Num1 << " атаковал игрока № " << Num2 << "!\n";
	std::cout << "У игрока № " << Num2 << " осталось " << P2->getHealth() << " очков здоровья.\n\n";
	log << "Игрок № " << Num1 << " атаковал игрока № " << Num2 << "!\n";
	log << "У игрока № " << Num2 << " осталось " << P2->getHealth() << " очков здоровья.\n\n";
}


// функция нанесения удара
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