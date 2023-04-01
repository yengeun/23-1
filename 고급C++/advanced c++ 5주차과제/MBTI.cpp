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

void ReadMBTIData::print_mbti()
{
    int e1 =0,e2 =0, e3=0, e4 =0, e5 =0, e6=0, e7=0, e8=0 ;
    int i1=0 ,i2=0, i3=0, i4=0, i5=0, i6=0, i7=0, i8 =0 ;

    for (int i = 0; i < num_rows_; i++) {
        if ("ESFP" == mbti_[i])
            e1++;
        else if ("ENFP" == mbti_[i])
            e2++;
        else if ("ESFJ" == mbti_[i])
            e3++;
        else if ("ENFJ" == mbti_[i])
            e4++;
        else if ("ESTP" == mbti_[i])
            e5++;
        else if ("ESTJ" == mbti_[i])
            e6++;
        else if ("ENTP" == mbti_[i])
            e7++;
        else if ("ENFJ" == mbti_[i])
            e8++;


        else if ("ISFP" == mbti_[i])
            i1++;
        else if ("INFP" == mbti_[i])
            i2++;
        else if ("ISFJ" == mbti_[i])
            i2++;
        else if ("INFJ" == mbti_[i])
            i2++;
        else if ("ISTP" == mbti_[i])
            i2++;
        else if ("ISTJ" == mbti_[i])
            i2++;
        else if ("INTP" == mbti_[i])
            i2++;
        else if ("INTJ" == mbti_[i])
            i2++;

        else
            continue;
        
    }

    cout << "ESFP: " << e1 << endl;
    cout << "ENFP: " << e2 << endl;
    cout << "ESFJ: " << e3 << endl;
    cout << "ENFJ: " << e4 << endl;
    cout << "ESTP: " << e5 << endl;
    cout << "ESTJ: " << e6 << endl;
    cout << "ENTP: " << e7 << endl;
    cout << "ENFJ: " << e8 << endl;

    cout << "ISFP: " << i1 << endl;
    cout << "INFP: " << i2 << endl;
    cout << "ISFJ: " << i3 << endl;
    cout << "INFJ: " << i4 << endl;
    cout << "ISTP: " << i5 << endl;
    cout << "ISTJ: " << i6 << endl;
    cout << "INTP: " << i7 << endl;
    cout << "INTJ: " << i8 << endl;
}


int main() {
 
    ReadMBTIData data;
    data.read_data("C:\\YeEunCPROGRAM\\advanced c++\\2023_Students.csv");
    data.print_mbti();

    return 0;
}