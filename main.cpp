#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

#include "Menu.h"
#include "Users.h"

int main(){   
    setlocale(0, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<User> Users; 
    CreateVector(Users);
    while (true) {
        cout << "--------------------------------Авторизация-----------------------------------------------" << endl;
        cout << "\n1.Регистрация;\n2.Вход;\n0.Завершить программу." << endl;
        int choice; SetDigit(choice);
        switch (choice) {
        case 1: Registration(Users); break;
        case 2: LoggedIn(Users); break;
        case 0: FillFile(Users); return 0;
        }
    }
}