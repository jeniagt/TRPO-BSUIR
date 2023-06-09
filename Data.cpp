#include "Data.h"
#include "Menu.h"

void CreateVector(vector<Toy>& Toys) {
    fstream file;
    file.open("Data.txt", ios::in);
    TestOpen(file.is_open());
    FillVector(Toys, file);
    file.close();
}
void FillVector(vector<Toy>& Toys, fstream& file) {
    string line;
    while (getline(file, line)) {
        Toy toy;
        toy.name = line;
        getline(file, line); toy.price = atof(line.c_str());
        getline(file, line); toy.county = line;
        getline(file, line); toy.count = atoi(line.c_str());
        getline(file, line); toy.minAge = atoi(line.c_str());
        Toys.push_back(toy);
    }
}
void Filling(vector<Toy>& Toys) {
    ofstream file;
    file.open("Data.txt");
    TestOpen(file.is_open());
    for (int i = 0; i < Toys.size(); i++) {
        file << Toys[i].name << endl;
        file << Toys[i].price << endl;
        file << Toys[i].county << endl;
        file << Toys[i].count << endl;
        file << Toys[i].minAge << endl;
    }
    file.close();
}

void ShowAllToys(vector<Toy>& Toys) {
    cout << endl << "--------------------------------Ассортимент магазина-----------------------------------------------" << endl;
    Cap();
    for (int i = 1; i < Toys.size() + 1; i++) ShowToy(Toys[i - 1], i);
}
void Cap() {
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "| " << setw(3) << left << "N" <<
        " | " << setw(30) << left << "Название" <<
        " | " << setw(6) << left << "Цена" <<
        " | " << setw(20) << left << "Изготовитель" <<
        " | " << setw(10) << left << "Количество" <<
        " | " << setw(7) << left << "Возраст" <<
        " |" << endl;
    cout << endl << "---------------------------------------------------------------------------------------------------" << endl;
}
void ShowToy(Toy toy, int& n) {
    cout << "| " << setw(3) << left << n <<
        " | " << setw(30) << left << toy.name <<
        " | " << setw(6) << left << toy.price <<
        " | " << setw(20) << left << toy.county <<
        " | " << setw(10) << left << toy.count <<
        " | " << setw(7) << left << toy.minAge <<
        " |" << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
}

Toy EntryToy() {
    Toy toy;
    cout << "Введите название игрушки: ";
    cin.ignore();
    getline(cin, toy.name);

    cout << "Введите цену: ";
    SetPositive(toy.price);

    cout << "Введите изготовителя: ";
    cin.ignore(); // Очистить буфер ввода перед чтением строки
    getline(cin, toy.county);

    cout << "Введите количество: ";
    SetPositive(toy.count);

    cout << "Введите минимальный возраст: ";
    SetPositive(toy.minAge);
    return toy;
}
void addToy(vector<Toy>& Toys) {
    cout << endl << "--------------------------------Режим добавления-----------------------------------------------" << endl;

    Toys.push_back(EntryToy());

    cout << "Игрушка успешно добавлена!" << endl;
    cout << "Хотите добавить ещё игрушку?\n1.Да;\n2.Нет." << endl;
    int n; SetDigit(n);
    if (n == 1) addToy(Toys);
}

void EditToy(vector<Toy>& Toys) { // Редактирование игрушки
    cout << endl << "--------------------------------Режим редактирования-----------------------------------------------" << endl;
    ShowAllToys(Toys);
    cout << "Какую строку хотите отредактировать?" << endl;
    int n; SetSize(n, Toys.size());

    Toys[n] = EntryToy();
    cout << "Игрушка успешно отредактирована!" << endl;
}

void DeleteMode(vector<Toy>& Toys) {
    cout << endl << "--------------------------------Режим удаления-----------------------------------------------" << endl;
    ShowAllToys(Toys);

    cout << "Какую строку хотите удалить?" << endl;
    int n; SetSize(n, Toys.size());
    cout << "Вы действительно хотите удалить игрушку № " << n + 1 << '?' << endl << "1.Да;\n2.Нет." << endl;
    int enter; SetDigit(enter);
    if (enter != 1) {
        cout << "Удаление отменено!" << endl;
        return;
    }
    Toys = DeleteToy(Toys, n);
    cout << "Игрушка успешно удалена!" << endl;
}
vector<Toy> DeleteToy(vector<Toy>& Toys, const int& n) {
    vector<Toy> NewToys;
    for (int i = 0; i < Toys.size(); i++) {
        if (i != n) NewToys.push_back(Toys[i]);
    }
    return NewToys;
}

