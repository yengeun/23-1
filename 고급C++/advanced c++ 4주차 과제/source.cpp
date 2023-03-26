#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

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
        while (getline(input_file, line)) {   //j=0,1,2 -> 이름,id,mbti
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

    // 소멸자입니다. 포인터로 만들어준 다이나믹 어레이는 지워줘야 함
    // 배열들이 지난 시간 소개한 동적배열(포인터를 사용한 배열입니다). 
    // 지금 다 이해할 필요 없습니다. 익숙해 지는 과정이예요.
    ~ReadMBTIData() {
        delete[] name_;
        delete[] id_;
        delete[] mbti_;
    }

    // 이 클래스에서는 private: 멤버 변수들이 클래스 가장 아래에 있습니다. 
    // 이런 식의 구현도 익숙해 지세요.
    // 두번째 강의에서 private 영역에는 일반적으로 객체의 '상태'를 나타내는 변수들을 정의한다고 했습니다.
    // 우리가 csv 파일에서 읽어올 변수들은 이름, id, mbti입니다.
    // 변수를 모두 포인터를 사용해 dynamic array로 만들었습니다. 
    // 이유는 몇개의 행이 있을지 모르기 때문입니다.
    // 당장 직접할 수 있지는 않아도 돼요. '이런 식으로 하는 구나' 정도로 보고 넘어갑니다. 
    // 다만 이 변수들을 사용할 줄 알아야 겠죠? 세번째 강의에서 볼 거예요.
private:
    string* name_;
    string* id_;
    string* mbti_;
    int num_rows_;
};

int main() {
    // 클래스 이름, 그리고 클래스로 만들 객체 이름을 써줍니다.
    ReadMBTIData data; 
    
    // 이제 클래스에 구현된 read_data 함수를 이용해 csv 파일을 읽어 보겠습니다.
    // 클래스로 돌아가서 read_data 함수를 보면 csv 파일 명을 읽도록 되어 있어요.
   
    //data.read_data("2023_Students.csv");                          // 내 소스 파일이 있는 곳에 csv 파일을 두면 이렇게 경로를 쓰지 않아도 됩니다. 
    //data.read_data("C:\\Users\\Sungshin\\2023_Students.csv");     // 내 소스 파일이 있는 곳이 아닌 다른 위치에 있는 곳에 있는 csv 파일을 읽고 싶다면 경로를 씁니다. 단, \ 표시를 하나가 아니라 두개(\\) 해주는 것을 기억하세요.
    data.read_data("C:\\YeEunCPROGRAM\\advanced c++\\2023_Students.csv");
    
    
    // 클래스의 print_data 함수를 이용해 콘솔창에 출력해 줍니다. 
    data.print_data();                     

    return 0;
}
