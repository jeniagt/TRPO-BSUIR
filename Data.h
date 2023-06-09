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
    string name; // �������� �������
    double price; // ���� �������
    string county; // ������������(������)
    int count; // ���������� � �������
    int minAge; // ����������� ������� ��� �������
};

void CreateVector(vector<Toy>& Toys); // �������� ������� 
void FillVector(vector<Toy>& Toys, fstream& file); // �������� �� ����� � ������� ������ �� ��������
void Filling(vector<Toy>& Toys); // ������ ����� �� �������� ������� ������� 

void ShowAllToys(vector<Toy>& Toys); // ���������� ������ � �������� �������� ��� ������ ������ 
void Cap(); // ����� ������� � ���������
void ShowToy(Toy Show, int& n); // ���������� ���������� �������

void addToy(vector<Toy>& Toys); // ���������� ������� � ������ ��������
Toy EntryToy(); // ���� ������ �� �������

void EditToy(vector<Toy>& Toys); // �������������� �������

void DeleteMode(vector<Toy>& Toys); // ���� �������� ������� 
vector<Toy> DeleteToy(vector<Toy>& Toys, const int& n); // �������� ������� �� �������

void MenuSearch(vector<Toy>& Toys); // ���� ������
void SearchAge(vector<Toy>& Toys); // ����� ������� �� ��������(�������������� �������)
void SearchName(vector<Toy>& Toys); // ����� ������� �� ��������
void SearchPrice(vector<Toy>& Toys); // ����� ������� �� ����

void MenuSort(vector<Toy>& Toys); // ���� ����������
void SortAlphabet(vector<Toy>& Toys); // ���������� �� ��������
void SortAge(vector<Toy>& Toys); // ���������� �� ��������
void SortQuantity(vector<Toy>& Toys); // ���������� �� ����������