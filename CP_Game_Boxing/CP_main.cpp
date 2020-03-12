/* Курсовая работа: "Игра "Бокс""
*/


#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include "Boxer.h"


using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::srand(time(NULL));			// для генерации случайных чисел при каждом запуске
	int Choice = 0;					// переменная выбора действия в меню

	ofstream play_log("Fight_log.txt");			// открытие файла для логирования процесса игры
	if (!play_log.is_open())					// проверка что файл открылся
	{
		std::cout << "\nФайл не может быть открыт!\n";
		system("pause");
	}
	else
		play_log << "***** Процесс логирования игры запущен! *****\n\n";


	cout << "=== ИГРА ""Бокс"" ===\n\n";
	play_log << "=== ИГРА ""Бокс"" ===\n\n";

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
			cout << "\nИнформация о здоровье игроков:\n";
			play_log << "\nИнформация о здоровье игроков:\n";
			PrintPlayHealth(&P1, N1, play_log);
			PrintPlayHealth(&P2, N2, play_log);
			system("pause");
			system("cls");

			cout << "\n\nГОНГ!!! Бой начался !!!\a\n\n";
			play_log << "\n\nГОНГ!!! Бой начался !!!\a\n\n";
			// бой начинает Игрок № 1
			while ((P1.getHealth() > 0) && (P2.getHealth() > 0) && (Choice == 1))
			{
				// атака игрока №1
				if ((P1.getHealth() > 0) && (P2.getHealth() > 0))
				{
					PrintFightStartInfo(N1, N2, play_log);
					FightPunch(&P1, &P2, play_log);
					PrintFightEndInfo(&P2, N1, N2, play_log);
				}

				// атака игрока №2
				if ((P1.getHealth() > 0) && (P2.getHealth() > 0))
				{
					PrintFightStartInfo(N2, N1, play_log);
					FightPunch(&P2, &P1, play_log);
					PrintFightEndInfo(&P1, N2, N1, play_log);
				}
			}

			// бой начинает Игрок № 2
			while ((P1.getHealth() > 0) && (P2.getHealth() > 0) && (Choice == 2))
			{
				// атака игрока №2
				if ((P1.getHealth() > 0) && (P2.getHealth() > 0))
				{
					PrintFightStartInfo(N2, N1, play_log);
					FightPunch(&P2, &P1, play_log);
					PrintFightEndInfo(&P1, N2, N1, play_log);
				}

				// атака игрока №1
				if ((P1.getHealth() > 0) && (P2.getHealth() > 0))
				{
					PrintFightStartInfo(N1, N2, play_log);
					FightPunch(&P1, &P2, play_log);
					PrintFightEndInfo(&P2, N1, N2, play_log);
				}
			}

			// результат боя
			cout << "\n\n = Результат поединка: =\n";
			play_log << "\n\n = Результат поединка: =\n";
			if (P1.getHealth() == 0)
			{
				cout << "Игрок № 2 победил !!!\n";
				play_log << "Игрок № 2 победил !!!\n";
			}
			else if (P2.getHealth() == 0)
			{
				cout << "Игрок № 1 победил !!!\n";
				play_log << "Игрок № 1 победил !!!\n";
			}
			cout << "\n = Итоговый счет = \n";
			play_log << "\n = Итоговый счет = \n";
			PrintPlayHealth(&P1, N1, play_log);
			PrintPlayHealth(&P2, N2, play_log);
			cout << "\n = Поединок окончен. = \n\n";
			play_log << "\n = Поединок окончен. = \n\n";
			system("pause");
			system("cls");
			Choice = 999;		// возврат к игровому меню

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

	play_log << "\n\n***** Процесс логирования игры остановлен! *****\n\n";
	play_log.close();		// закрытие файла логирования процесса игры
	return 0;
}