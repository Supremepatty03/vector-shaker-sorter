#pragma once

using namespace std;

bool file_existance(const string& path);
bool file_not_created(const string& path);
bool is_forbidden_file_name(const string& fileName);
void save_result_to_file(vector<string> unsorted_data, vector<string> data);