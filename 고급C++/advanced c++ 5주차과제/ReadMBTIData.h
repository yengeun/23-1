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
    void print_mbti();
    ~ReadMBTIData();

private:
    string* name_;
    string* id_;
    string* mbti_;
    int e1, e2, e3, e4, e5, e6, e7, e8 ;
    int i1, i2, i3, i4, i5, i6, i7, i8; 
    int num_rows_;
    
};
