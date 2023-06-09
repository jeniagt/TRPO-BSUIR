#pragma once
#include <iostream>
#include <vector>

#include "Users.h"
#include "Data.h"
using namespace std;

void UserMenu(); // Вызов меню при заходе обычного пользователя
void AdminMenu(vector<User>& Users); // Вызов меню при заходе администратора
void AccountMenu(vector<User>& Users); // Вызов меню работы с пользователями
void DataMenu(); // Вызов меню работы с данными
void EditMenu(vector<Toy>& Toys); // Вызов меню редактирования данных
void ProcessingMenu(vector<Toy>& Toys); // Вызов меню обработки данных(сортировка, поиск)