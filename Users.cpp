#include "Users.h"
#include "Menu.h"

void CreateVector(vector<User>& Users) {
    fstream file;
    file.open("accounts.txt", ios::in);
    TestOpen(file.is_open());
    FillVector(Users, file);
    file.close();
}
void FillVector(vector<User>& Users, fstream& file) {
    string line;
    while (getline(file, line)) {
        User user;
        user.username = line;
        getline(file, line); user.password_hash = line;
        getline(file, line); user.salt = line;
        getline(file, line); user.role = atoi(line.c_str());
        getline(file, line); user.access = atoi(line.c_str());
        Users.push_back(user);
    }
}
void FillFile(vector<User>& Users) { 
    ofstream file;
    file.open("Accounts.txt");
    TestOpen(file.is_open());
    for (int i = 0; i < Users.size(); i++) {
        file << Users[i].username << endl;
        file << Users[i].password_hash << endl;
        file << Users[i].salt << endl;
        file << Users[i].role << endl;
        file << Users[i].access << endl;
    }
    file.close();
}

void Registration(vector<User>& Users) {
    system("cls");
    cout << "\n--------------------------------Регистрация-----------------------------------------------" << endl;
    User user;
    cout << "Выберите логин - ";
    char c;
    while (true) {
        cin >> user.username;
        if (isLoginUnique(Users, user.username))  cout << "\nДанный логин используется другим пользователем\nВыберите другой логин: ";
        else break;
    }
    cout << "Выберите пароль - ";
    while ((c = _getch()) != '\r') {
        user.password_hash += c;
        _putch('*');
    }
    user.salt = CreateSalt();
    user.password_hash = to_string(hash_function(user.password_hash, user.salt));
    Users.push_back(user);
    cout << "\nАккаунт успешно создан!" << endl;
}
void Registration(vector<User>& Users, int access) {
    system("cls");
    cout << "\n--------------------------------Регистрация-----------------------------------------------" << endl;
    User user;
    cout << "Выберите логин - ";
    char c;
    while (true) {
        cin >> user.username;
        if (isLoginUnique(Users, user.username))  cout << "\nДанный логин используется другим пользователем\nВыберите другой логин: ";
        else break;
    }
    cout << "Выберите пароль - ";
    while ((c = _getch()) != '\r') {
        user.password_hash += c;
        _putch('*');
    }
    user.salt = CreateSalt();
    user.password_hash = to_string(hash_function(user.password_hash, user.salt));
    user.access = access;
    cout << "\nСделать пользователя администратором?\n1.Да;\n0.Нет." << endl;
    int choice; SetDigit(choice);
    if (choice == 1) user.role = 1;
    Users.push_back(user);
    cout << endl << "Аккаунт успешно создан!" << endl;
}

bool isLoginUnique(vector<User>& Users, string username) { // Проверка логина на уникальность

    for (int i = 0; i < Users.size(); i++) {
        if (ToLower(username) == ToLower(Users[i].username))
            return true;
    }
    return false;
}
void LoggedIn(vector<User>& Users) {
    User user;
    cout << "Введите логин - "; cin >> user.username;
    cout << "Введите пароль - ";
    char c;
    while ((c = _getch()) != '\r') {
        user.password_hash += c;
        _putch('*');
    }
    for (int i = 0; i < Users.size(); i++) {
        if (ToLower(Users[i].username) == ToLower(user.username) &&
            atoi(Users[i].password_hash.c_str()) == hash_function(user.password_hash, Users[i].salt)) {
            if (Users[i].access == 0) {
                cout << "\nОтказано в доступе\nВаш аккаунт не подтверждён." << endl;
                return;
            }
            else if (Users[i].access == 666) {
                cout << "\nОтказано в доступе\nВаш аккаунт заблокирован." << endl;
                return;
            }
            cout << "\nУспешный вход\nДобро пожаловать!" << endl;
            if (Users[i].role == 1) AdminMenu(Users);
            else UserMenu();
            return;
        }
    }
    cout << endl << "Неверное имя пользователя или пароль" << endl;
}

