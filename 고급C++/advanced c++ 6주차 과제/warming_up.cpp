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
    CStudent(string _name, string _id, string _mbti) {
               name = _name;
               id = _id;
               mbti = _mbti;
    }
    void set_students(string name, string id, string mbti) {
        this->name = name;
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
    // Ŭ���� �̸�, �׸��� Ŭ������ ���� ��ü �̸��� ���ݴϴ�.
    ReadMBTIData data;

    // ���� Ŭ������ ������ read_data �Լ��� �̿��� csv ������ �о� ���ڽ��ϴ�.
    // Ŭ������ ���ư��� read_data �Լ��� ���� csv ���� ���� �е��� �Ǿ� �־��.

    data.read_data("2023_Students.csv");                          // �� �ҽ� ������ �ִ� ���� csv ������ �θ� �̷��� ��θ� ���� �ʾƵ� �˴ϴ�. 
    //data.read_data("C:\\Users\\Sungshin\\2023_Students.csv");     // �� �ҽ� ������ �ִ� ���� �ƴ� �ٸ� ��ġ�� �ִ� ���� �ִ� csv ������ �а� �ʹٸ� ��θ� ���ϴ�. ��, \ ǥ�ø� �ϳ��� �ƴ϶� �ΰ�(\\) ���ִ� ���� ����ϼ���.
    //data.read_data("G:\\�� ����̺�\\Class 2023\\Advnaced Cpp\\2023_Students.csv");

    // Ŭ������ print_data �Լ��� �̿��� �ܼ�â�� ����� �ݴϴ�. 
    data.print_data();

    /*
    // !!!! �ɼ� ���� �Դϴ� !!! //
    ģ������ ���� ��ü�� ����� ������.
    ���� ���� �� ����ó�� ģ�� Ŭ������ �����, ������, getter, setter�� ����� �ִ� ���� �Ȱ����ϴ�.
    �׸��� main �Լ����� �ش� Ŭ������ �̿��� �������� ��ü�� ����� �˴ϴ�(�����ڷ� 24��).
    �������� ��ü�� ����� ��ü�� ������ ��� �ϱ� ������, �Ҹ��ڵ� ������ ������(���� �ڷ� 29�� ����)
    �������� ����� ��ü�� ���� �� source.cpp �ڵ忡�� ReadMBTIData�� ��� ������ num_rows_ ��ŭ ����� �ָ� �ǰ���?

    �������� ��ü�� ���� �� ��ü�� ��� ������ �����Ͽ� MBTI ���� ����� ģ������ �ִ��� Ȯ���� ������.
    ���� �ð��� ��� string class�� compare ��� �Լ��� ����� ���ϴ�.
    */

    // �� ���� ��ü�� ������ ó������ �� ���� �����ϴ�.
    // CSV ������ ���� �� �� ���� ����?
    // �̷��� ���߿� ��� ��ü�� ������ �����ϴ� ��쿡 �������� ��ü�� ����� �˴ϴ�. 
    // ����, CSV ������ �о� �� ���� ��ü�� �ʿ����� ���ô�. 
    int num_of_students;                            // �� ���� �л��� ���� �� ������ �����,
    // �� ���� ��� �ؾ� ����? 
    // ReadMBTIData�� ����� �л��� �ִ��� num_rows_ ������ ����Ǿ� ������, getter ���� ��� ����?
    // ReadMBTIData Ŭ������ get_num_of_students ��� �Լ��� ����� �� ���� �л��� �ִ��� �ܺο��� ������ �� �ֵ��� �մϴ�.
    num_of_students = data.get_num_of_students();   // ���� get_num_of_students �Լ��� �̿��� �� ���� �л��� �ִ��� �����ɴϴ�.

    CStudent* OStudent = new CStudent[num_of_students]; // ���� �������� ��� ��ü�� ������ �� �� �ְ� �Ǿ����ϴ�. ���� ó�� ����ϴ�. �� �޸� ������ ���� ���� new Ű���带 ����մϴ�. 
    //Ŭ���� �̸�* ��ü�̸� = new Ŭ�����̸�(������)[]

    // ���� �������� �� �޸𸮿� ���� �л� ��ü�� ������ϴ�. ���⿡ CSV ���� �����͸� �Է��� ���ô�. 
    // �־��� ReadMBTIData Ŭ������ print_data�� ���� ����� �� �� �־��. �����ʹ� ReadMBTIData Ŭ������ ���� data ��ü�� �ֽ��ϴ�. 
    // ��� �ִ� OStudent ��ü�� data ��ü�� ���� �����͸� �޾ƿ����� �սô�.

    data.set_data(OStudent);

    // �ɼ� ������ mbti�� ���� ���� �� ���� �л��� �ִ��� �˾ƺ��� �����Դϴ�. 
    // mbti�� ������ ������ �δ� ���� �ڷᱸ���� �˰����� ������, ������ �� ������� �𸣴� �ϳ��� �ϰڽ��ϴ�.
    // �츮 �л����� �� ������ mbti�� �ִ��� ���ô�. 
    string mbti_table[16] = { "ISTJ", "ISTP", "INFJ", "INTJ", "ISFJ", "ISFP", "INFP", "INTP", "ESTJ", "ESFP", "ENFP", "ENTP", "ESFJ", "ESTP", "ENFJ", "ENTJ" };
    int idx_table[16];              // ������ MBTI ���� �� ���� �л��� �ִ��� �����Ϸ��� �迭�� ����ϴ�.
    for (int i = 0; i < 16; ++i) {  // ������ MBTI�� �̿��� �л����� ���� Ȯ���ϸ鼭, ���� MBTI�� ���� ������ idx_table�� ī���� �մϴ�.
        idx_table[i] = 0;           // �ʱ�ȭ ��Ű��,
        for (int j = 0; j < num_of_students; ++j) {                     // ��� �л����� Ȯ���ϸ鼭,
            if (mbti_table[i].compare(OStudent[j].get_mbti()) == 0) {   // �ش� MBTI�� ���� / []�ȿ� string ���� �� 0�� ����
                idx_table[i]++;                                         // ī���� �մϴ�.
            }
        }
    }
    for (int i = 0; i < 16; ++i) {                              // �׸��� 16���� MBTI�� ����
        cout << mbti_table[i] << " : " << idx_table[i] << endl; // �� ���� �л��� �ִ��� ����� �ݴϴ�. 
    }

    delete[] OStudent;
    return 0;
}
