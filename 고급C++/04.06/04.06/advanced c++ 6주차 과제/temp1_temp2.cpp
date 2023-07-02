#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
class CStudent {
    string name;
    string id;
    string mbti;
public:
    CStudent() {}  //���� �𸣰� ���� �� default ������
    CStudent(string _name, string _id, string _mbti) : name(_name), id(_id), mbti(_mbti) {}  //�Լ� or ������ list -> ���⼱ list ��� , �ַ� ������ list ����ؼ� ����
    /* = > CStudent(string _name, string _id, string _mbti) {
                name = _name;
                id = _id   _> �Լ��� �����*/
    void set_students(string name, string id, string mbti) {
        this->name = name;  //��ü�� ��� ������ ����Ű�� ���� this, ��������
        this->id = id;
        this->mbti = mbti;
    }
    string get_name() {
        return name;
    }
    string get_id() {
        return id;
    }
    string get_mbti() {
        return mbti;
    }
};
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

    // print_data �Լ��� ��� �������� �ܼ�â�� ����ϴ� ������ �մϴ�. 
    // name_, id_, mbti_ �迭�� for loop�� ����� num_rows���� ����մϴ�. 
    // num_rows�� �� ���ڽ����� ����� �ִ� �Ű� ���� ������.
    void print_data() {
        for (int i = 0; i < num_rows_; i++) {
            cout << name_[i] << " " << id_[i] << " " << mbti_[i] << endl;
        }
    }
    int get_num_of_students() {  //�迭 �� ������
        return num_rows_;
    }
    CStudent* set_data(CStudent* _OStudent) {
        for (int i = 0; i < num_rows_; ++i) {
            _OStudent[i].set_students(name_[i], id_[i], mbti_[i]);
        }
        return _OStudent;
    }

    // �Ҹ����Դϴ�. 
    // �迭���� ���� �ð� �Ұ��� �����迭(�����͸� ����� �迭)�Դϴ�. 
    // ���ǿ��� HEAP MEMORY�� ����ϴ� ���, �̿� ���� �޸𸮸� ������ ��� �Ѵٰ� �����?
    ~ReadMBTIData() { 	// ��ü�� �����մϴ�. �Ҹ��� �Լ��� ~ ǥ�ø� �ϰ�, Ŭ���� �̸��� �״�� �� �ݴϴ�.
        delete[] name_; // name ��� ������ num_rows_ ��ŭ �����Ǵ� �迭�Դϴ�. �迭 ���� �� [] ǥ�ÿ� �Բ� ������ �ݴϴ�.
        delete[] id_;	// id, mbti ��� name ������ �����ϰ� �����մϴ�. 
        delete[] mbti_;
    }

    // �� Ŭ���������� private: ��� �������� Ŭ���� ���� �Ʒ��� �ֽ��ϴ�. 
    // �̷� ���� ������ �ͼ��� ������.
    // �ι�° ���ǿ��� private �������� �Ϲ������� ��ü�� '����'�� ��Ÿ���� �������� �����Ѵٰ� �߽��ϴ�.
    // �츮�� csv ���Ͽ��� �о�� �������� �̸�, id, mbti�Դϴ�.
    // ������ ��� �����͸� ����� dynamic array�� ��������ϴ�. 
    // ������ ��� ���� ������ �𸣱� �����Դϴ�.
private:
    string* name_; 	// �������� ����(dynamic)���� ��������ϴ�. heap memory�� �����Ͽ� stack �޸𸮰� �����Ǿ ����ְ� �մϴ�.
    string* id_;	// Heap memory�� ����ϴ� ������ ��ü�� ����, �Ҹ��� ���� ������� �����ϰ� �ͱ� �����Դϴ�. 
    string* mbti_;	// stack memory�� �ڷḦ �����ϸ� �Լ� ȣ���� ���� �� ������ ������ϴ�. ���� stack�� ������ �۾� ���� �����͸� ��� �������� ������ �־��.
    int num_rows_; 	// �� ���� �����͸� �о� ������ �������� ���̱� ������ ���� �������� �Ҵ��� �ʿ䰡 �����ϴ�. 
};
int main() {
    CStudent Sugeong[3];
    Sugeong[0].set_students("ABC", "2021", "ISTJ");
    Sugeong[1].set_students("DEF", "2022", "ISTP");
    Sugeong[2].set_students("GHI", "2023", "INFJ");
    CStudent* p;
    p = Sugeong;
    
   /* for (int i = 0; i < 3; ++i) {
        cout << i << "��° �������� �̸��� " << p->get_name() << endl;
        p++;
    } */

    string temp_name1, temp_name2;
    temp_name1 = p[0].get_name();  //���� �� ���� ������ ����Ű�� ��
    temp_name2 = (*p).get_name();
    cout << temp_name1 << endl;
    cout << temp_name2;

    return 0;
}
