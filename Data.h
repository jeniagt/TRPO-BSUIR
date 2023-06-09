#pragma once
#include <fstream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <iostream>
#include <windows.h>
#include <vector>

#include "Test.h"
#include "Users.h"
using namespace std;

struct Toy {
    string name; // Название игрушки
    double price; // Цена игрушки
    string county; // Изготовитель(страна)
    int count; // Количество в наличии
    int minAge; // Минимальный возраст для игрушки
};

void CreateVector(vector<Toy>& Toys); // Создание вектора 
void FillVector(vector<Toy>& Toys, fstream& file); // Выгрузка из файла в вектора данных об игрушках
void Filling(vector<Toy>& Toys); // Запись файла об игрушках данными вектора 

void ShowAllToys(vector<Toy>& Toys); // Перебирает вектор и передает значения для показа игруши 
void Cap(); // Шапка таблицы с игрушками
void ShowToy(Toy Show, int& n); // Показывает переданную игрушку

void addToy(vector<Toy>& Toys); // Добавление игрушки в вектор структур
Toy EntryToy(); // Ввод данных об игрушке

void EditToy(vector<Toy>& Toys); // Редактирование игрушки

void DeleteMode(vector<Toy>& Toys); // Меню удаления игрушки 
vector<Toy> DeleteToy(vector<Toy>& Toys, const int& n); // Удаление игрушки из вектора

void MenuSearch(vector<Toy>& Toys); // Меню поиска
void SearchAge(vector<Toy>& Toys); // Поиск игрушки по возрасту(индивидуальное задания)
void SearchName(vector<Toy>& Toys); // Поиск игрушки по названию
void SearchPrice(vector<Toy>& Toys); // Поиск игрушки по цене

void MenuSort(vector<Toy>& Toys); // Меню сортировки
void SortAlphabet(vector<Toy>& Toys); // Сортировка по алфавиту
void SortAge(vector<Toy>& Toys); // Сортировка по возрасту
void SortQuantity(vector<Toy>& Toys); // Сортировка по количеству