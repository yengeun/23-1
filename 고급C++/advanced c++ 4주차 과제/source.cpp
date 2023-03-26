#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class ReadMBTIData {    // Ŭ���� ����, �׸��� ���ϴ� Ŭ���� �̸��� ����մϴ�.       
public:                 // �̹� �忡 ��� �����Դϴ�. ��� �Լ������ �� ���ϴ�.
    ReadMBTIData() {}   // Ŭ������ ��ü�� ���� �� ����ϴ� �������Դϴ�. Ŭ������ �̸��� ���ƿ�. 

    // �Ʒ� csv ������ ���� read_data �Լ��� ���� ���� ����� ���� �� �ʿ䰡 �����ϴ�. 
    // ���� ����� ���� ���ϴ�. ��ȯ�ϴ� ������ ����, �̸��� read_data��, �Ű������� string ������ ���ϸ� �ʿ��մϴ�. //
    // ���� ������ ���ڽ��� �׳� �μ���.
    void read_data(string file_path) {
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
        while (getline(input_file, line)) {   //j=0,1,2 -> �̸�,id,mbti
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

    // print_data �Լ��� ��� �������� �ܼ�â�� ����ϴ� ������ �մϴ�. 
    // name_, id_, mbti_ �迭�� for loop�� ����� num_rows���� ����մϴ�. 
    // num_rows�� �� ���ڽ����� ����� �ִ� �Ű� ���� ������.
    void print_data() {
        for (int i = 0; i < num_rows_; i++) {
            cout << name_[i] << " " << id_[i] << " " << mbti_[i] << endl;
        }
    }

    // �Ҹ����Դϴ�. �����ͷ� ������� ���̳��� ��̴� ������� ��
    // �迭���� ���� �ð� �Ұ��� �����迭(�����͸� ����� �迭�Դϴ�). 
    // ���� �� ������ �ʿ� �����ϴ�. �ͼ��� ���� �����̿���.
    ~ReadMBTIData() {
        delete[] name_;
        delete[] id_;
        delete[] mbti_;
    }

    // �� Ŭ���������� private: ��� �������� Ŭ���� ���� �Ʒ��� �ֽ��ϴ�. 
    // �̷� ���� ������ �ͼ��� ������.
    // �ι�° ���ǿ��� private �������� �Ϲ������� ��ü�� '����'�� ��Ÿ���� �������� �����Ѵٰ� �߽��ϴ�.
    // �츮�� csv ���Ͽ��� �о�� �������� �̸�, id, mbti�Դϴ�.
    // ������ ��� �����͸� ����� dynamic array�� ��������ϴ�. 
    // ������ ��� ���� ������ �𸣱� �����Դϴ�.
    // ���� ������ �� ������ �ʾƵ� �ſ�. '�̷� ������ �ϴ� ����' ������ ���� �Ѿ�ϴ�. 
    // �ٸ� �� �������� ����� �� �˾ƾ� ����? ����° ���ǿ��� �� �ſ���.
private:
    string* name_;
    string* id_;
    string* mbti_;
    int num_rows_;
};

int main() {
    // Ŭ���� �̸�, �׸��� Ŭ������ ���� ��ü �̸��� ���ݴϴ�.
    ReadMBTIData data; 
    
    // ���� Ŭ������ ������ read_data �Լ��� �̿��� csv ������ �о� ���ڽ��ϴ�.
    // Ŭ������ ���ư��� read_data �Լ��� ���� csv ���� ���� �е��� �Ǿ� �־��.
   
    //data.read_data("2023_Students.csv");                          // �� �ҽ� ������ �ִ� ���� csv ������ �θ� �̷��� ��θ� ���� �ʾƵ� �˴ϴ�. 
    //data.read_data("C:\\Users\\Sungshin\\2023_Students.csv");     // �� �ҽ� ������ �ִ� ���� �ƴ� �ٸ� ��ġ�� �ִ� ���� �ִ� csv ������ �а� �ʹٸ� ��θ� ���ϴ�. ��, \ ǥ�ø� �ϳ��� �ƴ϶� �ΰ�(\\) ���ִ� ���� ����ϼ���.
    data.read_data("C:\\YeEunCPROGRAM\\advanced c++\\2023_Students.csv");
    
    
    // Ŭ������ print_data �Լ��� �̿��� �ܼ�â�� ����� �ݴϴ�. 
    data.print_data();                     

    return 0;
}
