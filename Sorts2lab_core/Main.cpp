#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <memory>
#include <string>
#include "Functions.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");
    cout << " ������������ ������ �2, ������� 1, ������� ����� / �������������� �����  ��.433 "<< endl;

    vector<string> data = {};
    vector<string> Sorted_data;
    string tmp;

    int data_amount;
    cout << " ������� ���������� ���������: " << endl;
    data_amount = if_integer();
    for (int i=0; i < data_amount; i++) 
    {
        cout << "������� �������� ��� �������� � " << i << ": " << endl;
        cin >> tmp;
        data.emplace_back(tmp);
    }

    cout << " �� ����� ��������� ������: ";
    show_data(data);

    cout << "\n" << endl;

    cout << " ��������������� ������: ";
    Sorted_data = shaker_sort(data);
    show_data(Sorted_data);

    cout << " \n ";

    cout << " ��������������� ������2: ";
    Sorted_data = number_sort(Sorted_data);
    show_data(Sorted_data);

    return 0;
}