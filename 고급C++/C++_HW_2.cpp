// 20211359 �ſ��� C++ ����2
#include <iostream>
#include <string>

using namespace std;


class MBTI
    {
    public:
        string name; //������ �ʵ�
        string mbti;

    };

int main()
{

    string mymbti;
    cout << "MBTI: "; 
    cin >> mymbti;


    MBTI Stu[43]; // �л����� ��ü�� ����

    Stu[0].name = "������"; Stu[0].mbti = "ESFJ";
    Stu[1].name = "������"; Stu[1].mbti = "ISTJ";
    Stu[2].name = "Ȳ����"; Stu[2].mbti = "INFP";
    Stu[3].name = "������"; Stu[3].mbti = "INFJ";
    Stu[4].name = "�����"; Stu[4].mbti = "ISFP";
    Stu[5].name = "�輺��"; Stu[5].mbti = "INTP";
    Stu[6].name = "�����"; Stu[6].mbti = "ISTP";
    Stu[7].name = "������"; Stu[7].mbti = "ENFP";
    Stu[8].name = "������"; Stu[8].mbti = "ISFP";
    Stu[9].name = "������"; Stu[9].mbti = "ESFJ";
    Stu[10].name = "������"; Stu[10].mbti = "ISTP";
    Stu[11].name = "����ȣ"; Stu[11].mbti = "ESTP";
    Stu[12].name = "�ڽ���"; Stu[12].mbti = "ENFJ";
    Stu[13].name = "������"; Stu[13].mbti = "ENTJ";
    Stu[14].name = "���̶�"; Stu[14].mbti = "ESFJ";
    Stu[15].name = "������"; Stu[15].mbti = "INTP";
    Stu[16].name = "�ȴٿ�"; Stu[16].mbti = "ENFJ";
    Stu[17].name = "������"; Stu[17].mbti = "ESFJ";
    Stu[18].name = "�̼���"; Stu[18].mbti = "ISTP";
    Stu[19].name = "������"; Stu[19].mbti = "ESTJ";
    Stu[20].name = "��ä��"; Stu[20].mbti = "ISFJ";
    Stu[21].name = "��ä��"; Stu[21].mbti = "ISTP";
    Stu[22].name = "�Ӵ���"; Stu[22].mbti = "ESFJ";
    Stu[23].name = "������"; Stu[23].mbti = "INFP";
    Stu[24].name = "������"; Stu[24].mbti = "ISTP";
    Stu[25].name = "������"; Stu[25].mbti = "INFP";
    Stu[26].name = "���μ�"; Stu[26].mbti = "ISFP";
    Stu[27].name = "������"; Stu[27].mbti = "ESTP";
    Stu[28].name = "������"; Stu[28].mbti = "INFP";
    Stu[29].name = "�Ѽ۹�"; Stu[29].mbti = "INFP";
    Stu[30].name = "������"; Stu[30].mbti = "ISTP";
    Stu[31].name = "��ä��"; Stu[31].mbti = "ISTJ";
    Stu[32].name = "ȫ����"; Stu[32].mbti = "ENFP";
    Stu[33].name = "Ȳ����"; Stu[33].mbti = "ISTJ";
    Stu[34].name = "Ȳ����"; Stu[34].mbti = "ISFJ";
    Stu[35].name = "Ȳ����"; Stu[35].mbti = "ISFP";
    Stu[36].name = "Ȳä��"; Stu[36].mbti = "ISTP";
    Stu[37].name = "������"; Stu[37].mbti = "ESTJ";
    Stu[38].name = "Ȳ����"; Stu[38].mbti = "ISTP";
    Stu[39].name = "Ȳ����"; Stu[39].mbti = "INTP";
    Stu[40].name = "�ſ���"; Stu[40].mbti = "ESFP";
    Stu[41].name = "������"; Stu[41].mbti = "ISTP";
    Stu[42].name = "������"; Stu[42].mbti = "ISTP";


    for (int i = 0; i < 43; i++)
    {
        if (Stu[i].mbti == mymbti) // �Է��� mbti�� ���� �л� ã�Ƽ� ���
            cout << Stu[i].name << endl;
    }
 
    return 0;
}