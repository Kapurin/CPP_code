#pragma once
#include <iostream>
#include "Student.h"
#include "Teacher.h"

// ��������� �������

// ������� ���������� �� (c ���������� ��� � �����)
//void FillHumAllDB(Human **Arr, int Size, int FillType);

// ������� ������ ������� ��� � ������� ����, ��� � ��
void PrintHumFullName(Human **Arr, int Size);

// ������� ���������� ��������� �� ������� 
void SortStudSecondName(Human **Arr, int Size);
 
// ������� ���������� �������������� �� ������� 
void SortTeachSecondName(Human **Arr, int Size);