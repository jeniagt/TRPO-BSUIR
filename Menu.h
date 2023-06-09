#pragma once
#include <iostream>
#include <vector>

#include "Users.h"
#include "Data.h"
using namespace std;

void UserMenu(); // ����� ���� ��� ������ �������� ������������
void AdminMenu(vector<User>& Users); // ����� ���� ��� ������ ��������������
void AccountMenu(vector<User>& Users); // ����� ���� ������ � ��������������
void DataMenu(); // ����� ���� ������ � �������
void EditMenu(vector<Toy>& Toys); // ����� ���� �������������� ������
void ProcessingMenu(vector<Toy>& Toys); // ����� ���� ��������� ������(����������, �����)