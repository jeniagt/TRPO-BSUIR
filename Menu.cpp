#include "Menu.h"

void UserMenu() {
    vector<Toy> Toys;
    CreateVector(Toys);
    while (true) {
        cout << "--------------------------------���� ������������-----------------------------------------------" << endl;
        cout << endl << "1.�������� ������������ ��������;\n2.�����;\n3.����������;\n0.����� � ������� ����." << endl;
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
    cout << "--------------------------------���� ��������������-----------------------------------------------" << endl;
    cout << "\n1.������ � �������� ��������;\n2.������ � �������;\n0.����� � ������� ����." << endl;
    int choice; SetDigit(choice);
    switch (choice) {
    case 1: AccountMenu(Users); break;
    case 2: DataMenu(); break;
    case 0: return;
    }
    AdminMenu(Users);
}
void AccountMenu(vector<User>& Users) {
    cout << "\n--------------------------------���� ������ � �������� ��������-----------------------------------------------" << endl;
    cout << "\n1.�������� ���� ������� �������;\n2.���������� ����� ������� ������;\n3.�������������� ������� ������;\n4.�������� ������� ������;\n0.�����." << endl;
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
        cout << "\n--------------------------------���� ������ � �������-----------------------------------------------" << endl;
        cout << "\n1.����� ��������������;\n2.����� ���������;\n0.�����." << endl;
        int choice; SetDigit(choice);
        switch (choice) {
        case 1: EditMenu(Toys); break;
        case 2: ProcessingMenu(Toys); break;
        case 0: Filling(Toys); return;
        }
    }
}
void EditMenu(vector<Toy>& Toys) {
    cout << endl << "--------------------------------��������������-----------------------------------------------" << endl;
    cout << endl << "1.�������� ������������ ��������;\n2.���������� ����� �������;\n3.�������������� ������;\n4.�������� ������;\n0.�����." << endl;
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
    cout << endl << "--------------------------------���������-----------------------------------------------" << endl;
    cout << endl << "1.�����;\n2.����������;\n0.�����." << endl;
    int choice;
    SetDigit(choice);
    switch (choice) {
    case 1: MenuSearch(Toys); break;
    case 2: MenuSort(Toys); break;
    case 0: return;
    }
    ProcessingMenu(Toys);
}