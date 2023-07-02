#include <iostream>
using namespace std;

class CFirst {
public:
	~CFirst() { cout << "Destruct First" << endl; }  //ptr1 삭제시 ptr2는 살아있음 but virtual 쓰면 메모리 모두 깨끘하게 날ㄹ려줌
	//void FirstFunc() { cout << "COUT FirstFunc" << endl; }
    void MyFunc() { cout << "Override FirstFunc" << endl; }
	//virtual void MyVirtualFunc() { cout << "Virtual FirstFunc" << endl; }

};
class CSecond : public CFirst {
public:
	~CSecond() { cout << "Destruct Second" << endl; }
	//void SecondFunc() { cout << "COUT SecondFunc" << endl; }
	void MyFunc() { cout << "Override SecondFunc" << endl; }
	//virtual void MyVirtualFunc() { cout << "Virtual SecondFunc" << endl; }
};
class CThird : public CSecond {
public:
	~CThird() { cout << "Destruct Third" << endl; }
	//void ThirdFunc() { cout << "COUT ThirdFunc" << endl; }
	void MyFunc() { cout << "Override ThirdFunc" << endl; }
	//void MyVirtualFunc() { cout << "Virtual ThirdFunc" << endl; }
};

int main()
{
	CFirst* ptr1 = new CFirst();
	ptr1->MyFunc();
	delete ptr1;  //지우는거 아님 힙메모리 할당 해제, 스택에는 살아 있음

	ptr1 = new CSecond(); // 위에서 delete했어도 또 다른 힙메모리 할당 가능
	ptr1->MyFunc();
	delete ptr1;

	ptr1 = new CThird();
	ptr1->MyFunc();
	delete ptr1;

	return 0;
}