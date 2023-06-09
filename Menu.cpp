#include "Menu.h"

void UserMenu() {
    vector<Toy> Toys;
    CreateVector(Toys);
    while (true) {
        cout << "--------------------------------Меню пользователя-----------------------------------------------" << endl;
        cout << endl << "1.Просмотр ассортимента магазина;\n2.Поиск;\n3.Сортировка;\n0.Выход в главное меню." << endl;
        int choice; SetDigit(choice);
        switch (choice) {
        case 1: ShowAllToys(Toys); break;
        case 2: MenuSearch(Toys); break;
        case 3: MenuSort(Toys); break;
        case 0: Filling(Toys); return;
        }
    }
}
void AdminMenu(vector<User>& Users) {
    cout << "--------------------------------Меню администратора-----------------------------------------------" << endl;
    cout << "\n1.Работа с учётными записями;\n2.Работа с данными;\n0.Выход в главное меню." << endl;
    int choice; SetDigit(choice);
    switch (choice) {
    case 1: AccountMenu(Users); break;
    case 2: DataMenu(); break;
    case 0: return;
    }
    AdminMenu(Users);
}
void AccountMenu(vector<User>& Users) {
    cout << "\n--------------------------------Меню работы с учётными записями-----------------------------------------------" << endl;
    cout << "\n1.Просмотр всех учётных записей;\n2.Добавление новой учётной записи;\n3.Редактирование учётной записи;\n4.Удаление учётное записи;\n0.Назад." << endl;
    int choice; SetDigit(choice);
    switch (choice) {
    case 1: ShowUsers(Users); break;
    case 2: Registration(Users, 1); break;
    case 3: EditUsers(Users); break;
    case 4: DeleteMode(Users); break;
    case 0: return;
    }
    AccountMenu(Users);
}
void DataMenu() {
    vector<Toy> Toys;
    CreateVector(Toys);
    while (true) {
        cout << "\n--------------------------------Меню работы с данными-----------------------------------------------" << endl;
        cout << "\n1.Режим редактирования;\n2.Режим обработки;\n0.Назад." << endl;
        int choice; SetDigit(choice);
        switch (choice) {
        case 1: EditMenu(Toys); break;
        case 2: ProcessingMenu(Toys); break;
        case 0: Filling(Toys); return;
        }
    }
}
void EditMenu(vector<Toy>& Toys) {
    cout << endl << "--------------------------------Редактирование-----------------------------------------------" << endl;
    cout << endl << "1.Просмотр ассортимента магазина;\n2.Добавление новой игрушки;\n3.Редактирование записи;\n4.Удаление записи;\n0.Назад." << endl;
    int choice;
    SetDigit(choice);
    switch (choice) {
    case 1: ShowAllToys(Toys); break;
    case 2: addToy(Toys); break;
    case 3: EditToy(Toys); break;
    case 4: DeleteMode(Toys); break;
    case 0: return;
    }
    EditMenu(Toys);
}
void ProcessingMenu(vector<Toy>& Toys) {
    cout << endl << "--------------------------------Обработка-----------------------------------------------" << endl;
    cout << endl << "1.Поиск;\n2.Сортировка;\n0.Назад." << endl;
    int choice;
    SetDigit(choice);
    switch (choice) {
    case 1: MenuSearch(Toys); break;
    case 2: MenuSort(Toys); break;
    case 0: return;
    }
    ProcessingMenu(Toys);
}