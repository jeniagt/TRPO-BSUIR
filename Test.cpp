#include "Test.h"

string ToLower(string result) {
    int i = 0;
    while (result[i])                           // пока не конец строки
    {
        result[i] = (char)tolower(result[i]);  // преобразовать текущий символ строки в строчный
        i++;                                   // инкремент индекса символов в строке
    }
    return result;
}

void SetDigit(int& choice) {
    cin >> choice;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "¬ведите число!" << endl;
        cin >> choice;
    }
}
void SetPositive(double& price) {
    cin >> price;
    while (cin.fail() || price <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "¬ведите положительное число!" << endl;
        cin >> price;
    }
}
void SetPositive(int& age) {
    cin >> age;
    while (cin.fail() || age <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "¬ведите положительное число!" << endl;
        cin >> age;
    }
}
void SetSize(int& n, int count) {
    cin >> n; n--;
    while (cin.fail() || n < 0 || n >= count) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "¬ведите номер строки из таблицы!" << endl;
        cin >> n;
        n--;
    }
}

void TestOpen(bool open) {
    if (!open) {
        cout << endl << "ќшибка открыти€ файла!" << endl;
        system("pause"); exit(0);
    }
}