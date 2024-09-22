#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <regex>
#include "Interface.h"
#include "Functions.h"
#include "Filefunc.h"

bool file_existance(const string& path)
{
    if (ifstream(path))
    {
        cout << "Файл с таким именем уже существует!" << endl;
        return true;
    }
    else
        return false;
}

bool file_not_created(const string& path)
{
    if (ifstream(path))
    {
        return false;
    }
    else
    {
        cout << endl;
        return true;
    }
}
bool is_forbidden_file_name(const string& fileName) {
    regex forbiddenNames("(CON|NUL|AUX|PRN|COM\\d|LPT\\d)(\\..*)?", regex_constants::icase);
    return regex_match(fileName, forbiddenNames);
}

void save_result_to_file(vector<string> unsorted_data, vector<string> data)
{
    string fileName;
    do {
        cout << " Введите имя файла для сохранения: ";
        cin >> fileName;
        cin.ignore(INT_MAX, '\n');
        while (is_forbidden_file_name(fileName))
        {
            cout << " Создание файла с таким именем запрещено в Windows." << endl;
            cout << " Введите имя файла для сохранения: ";
            cin >> fileName;
            cin.ignore(INT_MAX, '\n');
        }
        while (file_existance(fileName))
        {
            int response;
            cout << " Файл с именем " << fileName << " уже существует. ";
            response = file_menu();

            if (response == 1)
            {
                cout << " Данные удалены!" << endl;
                break;
            }
            else
            {
                cout << " Введите новое имя файла: ";
                cin >> fileName;
                cin.ignore(INT_MAX, '\n');
                //break;
            }
        }
        ofstream file(fileName);
        if (!file.is_open()) {
            cout << " Название файла содержит недопустимые символы или файл закрыт для записи." << endl;
            save_result_to_file(unsorted_data, data);
            break;
        }
        file << "Начальный массив" << endl;
        for (int i = 0; i < unsorted_data.size(); i++)
        {
                file << unsorted_data[i] << "|" << "\t";
        }
        file << "\n";
        file << "Отсортированный массив" << endl;
        for (int i = 0; i < data.size(); i++)
        {
                file << data[i] << "|" << "\t";
        }
        file << endl;
        file.close();
        if (!file_not_created(fileName))
            cout << " Данные успешно сохранены в файл " << fileName << endl;

    } while (file_not_created(fileName));
}