string CreateSalt() {
    srand(time(NULL));
    string salt = "";
    const int SIZE = (rand() % 100) + 50;
    for (int i = 0; i < SIZE; i++) salt += char((rand() % 42) + 48); // ASCII 48-90
    return salt;
}
unsigned long hash_function(string password, string salt) {
    password += salt;
    unsigned long i = 0;
    for (int j = 0; j < password.size(); j++) i += password[j];
    return i;
}

void ShowUsers(vector<User>& Users) {
    cout << "\n--------------------------------Аккаунты-----------------------------------------------" << endl;

    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "| " << setw(3) << left << "N" <<
        " | " << setw(20) << left << "account" <<
        " | " << setw(20) << left << "Тип аккауна" <<
        " | " << setw(35) << left << "Состояние" << " | " << endl;
    cout << "\n---------------------------------------------------------------------------------------------------" << endl;
    for (int n = 0; n < Users.size(); n++) {

        cout << "| " << setw(3) << left << n + 1;
        cout << " | " << setw(20) << left << Users[n].username;

        if (Users[n].role == 1) cout << " | " << setw(20) << left << "Администратор";
        else cout << " | " << setw(20) << left << "Пользователь";

        if (Users[n].access == 0) cout << " | " << setw(35) << left << "Не активирован (требуется действие)" << " | " << endl;
        else if (Users[n].access == 1) cout << " | " << setw(35) << left << "Активирован" << " | " << endl;
        else cout << " | " << setw(35) << left << "Заблокирован" << " | " << endl;
        cout << "---------------------------------------------------------------------------------------------------" << endl;
    }
}

void DeleteMode(vector<User>& Users) {
    cout << "\n--------------------------------Режим удаления-----------------------------------------------" << endl;
    ShowUsers(Users);
    cout << "Какого пользователя хотите удалить N?" << endl;
    int n; SetSize(n, Users.size());
    if (ToLower(Users[n].username) == "admin") {
        cout << "Отказано в доступе!\nВы не можете удалить главного админа!" << endl;
        return;
    }
    cout << "Вы действительно хотите удалить аккаунт? " << Users[n].username << endl << "1.Да;\n2.Нет." << endl;
    int enter; SetDigit(enter);
    if (enter != 1) {
        cout << "Удаление отменено!" << endl;
        return;
    }
    Users = DeleteUser(Users, n);
    cout << "Игрушка успешно удалена!" << endl;
}
vector<User> DeleteUser(vector<User>& Users, const int& n) {
    vector<User> NewUsers;
    for (int i = 0; i < Users.size(); i++) {
        if (i != n) NewUsers.push_back(Users[i]);
    }
    return NewUsers;
}

void EditUsers(vector<User>& Users) {
    ShowUsers(Users);
    cout << "\nВыберите номер аккаунта для редактирования" << endl;
    int n; SetSize(n, Users.size());
    cout << "\nВыберите действие" << endl;
    cout << "\n1.Изменить статус блокировки;\n2.Подтвердить аккаунт;\n3.Изменить статус аккаунта;\n0.Назад." << endl;
    int choice;  SetDigit(choice);
    switch (choice) {
    case 1: Block(Users, n); break;
    case 2: Confirm(Users, n); break;
    case 3: GetAdmin(Users, n); break;
    case 0: return;
    }
}
void Block(vector<User>& Users, int& n) {
    if (Users[n].access == 666) {
        Users[n].access = 1;
        cout << "Аккаунт " << Users[n].username << " разблокирован" << endl;
    }
    else {
        Users[n].access = 666;
        cout << "Аккаунт " << Users[n].username << " заблокирован" << endl;
    }
}
void Confirm(vector<User>& Users, int& n) {
    if (Users[n].access == 0) {
        Users[n].access = 1;
        cout << "Аккаунт " << Users[n].username << " успешно подтверждён" << endl;
    }
    else cout << "Аккаунт " << Users[n].username << " уже был подтверждён ранее" << endl;
}
void GetAdmin(vector<User>& Users, int& n) {
    if (Users[n].role == 0) {
        Users[n].role = 1;
        cout << "Аккаунт " << Users[n].username << " теперь имеет статус администратора" << endl;
    }
    else {
        Users[n].role = 0;
        cout << "Аккаунт " << Users[n].username << " теперь имеет статус пользователя" << endl;
    }
}