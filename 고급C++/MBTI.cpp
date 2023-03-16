#include "ReadMBTIData.h"

ReadMBTIData::ReadMBTIData() {}

void ReadMBTIData::read_data(string file_path) {
    ifstream input_file(file_path);
    if (!input_file.is_open()) {
        cerr << "Failed to open input file" << endl;
        return;
    }

    int num_rows = 0;
    string line;
    while (getline(input_file, line)) {
        num_rows++;
    }
    input_file.clear();
    input_file.seekg(0, ios::beg);

    name_ = new string[num_rows];
    id_ = new string[num_rows];
    mbti_ = new string[num_rows];

    int i = 0;
    while (getline(input_file, line)) {
        stringstream ss(line);
        string cell;
        int j = 0;
        while (getline(ss, cell, ',')) {
            if (j == 0) {
                name_[i] = cell;
                   
            }
            else if (j == 1) {
                id_[i] = cell;
            }
            else if (j == 2) {
                mbti_[i] = cell;
            }
            j++;
        }
        i++;
    }
    input_file.close();
    num_rows_ = num_rows;
}


ReadMBTIData::~ReadMBTIData() {
    delete[] name_;
    delete[] id_;
    delete[] mbti_;
}

void ReadMBTIData::print_name()
{
    string M;
    cout << "MBTI: ";
    cin >> M;

    for (int i = 0; i < num_rows_; i++) {
        if ( M == mbti_[i])
            cout << name_[i] << endl;
    }
}


int main() {
 
    ReadMBTIData data;
    data.read_data("C:\\YeEunCPROGRAM\\advanced c++\\2023_Students.csv");
    data.print_name();

    return 0;
}