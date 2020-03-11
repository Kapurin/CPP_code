/* Курсовая работа: "Игра "Бокс""
*/


#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Boxer.h"


using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::srand(time(NULL));			// для генерации случайных чисел при каждом запуске

	int Choice = 0;		// переменная выбора действия в меню

	cout << "=== ИГРА ""Бокс"" ===\n\n";

	int N1 = 1;		// игрок №1
	int N2 = 2;		// игрок №2

	Boxer P1 (100);	// игрок №1
	Boxer P2 (100);	// игрок №2
	

	do
	{
		// меню игры
		cout << "== Игровое меню: == \n\n";
		cout << "1 - бой начинает Игрок № 1;\n";
		cout << "2 - бой начинает Игрок № 2;\n";
		cout << "0 - завершение игры\n";
		cin >> Choice;


		while ((Choice == 1) || (Choice == 2))
		{
			cout << "Информация о здоровье игроков:\n";
			PrintPlayHealth(&P1, N1);
			PrintPlayHealth(&P2, N2);
			system("pause");
			system("cls");

			cout << "ГОНГ!!! Бой начался !!!\a\n\n";
			// бой начинает Игрок № 1
			while ((P1.getHealth() > 0) && (P2.getHealth() > 0) && (Choice == 1))
			{
				// атака игрока №1
				if ((P1.getHealth() > 0) && (P2.getHealth() > 0))
				{
					PrintFightStartInfo(N1, N2);
					FightPunch(&P1, &P2);
					PrintFightEndInfo(&P2, N1, N2);
				}

				// атака игрока №2
				if ((P1.getHealth() > 0) && (P2.getHealth() > 0))
				{
					PrintFightStartInfo(N2, N1);
					FightPunch(&P2, &P1);
					PrintFightEndInfo(&P1, N2, N1);
				}
			}

			// бой начинает Игрок № 2
			while ((P1.getHealth() > 0) && (P2.getHealth() > 0) && (Choice == 2))
			{
				// атака игрока №2
				if ((P1.getHealth() > 0) && (P2.getHealth() > 0))
				{
					PrintFightStartInfo(N2, N1);
					FightPunch(&P2, &P1);
					PrintFightEndInfo(&P1, N2, N1);
				}

				// атака игрока №1
				if ((P1.getHealth() > 0) && (P2.getHealth() > 0))
				{
					PrintFightStartInfo(N1, N2);
					FightPunch(&P1, &P2);
					PrintFightEndInfo(&P2, N1, N2);
				}
			}

			// результат боя
			cout << "\n\n = Результат поединка: =\n";
			if (P1.getHealth() == 0)
				cout << "Игрок № 2 победил !!!\n";
			else if (P2.getHealth() == 0)
				cout << "Игрок № 1 победил !!!\n";

			cout << "\n = Итоговый счет = \n";
			PrintPlayHealth(&P1, N1);
			PrintPlayHealth(&P2, N2);
			system("pause");
			system("cls");
			Choice = 999;

			// установка исходного уровня здоровья игрокам
			P1.setHealth(100);
			P2.setHealth(100);
		}

		if ((Choice != 0) && (Choice != 1) && (Choice != 2) && (Choice != 999))
		{		
			cout << "\n\nНеправильный ввод! Повторите попытку.\n\n";
			system("pause");
			system("cls");
		}
	} while (Choice != 0);

	return 0;
}