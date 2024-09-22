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
    cout << " \n";
}
vector<string> default_data (void)
{
    string tmp="";
    vector<string> default_list;
    srand(static_cast<unsigned int>(time(NULL)));
    int length = rand() % 20 + 2;




    for (int i = 0; i < length; i++) 
    {
        int j = rand() % 7 + 2;
        tmp = "";
        for (int k = 1; k < j; k++) {
            int random_first_char_type = rand() % 2; // 0 = заглавная англ., 1 = строчная англ.
            char random_char;

            if (random_first_char_type == 0) {
                random_char = rand() % 26 + 65; // A-Z
            }
            else
            {
                random_char = rand() % 26 + 97; // a-z
            }
            tmp += random_char;

            ////////////////////////////////////////
            int random_char_type = rand() % 5; // 0 = цифра, 1 = заглавная англ., 2 = строчная англ., 3 = русский, 4 = спецсимвол
            //char random_char;

            if (random_char_type == 0) {
                random_char = rand() % 10 + 48; // 0-9
            }
            else if (random_char_type == 1) {
                random_char = rand() % 26 + 65; // A-Z
            }
            else if (random_char_type == 2) {
                random_char = rand() % 26 + 97; // a-z
            }
            else if (random_char_type == 3) {
                if (rand() % 2 == 0) {
                    random_char = rand() % 32 + 224; // а-я
                }
                else {
                    random_char = rand() % 32 + 192; // А-Я
                }
            }
            else {
                // Спецсимволы 
                int random_special = rand() % 4;
                if (random_special == 0) {
                    random_char = rand() % 15 + 33; // Символы !-/
                }
                else if (random_special == 1) {
                    random_char = rand() % 7 + 58;  // Символы :-@
                }
                else if (random_special == 2) {
                    random_char = rand() % 6 + 91;  // Символы [-`
                }
                else {
                    random_char = rand() % 4 + 123; // Символы {-~
                }
            }

            tmp += random_char;
        }
        default_list.emplace_back(tmp);
    }
    return default_list;
}
string read_until_space() {
    string input;
    string result;

    getline(cin, input);

    size_t space_pos = input.find(' ');

    if (space_pos != string::npos) {
        result = input.substr(0, space_pos);
    }
    else {
        result = input;
    }

    return result;
}