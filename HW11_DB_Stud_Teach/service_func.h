#pragma once
#include <iostream>
#include "Human.h"

// служебные функции

// функция заполнения БД (c клавиатуры или с файла)
void FillHumAllDB(Human *Arr, int Size, int FillType);

// функция вывода полного ФИО всех, кто в БД
void PrintHumFullName(Human *Arr, int Size);

// функция вывода фамилии, имени всех, кто в БД
void PrintHumName(Human *Arr, int Size);

// функция сортировки студентов/преподавателей по фамилии 
void SortHumSecondName(Human *Arr, int Size);