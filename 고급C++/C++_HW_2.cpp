// 20211359 신예은 C++ 과제2
#include <iostream>
#include <string>

using namespace std;


class MBTI
    {
    public:
        string name; //데이터 필드
        string mbti;

    };

int main()
{

    string mymbti;
    cout << "MBTI: "; 
    cin >> mymbti;


    MBTI Stu[43]; // 학생들을 객체로 생성

    Stu[0].name = "신혜빈"; Stu[0].mbti = "ESFJ";
    Stu[1].name = "정혜빈"; Stu[1].mbti = "ISTJ";
    Stu[2].name = "황지원"; Stu[2].mbti = "INFP";
    Stu[3].name = "문현수"; Stu[3].mbti = "INFJ";
    Stu[4].name = "고원정"; Stu[4].mbti = "ISFP";
    Stu[5].name = "김성은"; Stu[5].mbti = "INTP";
    Stu[6].name = "김수연"; Stu[6].mbti = "ISTP";
    Stu[7].name = "김은비"; Stu[7].mbti = "ENFP";
    Stu[8].name = "김은지"; Stu[8].mbti = "ISFP";
    Stu[9].name = "김지윤"; Stu[9].mbti = "ESFJ";
    Stu[10].name = "노유정"; Stu[10].mbti = "ISTP";
    Stu[11].name = "문수호"; Stu[11].mbti = "ESTP";
    Stu[12].name = "박시현"; Stu[12].mbti = "ENFJ";
    Stu[13].name = "박지선"; Stu[13].mbti = "ENTJ";
    Stu[14].name = "서미라"; Stu[14].mbti = "ESFJ";
    Stu[15].name = "서지우"; Stu[15].mbti = "INTP";
    Stu[16].name = "안다연"; Stu[16].mbti = "ENFJ";
    Stu[17].name = "우지윤"; Stu[17].mbti = "ESFJ";
    Stu[18].name = "이수아"; Stu[18].mbti = "ISTP";
    Stu[19].name = "이정연"; Stu[19].mbti = "ESTJ";
    Stu[20].name = "이채영"; Stu[20].mbti = "ISFJ";
    Stu[21].name = "이채원"; Stu[21].mbti = "ISTP";
    Stu[22].name = "임다인"; Stu[22].mbti = "ESFJ";
    Stu[23].name = "임은서"; Stu[23].mbti = "INFP";
    Stu[24].name = "전유나"; Stu[24].mbti = "ISTP";
    Stu[25].name = "전지연"; Stu[25].mbti = "INFP";
    Stu[26].name = "정민서"; Stu[26].mbti = "ISFP";
    Stu[27].name = "정은주"; Stu[27].mbti = "ESTP";
    Stu[28].name = "정현정"; Stu[28].mbti = "INFP";
    Stu[29].name = "한송미"; Stu[29].mbti = "INFP";
    Stu[30].name = "한지은"; Stu[30].mbti = "ISTP";
    Stu[31].name = "허채윤"; Stu[31].mbti = "ISTJ";
    Stu[32].name = "홍지현"; Stu[32].mbti = "ENFP";
    Stu[33].name = "황시은"; Stu[33].mbti = "ISTJ";
    Stu[34].name = "황예원"; Stu[34].mbti = "ISFJ";
    Stu[35].name = "황지은"; Stu[35].mbti = "ISFP";
    Stu[36].name = "황채원"; Stu[36].mbti = "ISTP";
    Stu[37].name = "김유나"; Stu[37].mbti = "ESTJ";
    Stu[38].name = "황소윤"; Stu[38].mbti = "ISTP";
    Stu[39].name = "황지원"; Stu[39].mbti = "INTP";
    Stu[40].name = "신예은"; Stu[40].mbti = "ESFP";
    Stu[41].name = "정혜민"; Stu[41].mbti = "ISTP";
    Stu[42].name = "강수현"; Stu[42].mbti = "ISTP";


    for (int i = 0; i < 43; i++)
    {
        if (Stu[i].mbti == mymbti) // 입력한 mbti와 같은 학생 찾아서 출력
            cout << Stu[i].name << endl;
    }
 
    return 0;
}