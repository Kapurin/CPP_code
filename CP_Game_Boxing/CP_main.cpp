/* �������� ������: "���� "����""
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

	std::srand(time(NULL));			// ��� ��������� ��������� ����� ��� ������ �������
	int Choice = 0;					// ���������� ������ �������� � ����

	ofstream play_log("Fight_log.txt");			// �������� ����� ��� ����������� �������� ����
	if (!play_log.is_open())					// �������� ��� ���� ��������
	{
		std::cout << "\n���� �� ����� ���� ������!\n";
		system("pause");
	}
	else
		play_log << "***** ������� ����������� ���� �������! *****\n\n";


	cout << "=== ���� ""����"" ===\n\n";
	play_log << "=== ���� ""����"" ===\n\n";

	int N1 = 1;		// ����� �1
	int N2 = 2;		// ����� �2

	Boxer P1 (100);	// ����� �1
	Boxer P2 (100);	// ����� �2
	

	do
	{
		// ���� ����
		cout << "== ������� ����: == \n\n";
		cout << "1 - ��� �������� ����� � 1;\n";
		cout << "2 - ��� �������� ����� � 2;\n";
		cout << "0 - ���������� ����\n";
		cin >> Choice;


		while ((Choice == 1) || (Choice == 2))
		{
			cout << "\n���������� � �������� �������:\n";
			play_log << "\n���������� � �������� �������:\n";
			PrintPlayHealth(&P1, N1, play_log);
			PrintPlayHealth(&P2, N2, play_log);
			system("pause");
			system("cls");

			cout << "\n\n����!!! ��� ������� !!!\a\n\n";
			play_log << "\n\n����!!! ��� ������� !!!\a\n\n";
			// ��� �������� ����� � 1
			while ((P1.getHealth() > 0) && (P2.getHealth() > 0) && (Choice == 1))
			{
				// ����� ������ �1
				if ((P1.getHealth() > 0) && (P2.getHealth() > 0))
				{
					PrintFightStartInfo(N1, N2, play_log);
					FightPunch(&P1, &P2, play_log);
					PrintFightEndInfo(&P2, N1, N2, play_log);
				}

				// ����� ������ �2
				if ((P1.getHealth() > 0) && (P2.getHealth() > 0))
				{
					PrintFightStartInfo(N2, N1, play_log);
					FightPunch(&P2, &P1, play_log);
					PrintFightEndInfo(&P1, N2, N1, play_log);
				}
			}

			// ��� �������� ����� � 2
			while ((P1.getHealth() > 0) && (P2.getHealth() > 0) && (Choice == 2))
			{
				// ����� ������ �2
				if ((P1.getHealth() > 0) && (P2.getHealth() > 0))
				{
					PrintFightStartInfo(N2, N1, play_log);
					FightPunch(&P2, &P1, play_log);
					PrintFightEndInfo(&P1, N2, N1, play_log);
				}

				// ����� ������ �1
				if ((P1.getHealth() > 0) && (P2.getHealth() > 0))
				{
					PrintFightStartInfo(N1, N2, play_log);
					FightPunch(&P1, &P2, play_log);
					PrintFightEndInfo(&P2, N1, N2, play_log);
				}
			}

			// ��������� ���
			cout << "\n\n = ��������� ��������: =\n";
			play_log << "\n\n = ��������� ��������: =\n";
			if (P1.getHealth() == 0)
			{
				cout << "����� � 2 ������� !!!\n";
				play_log << "����� � 2 ������� !!!\n";
			}
			else if (P2.getHealth() == 0)
			{
				cout << "����� � 1 ������� !!!\n";
				play_log << "����� � 1 ������� !!!\n";
			}
			cout << "\n = �������� ���� = \n";
			play_log << "\n = �������� ���� = \n";
			PrintPlayHealth(&P1, N1, play_log);
			PrintPlayHealth(&P2, N2, play_log);
			cout << "\n = �������� �������. = \n\n";
			play_log << "\n = �������� �������. = \n\n";
			system("pause");
			system("cls");
			Choice = 999;		// ������� � �������� ����

			// ��������� ��������� ������ �������� �������
			P1.setHealth(100);
			P2.setHealth(100);
		}

		if ((Choice != 0) && (Choice != 1) && (Choice != 2) && (Choice != 999))
		{		
			cout << "\n\n������������ ����! ��������� �������.\n\n";
			system("pause");
			system("cls");
		}
	} while (Choice != 0);

	play_log << "\n\n***** ������� ����������� ���� ����������! *****\n\n";
	play_log.close();		// �������� ����� ����������� �������� ����
	return 0;
}