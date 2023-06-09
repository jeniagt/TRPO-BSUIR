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
    string username; // ����� ������������
    string password_hash; // ������������ ������
    string salt; // ���� ����������� � ������
    int role = 0; // ���� � ��������� (0-������������, 1- �����)
    int access = 0; // ��������� �������� (0 - ������� ������������� ������, 1 - ����������, 666 - ������������)
};

void CreateVector(vector<User>& Users); // �������� ������� �������������
void FillVector(vector<User>& Users, fstream& file); // �������� �� ����� � ������� ������ �� �������������
void FillFile(vector<User>& Users); // ������ ����� � ������������� ������� ������� 

void Registration(vector<User>& Users); // ����������� ������������
void Registration(vector<User>& Users, int access); // ����������� ������������ ��� ����������� ������� 

bool isLoginUnique(vector<User>& Users, string username); // �������� ������ �� ������������
void LoggedIn(vector<User>& Users); // �������� ������ � ������ ��� ����� ������������ 

string CreateSalt(); // �������� "����" ��� ���������� � ������� ��� ����������� 
unsigned long hash_function(string password, string salt); // ����������� ������ � "�����"

void ShowUsers(vector<User>& Users); // ���������� ������ �������������

void DeleteMode(vector<User>& Users); // ���� �������� ������������
vector <User> DeleteUser(vector<User>& Users, const int& n); // �������� ������������

void EditUsers(vector<User>& Users); // �������������� ������������
void Block(vector<User>& Users, int& n); // ����������/������������� ������������
void Confirm(vector<User>& Users, int& n); // ������������� ������������ ����� ��� �����������
void GetAdmin(vector<User>& Users, int& n); // ������������ �������������� ��� �������