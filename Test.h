#pragma once
#include <iostream>
#include <string>
using namespace std;

string ToLower(string result); // Делает строку с маленькими буквами

void SetDigit(int& choice); // Заполнение переменной цифрами
void SetPositive(double& price); // Заполнение переменной не отрицательными цифрами с плавающей точкой
void SetPositive(int& age); // Заполнение переменной не отрицательными цифрами
void SetSize(int& n, int count); // Заполнение переменной в размере вектора
void TestOpen(bool open); // Проверка файла на открытие