#pragma once
#include <iostream>
#include "Student.h"
#include "Teacher.h"

// служебные функции

// функция заполнения БД (c клавиатуры или с файла)
//void FillHumAllDB(Human **Arr, int Size, int FillType);

// функция вывода полного ФИО и статуса всех, кто в БД
void PrintHumFullName(Human **Arr, int Size);

// функция сортировки студентов по фамилии 
void SortStudSecondName(Human **Arr, int Size);
 
// функция сортировки преподавателей по фамилии 
void SortTeachSecondName(Human **Arr, int Size);