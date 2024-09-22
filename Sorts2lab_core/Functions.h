#pragma once
#include <vector>
using namespace std;
int if_integer(void);
template <typename T>
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
}

vector <string> number_sort(vector <string> data);
void show_data(vector<string> data);
