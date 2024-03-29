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
    CStudent() {}  //아직 모르고 있을 때 default 생성자
    CStudent(string _name, string _id, string _mbti) : name(_name), id(_id), mbti(_mbti) {}  //함수 or 생성자 list -> 여기선 list 사용 , 주로 생성자 list 사용해서 생성
    /* = > CStudent(string _name, string _id, string _mbti) {
                name = _name;
                id = _id   _> 함수로 만들기*/
    void set_students(string name, string id, string mbti) {
        this->name = name;  //객체의 멤버 변수를 가르키기 위한 this, 포인터임
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
class ReadMBTIData {    // 클래스 선언, 그리고 원하는 클래스 이름을 사용합니다.       
public:                 // 이번 장에 배울 내용입니다. 멤버 함수들부터 써 봅니다.
    ReadMBTIData() {}   // 클래스로 객체를 만들 때 사용하는 생성자입니다. 클래스와 이름이 같아요. 

    // 아래 csv 파일을 읽을 read_data 함수는 지금 구현 방법은 전혀 알 필요가 없습니다. 
    // 선언 방법만 보고 갑니다. 반환하는 내용이 없고, 이름은 read_data고, 매개변수는 string 형태의 파일명만 필요합니다. //
    // 안의 내용은 블랙박스로 그냥 두세요.
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

    // print_data 함수는 멤버 변수들을 콘솔창에 출력하는 역할을 합니다. 
    // name_, id_, mbti_ 배열을 for loop를 사용해 num_rows까지 출력합니다. 
    // num_rows는 위 블랙박스에서 계산해 주니 신경 쓰지 마세요.
    void print_data() {
        for (int i = 0; i < num_rows_; i++) {
            cout << name_[i] << " " << id_[i] << " " << mbti_[i] << endl;
        }
    }
    int get_num_of_students() {  //배열 몇 개인지
        return num_rows_;
    }
    CStudent* set_data(CStudent* _OStudent) {
        for (int i = 0; i < num_rows_; ++i) {
            _OStudent[i].set_students(name_[i], id_[i], mbti_[i]);
        }
        return _OStudent;
    }

    // 소멸자입니다. 
    // 배열들이 지난 시간 소개한 동적배열(포인터를 사용한 배열)입니다. 
    // 강의에서 HEAP MEMORY를 사용하는 경우, 이와 같이 메모리를 해제해 줘야 한다고 배웠죠?
    ~ReadMBTIData() { 	// 객체를 삭제합니다. 소멸자 함수는 ~ 표시를 하고, 클래스 이름을 그대로 써 줍니다.
        delete[] name_; // name 멤버 변수는 num_rows_ 만큼 생성되는 배열입니다. 배열 삭제 시 [] 표시와 함께 삭제해 줍니다.
        delete[] id_;	// id, mbti 모두 name 변수와 동일하게 삭제합니다. 
        delete[] mbti_;
    }

    // 이 클래스에서는 private: 멤버 변수들이 클래스 가장 아래에 있습니다. 
    // 이런 식의 구현도 익숙해 지세요.
    // 두번째 강의에서 private 영역에는 일반적으로 객체의 '상태'를 나타내는 변수들을 정의한다고 했습니다.
    // 우리가 csv 파일에서 읽어올 변수들은 이름, id, mbti입니다.
    // 변수를 모두 포인터를 사용해 dynamic array로 만들었습니다. 
    // 이유는 몇개의 행이 있을지 모르기 때문입니다.
private:
    string* name_; 	// 변수들을 동적(dynamic)으로 만들었습니다. heap memory에 저장하여 stack 메모리가 해제되어도 살아있게 합니다.
    string* id_;	// Heap memory를 사용하는 이유는 객체의 생성, 소멸을 내가 마음대로 조절하고 싶기 때문입니다. 
    string* mbti_;	// stack memory에 자료를 저장하면 함수 호출이 끝날 때 변수가 사라집니다. 또한 stack은 공간이 작아 많은 데이터를 담기 부적합한 이유도 있어요.
    int num_rows_; 	// 몇 개의 데이터를 읽어 올지는 정해지는 값이기 때문에 굳이 동적으로 할당할 필요가 없습니다. 
};
int main() {
    CStudent Sugeong[3];
    Sugeong[0].set_students("ABC", "2021", "ISTJ");
    Sugeong[1].set_students("DEF", "2022", "ISTP");
    Sugeong[2].set_students("GHI", "2023", "INFJ");
    CStudent* p;
    p = Sugeong;
    
   /* for (int i = 0; i < 3; ++i) {
        cout << i << "번째 수정이의 이름은 " << p->get_name() << endl;
        p++;
    } */

    string temp_name1, temp_name2;
    temp_name1 = p[0].get_name();  //만든 적 없는 공간을 가르키게 됨
    temp_name2 = (*p).get_name();
    cout << temp_name1 << endl;
    cout << temp_name2;

    return 0;
}
