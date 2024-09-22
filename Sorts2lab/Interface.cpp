#include <iostream>
#include <string>
#include <windows.h>
#include "Functions.h"


using namespace std;


int main_menu(void) {
    string input = "";
    cout << endl << endl << " -----Меню-----" << endl;
    cout << " Что вы хотите сделать? " << endl;
    cout << " 1. Создать список вручную " << endl;
    cout << " 2. Использовать шаблонный список " << endl;
    cout << " 3. Завершить программу " << endl;

    cout << " Введите 1, 2 или 3: ";
    while (true) {
        cin >> input;
        cin.ignore(INT_MAX, '\n');
        if (input.size() == 1 && (input[0] == '1' || input[0] == '2' || input[0] == '3' || input[0] == '4')) {
            return stoi(input);
        }
        cout << " Введите '1', '2' или '3': ";

    }
    return -1;
}
int file_menu(void)
{
    string input = "";

    cout << " Что вы хотите сделать? " << endl;
    cout << " 1. Очистить содержимое файла " << endl;
    cout << " 2. Указать другое имя файла " << endl;

    cout << " Введите 1 или 2:";
    while (true) {
        cin >> input;
        cin.ignore(INT_MAX, '\n');
        if (input.size() == 1 && (input[0] == '1' || input[0] == '2')) {
            return stoi(input);
        }
        cout << " Введите '1' или '2': ";
    }
    return -1;
}
int file_save(void)
{
    string file_choise = "";
    cout << " Сохранить данные в файл?" << endl;
    cout << " 1. Да" << endl;
    cout << " 2. Нет " << endl;
    cout << " Введите 1 или 2: ";
    while (true) {
        cin >> file_choise;
        cin.ignore(INT_MAX, '\n');
        if (file_choise.size() == 1 && (file_choise[0] == '1' || file_choise[0] == '2')) {
            return stoi(file_choise);
        }
        cout << " Введите '1' или '2': ";
    }
    return -1;
}
void say_goodbye(void)
{
    cout << " Завершение работы." << endl;
    Sleep(600);
    cout << " Завершение работы.." << endl;
    Sleep(600);
    cout << " Завершение работы..." << endl;
    Sleep(600);
}