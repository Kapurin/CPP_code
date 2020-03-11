/* �������� ������: "���� "����""
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

	std::srand(time(NULL));			// ��� ��������� ��������� ����� ��� ������ �������

	int Choice = 0;		// ���������� ������ �������� � ����

	cout << "=== ���� ""����"" ===\n\n";

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
			cout << "���������� � �������� �������:\n";
			PrintPlayHealth(&P1, N1);
			PrintPlayHealth(&P2, N2);
			system("pause");
			system("cls");

			cout << "����!!! ��� ������� !!!\a\n\n";
			// ��� �������� ����� � 1
			while ((P1.getHealth() > 0) && (P2.getHealth() > 0) && (Choice == 1))
			{
				// ����� ������ �1
				if ((P1.getHealth() > 0) && (P2.getHealth() > 0))
				{
					PrintFightStartInfo(N1, N2);
					FightPunch(&P1, &P2);
					PrintFightEndInfo(&P2, N1, N2);
				}

				// ����� ������ �2
				if ((P1.getHealth() > 0) && (P2.getHealth() > 0))
				{
					PrintFightStartInfo(N2, N1);
					FightPunch(&P2, &P1);
					PrintFightEndInfo(&P1, N2, N1);
				}
			}

			// ��� �������� ����� � 2
			while ((P1.getHealth() > 0) && (P2.getHealth() > 0) && (Choice == 2))
			{
				// ����� ������ �2
				if ((P1.getHealth() > 0) && (P2.getHealth() > 0))
				{
					PrintFightStartInfo(N2, N1);
					FightPunch(&P2, &P1);
					PrintFightEndInfo(&P1, N2, N1);
				}

				// ����� ������ �1
				if ((P1.getHealth() > 0) && (P2.getHealth() > 0))
				{
					PrintFightStartInfo(N1, N2);
					FightPunch(&P1, &P2);
					PrintFightEndInfo(&P2, N1, N2);
				}
			}

			// ��������� ���
			cout << "\n\n = ��������� ��������: =\n";
			if (P1.getHealth() == 0)
				cout << "����� � 2 ������� !!!\n";
			else if (P2.getHealth() == 0)
				cout << "����� � 1 ������� !!!\n";

			cout << "\n = �������� ���� = \n";
			PrintPlayHealth(&P1, N1);
			PrintPlayHealth(&P2, N2);
			system("pause");
			system("cls");
			Choice = 999;

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

	return 0;
}