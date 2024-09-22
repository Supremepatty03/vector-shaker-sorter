#include <iostream>
#include <string>
#include <windows.h>
#include <ctime> 
#include <vector>
#include <algorithm>
#include "Functions.h"


using namespace std;

int if_integer(void) {
    int value = 0;
    cin >> value;
    while (!cin) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Введите число: ";
        cin >> value;
    }
    while (cin.get() != '\n');
    return value;
}

/*vector <string> shaker_sort(vector <string> data) {
    bool tmp = true;
    int n = 0;
    while (tmp) 
    {
        tmp = false;
        for (int i = 0; i < data.size()-n-1 ; i++) 
        {
            if (data[i] > data[i + 1]) 
            {
                swap(data[i], data[i + 1]);
                tmp = true;
            }
        }
        if (!tmp) break;
        n += 1;
        for (int i = static_cast<int>(data.size()) - n-1; i > 0; i--)
        {
            if (data[i] < data[i - 1]) 
            {
                swap(data[i], data[i - 1]);
                tmp = true;
            }
        }
    }


    return data;
*/

/*template <typename T>
vector<T> shaker_sort(vector<T> data) {
    bool tmp = true;
    int n = 0;
    while (tmp) {
        tmp = false;
        for (int i = 0; i < data.size() - n - 1; i++) {
            if (data[i] > data[i + 1]) {
                swap(data[i], data[i + 1]);
                tmp = true;
            }
        }
        if (!tmp) break;
        n += 1;
        for (int i = static_cast<int>(data.size()) - n - 1; i > 0; i--) {
            if (data[i] < data[i - 1]) {
                swap(data[i], data[i - 1]);
                tmp = true;
            }
        }
    }
    return data;
}*/
 /*vector <string> number_sort(vector <string> data) {
    vector<int> numbers;
    vector<int> Sorted_numbers;
    vector<string> f_numbers;
    bool first_element = true;
    int first_index = -1;
    for (int i = 0; i < data.size(); i++) 
    {
        try 
        { 
            int tmp = stoi(data[i]);
            numbers.emplace_back(tmp);
            if (first_element)
            {
                first_index = i;
            }
            first_element = false;
        }
        catch (...)
        {
            continue;
        }
    }
    if (first_index != -1)
    {
        Sorted_numbers = shaker_sort(numbers);

        for (int i = 0; i < Sorted_numbers.size(); i++) {
            //f_numbers.emplace_back(to_string(Sorted_numbers[i]));
            data.insert(data.begin() + first_index + i, to_string(Sorted_numbers[i]));
        }
    }
    return data;
}*/

vector<string> number_sort(vector<string> data) {
    vector<int> numbers;
    vector<int> Sorted_numbers;
    vector<string> f_numbers;
    bool first_element = true;
    int first_index = -1;

    // Находим все числа и запоминаем позицию первого
    for (int i = 0; i < data.size(); i++) {
        try {
            int tmp = stoi(data[i]);
            numbers.emplace_back(tmp);
            if (first_element) {
                first_index = i;
                first_element = false;
            }
        }
        catch (...) {
            continue;
        }
    }

    // Если были найдены числа, сортируем их
    if (first_index != -1) {
        Sorted_numbers = shaker_sort(numbers);

        // Удаляем старые элементы-числа из data
        data.erase(data.begin() + first_index, data.begin() + first_index + numbers.size());

        // Вставляем отсортированные числа обратно как строки
        for (int i = 0; i < Sorted_numbers.size(); i++) {
            data.insert(data.begin() + first_index + i, to_string(Sorted_numbers[i]));
        }
    }

    return data;
}

void show_data(vector<string> data) {
    for (int i=0; static_cast<int>(i) < data.size(); i++) {
        cout << data[i] << " |";
    }
}