void MenuSearch(vector<Toy>& Toys) {
    cout << endl << "--------------------------------Меню поиска-----------------------------------------------" << endl;
    cout << endl << "1.По названию;\n2.По цене;\n3.По возрасту;\n0.Назад." << endl;
    int choice; SetDigit(choice);
    switch (choice) {
    case 1: SearchName(Toys); break;
    case 2: SearchPrice(Toys); break;
    case 3: SearchAge(Toys); break;
    case 0: return;
    }
    MenuSearch(Toys);
}
void SearchName(vector<Toy>& Toys) {
    cout << "Какую игрушку хотите найти?" << endl;
    string result; cin.ignore(); getline(cin, result);
    result = ToLower(result);
    int n = 0;
    for (int i = 0; i < Toys.size(); i++) {
        if (ToLower(Toys[i].name).find(result) == std::string::npos) continue;
        else {
            n++;
            if (n == 1) Cap();
            ShowToy(Toys[i], n);
        }
    }
    if (n == 0) cout << "Игрушка с таким названием в ассортименте отсутсвует" << endl;
}
void SearchPrice(vector<Toy>& Toys) {
    cout << "Введите цену?" << endl;
    double price; SetPositive(price);

    int n = 0;
    for (int i = 0; i < Toys.size(); i++) {
        if (Toys[i].price > price) continue;
        else {
            n++;
            if (n == 1) Cap();
            ShowToy(Toys[i], n);
        }
    }
    if (n == 0) cout << "Игрушки с ценой меньше - в ассортименте отсутсвует" << endl;
}
void SearchAge(vector<Toy>& Toys) {
    cout << "Для какого возраста хотите выбрать игрушку?" << endl;
    int x;  SetPositive(x);
    int n = 0;
    for (int i = 0; i < Toys.size(); i++) {
        if (Toys[i].minAge <= x) {
            n++;
            if (n == 1) Cap();
            ShowToy(Toys[i], n);
        }
    }
    if (n == 0) cout << "Игрушки для такого возраста в ассортименте отсутсвуют" << endl;
}

void MenuSort(vector<Toy>& Toys) {
    cout << endl << "--------------------------------Меню сортировки-----------------------------------------------" << endl;
    cout << endl << "1.По алфавиту;\n2.По возрасту;\n3.По количеству;\n0.Назад." << endl;
    int choice; SetDigit(choice);
    cout << "--------------------------------Сортированная информация---------------------------------------------------" << endl;
    switch (choice) {
    case 1: SortAlphabet(Toys); break;
    case 2: SortAge(Toys); break;
    case 3: SortQuantity(Toys); break;
    case 0: return;
    }
    MenuSort(Toys);
}
void SortAlphabet(vector<Toy>& Toys) {
    Toy temp;
    // Сортировка пузырьком
    for (int i = 0; i < Toys.size() - 1; i++) {
        for (int j = 0; j < Toys.size() - i - 1; j++) {
            if (Toys[j].name > Toys[j + 1].name) {
                // меняем элементы местами
                temp = Toys[j];
                Toys[j] = Toys[j + 1];
                Toys[j + 1] = temp;
            }
        }
    }
    ShowAllToys(Toys);
}
void SortAge(vector<Toy>& Toys) {
    Toy temp;
    // Сортировка пузырьком
    for (int i = 0; i < Toys.size() - 1; i++) {
        for (int j = 0; j < Toys.size() - i - 1; j++) {
            if (Toys[j].minAge > Toys[j + 1].minAge) {
                // меняем элементы местами
                temp = Toys[j];
                Toys[j] = Toys[j + 1];
                Toys[j + 1] = temp;
            }
        }
    }
    ShowAllToys(Toys);
}
void SortQuantity(vector<Toy>& Toys) {
    Toy temp;
    // Сортировка пузырьком
    for (int i = 0; i < Toys.size() - 1; i++) {
        for (int j = 0; j < Toys.size() - i - 1; j++) {
            if (Toys[j].count > Toys[j + 1].count) {
                // меняем элементы местами
                temp = Toys[j];
                Toys[j] = Toys[j + 1];
                Toys[j + 1] = temp;
            }
        }
    }
    ShowAllToys(Toys);
}