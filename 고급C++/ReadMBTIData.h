//20211359 신예은 3주차 과제_01
#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class ReadMBTIData {
public:
    ReadMBTIData();
    void read_data(string file_path);
    void print_name();
    ~ReadMBTIData();

private:
    string* name_;
    string* id_;
    string* mbti_;
    string M;
    int num_rows_;
    
};
