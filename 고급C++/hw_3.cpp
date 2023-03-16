//20211359 신예은 _ 3주차 과제
#include <iostream>
#include <string>
using namespace std;

class MBTI {

public:
	void API()
	{

		int num = 0;
		cout <<" 모처럼 생긴 여유시간에 당신은 무엇을 할 것인가요? 아래 항목 중 선택해 숫자(정수)를 입력하고 엔터를 치세요." << endl <<
			"1.웹툰보기" << endl << "2.여행가기" << endl << "3.과제하기" << endl << "4.집에 있기" << endl << "5.운동하기" << endl;
		cin >> num;

		if (num == 1)
			cout << "당신은 1번을 선택하였습니다"<< endl << "당신의 MBTI는 INFP입니다.";
		if (num == 2)
			cout << "당신은 2번을 선택하였습니다" << endl << "당신의 MBTI는 ENFP입니다.";
		if (num == 3)
			cout << "당신은 3번을 선택하였습니다" << endl << "당신의 MBTI는 ISTJ입니다.";
		if (num == 4)
			cout << "당신은 4번을 선택하였습니다" << endl << "당신의 MBTI는 INTP입니다.";
		if (num == 5)
			cout << "당신은 5번을 선택하였습니다" << endl << "당신의 MBTI는 ISFJ입니다.";

	}
};

int main()
{

	MBTI ombti;
	ombti.API();

	return 0;

}
