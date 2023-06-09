#pragma once
#include <fstream>
#include <vector>
#include <ctime>
#include <string>
#include <iomanip>
#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Test.h"
#include "Data.h"

using namespace std;

struct User {
    string username; // Логин пользователя
    string password_hash; // Хешированный пароль
    string salt; // Соль добавляемая к паролю
    int role = 0; // Роль в программе (0-пользователь, 1- админ)
    int access = 0; // Состояние аккаунта (0 - требует подтверждения админа, 1 - подтверждён, 666 - заблокирован)
};

void CreateVector(vector<User>& Users); // Создание вектора пользователей
void FillVector(vector<User>& Users, fstream& file); // Выгрузка из файла в вектора данных об пользователях
void FillFile(vector<User>& Users); // Запись файла о пользователях данными вектора 

void Registration(vector<User>& Users); // Регистрация пользователя
void Registration(vector<User>& Users, int access); // Регистрация пользователя при регистрации админом 

bool isLoginUnique(vector<User>& Users, string username); // Проверка логина на уникальность
void LoggedIn(vector<User>& Users); // Проверка логина и пароля при входе пользователя 

string CreateSalt(); // Создания "соли" для смешивания с паролей при хешировании 
unsigned long hash_function(string password, string salt); // Хеширование пароля с "солью"

void ShowUsers(vector<User>& Users); // Показывает список пользователей

void DeleteMode(vector<User>& Users); // Меню удаления пользователя
vector <User> DeleteUser(vector<User>& Users, const int& n); // Удаление пользователя

void EditUsers(vector<User>& Users); // Редактирование пользователя
void Block(vector<User>& Users, int& n); // Блокировка/разблокировка пользователя
void Confirm(vector<User>& Users, int& n); // Подтверждение пользователя после его регистрации
void GetAdmin(vector<User>& Users, int& n); // Присваивание администратора или лишение