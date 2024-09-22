#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>
#include <memory>
#include <string>
#include "Functions.h"
#include "Interface.h"
#include "Filefunc.h"
#define SAVE_TO_FILE 1


using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");
    cout << " Лабораторная работа №2, вариант 1, Тарасов Артем / Александрычева Алена  гр.433 "<< endl;

    vector<string> data = {};
    vector<string> Sorted_data;
    string tmp;
    int menu = 0;
    int choise = 0;
    bool not_first_try = false;

    enum choise_options
    {
        BY_HIMSELF = 1,
        DEFAULT_LIST = 2,
        EXIT = 3
    };

    menu = main_menu();

    do {
        if (not_first_try)
            menu = main_menu();

        if (menu == EXIT)
            break;

        if (menu == BY_HIMSELF)
        {
            int data_amount;
            cout << " Введите количество элементов: " << endl;
            data_amount = if_integer();
            for (int i = 0; i < data_amount; i++)
            {
                cout << "Введите значение для элемента № " << i+1 << ": " << endl;
                tmp = read_until_space();
                data.emplace_back(tmp);
            }
        }
        else if (menu == DEFAULT_LIST)
        {
            data = default_data();
        }

        cout << " Вы ввели следующие данные: ";
        show_data(data);


        //cout << " Отсортированные данные: ";
        Sorted_data = shaker_sort(data);
        //show_data(Sorted_data);

        cout << " \n";

        cout << " Отсортированные данные: ";
        Sorted_data = number_sort(Sorted_data);
        show_data(Sorted_data);

        if (file_save() == SAVE_TO_FILE) {
            save_result_to_file(data, Sorted_data);
        }
        not_first_try = true;
        data.clear();
    } while (menu != EXIT);
    say_goodbye();
    return 0;
}