#pragma once
#include <iostream>
#include "Human.h"

// ��������� �������

// ������� ���������� �� (c ���������� ��� � �����)
void FillHumAllDB(Human *Arr, int Size, int FillType);

// ������� ������ ������� ��� ����, ��� � ��
void PrintHumFullName(Human *Arr, int Size);

// ������� ������ �������, ����� ����, ��� � ��
void PrintHumName(Human *Arr, int Size);

// ������� ���������� ���������/�������������� �� ������� 
void SortHumSecondName(Human *Arr, int Size);