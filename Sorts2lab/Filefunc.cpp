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
        cout << "���� � ����� ������ ��� ����������!" << endl;
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
        cout << " ������� ��� ����� ��� ����������: ";
        cin >> fileName;
        cin.ignore(INT_MAX, '\n');
        while (is_forbidden_file_name(fileName))
        {
            cout << " �������� ����� � ����� ������ ��������� � Windows." << endl;
            cout << " ������� ��� ����� ��� ����������: ";
            cin >> fileName;
            cin.ignore(INT_MAX, '\n');
        }
        while (file_existance(fileName))
        {
            int response;
            cout << " ���� � ������ " << fileName << " ��� ����������. ";
            response = file_menu();

            if (response == 1)
            {
                cout << " ������ �������!" << endl;
                break;
            }
            else
            {
                cout << " ������� ����� ��� �����: ";
                cin >> fileName;
                cin.ignore(INT_MAX, '\n');
                //break;
            }
        }
        ofstream file(fileName);
        if (!file.is_open()) {
            cout << " �������� ����� �������� ������������ ������� ��� ���� ������ ��� ������." << endl;
            save_result_to_file(unsorted_data, data);
            break;
        }
        file << "��������� ������" << endl;
        for (int i = 0; i < unsorted_data.size(); i++)
        {
                file << unsorted_data[i] << "|" << "\t";
        }
        file << "\n";
        file << "��������������� ������" << endl;
        for (int i = 0; i < data.size(); i++)
        {
                file << data[i] << "|" << "\t";
        }
        file << endl;
        file.close();
        if (!file_not_created(fileName))
            cout << " ������ ������� ��������� � ���� " << fileName << endl;

    } while (file_not_created(fileName));
}