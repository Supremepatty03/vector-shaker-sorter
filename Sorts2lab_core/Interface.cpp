#include <iostream>
#include <string>
#include <windows.h>
#include "Functions.h"


using namespace std;


int main_menu(void) {
    string input = "";
    cout << endl << endl << " -----����-----" << endl;
    cout << " ��� �� ������ �������? " << endl;
    cout << " 1. ������� ������ ������� " << endl;
    cout << " 2. ������������ ��������� ������ " << endl;
    cout << " 3. ��������� ��������� " << endl;

    cout << " ������� 1, 2 ��� 3: ";
    while (true) {
        cin >> input;
        cin.ignore(INT_MAX, '\n');
        if (input.size() == 1 && (input[0] == '1' || input[0] == '2' || input[0] == '3' || input[0] == '4')) {
            return stoi(input);
        }
        cout << " ������� '1', '2' ��� '3': ";

    }
    return -1;
}
int file_menu(void)
{
    string input = "";

    cout << " ��� �� ������ �������? " << endl;
    cout << " 1. �������� ���������� ����� " << endl;
    cout << " 2. ������� ������ ��� ����� " << endl;

    cout << " ������� 1 ��� 2:";
    while (true) {
        cin >> input;
        cin.ignore(INT_MAX, '\n');
        if (input.size() == 1 && (input[0] == '1' || input[0] == '2')) {
            return stoi(input);
        }
        cout << " ������� '1' ��� '2': ";
    }
    return -1;
}
int file_save(void)
{
    string file_choise = "";
    cout << " ��������� ������ � ����?" << endl;
    cout << " 1. ��" << endl;
    cout << " 2. ��� " << endl;
    cout << " ������� 1 ��� 2: ";
    while (true) {
        cin >> file_choise;
        cin.ignore(INT_MAX, '\n');
        if (file_choise.size() == 1 && (file_choise[0] == '1' || file_choise[0] == '2')) {
            return stoi(file_choise);
        }
        cout << " ������� '1' ��� '2': ";
    }
    return -1;
}
void say_goodbye(void)
{
    cout << " ���������� ������." << endl;
    Sleep(600);
    cout << " ���������� ������.." << endl;
    Sleep(600);
    cout << " ���������� ������..." << endl;
    Sleep(600);
}