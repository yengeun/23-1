#include <iostream>
using namespace std;

class CFirst {
public:
	virtual ~CFirst() {}
	void FirstFunc() { cout << "COUT FirstFunc" << endl; }
	void MyFunc() { cout << "Override FirstFunc" << endl; }
	void MyVirtualFunc() { cout << "Virtual FirstFunc" << endl; }
	
};
class CSecond : public CFirst {
public:
	~CSecond() {}
	void SecondFunc() { cout << "COUT SecondFunc" << endl; }
	void MyFunc() { cout << "Override SecondFunc" << endl; }
	void MyVirtualFunc() { cout << "Virtual SecondFunc" << endl; }
};
class CThird : public CSecond {
public:
	~CThird() {}
	void ThirdFunc() { cout << "COUT ThirdFunc" << endl; }
	void MyFunc() { cout << "Override ThirdFunc" << endl; }
	virtual void MyVirtualFunc() { cout << "Virtual ThirdFunc" << endl; }
};

int main() {
	CThird* tptr = new CThird();  //포인터 객체 생성
	CSecond* sptr = tptr;  //왼쪽이 조금 더 큰 개념이라서 넣어주기 가능
	CFirst* fptr = sptr;

	fptr->MyFunc(); //베이스 클래스의 멤버 호출
	sptr->MyFunc(); // 두 번째 클래스의 멤버 호출
	tptr->MyFunc(); // 세 번째 클래스의 멤버 호출
	fptr->MyVirtualFunc(); 
	sptr->MyVirtualFunc(); //안에 들어간 실제 객체 호출/ 세 번째 클래스로 만든 객체 들어와 있음
	tptr->MyVirtualFunc();

	return 0;

	/*tptr->FirstFunc();
	tptr->SecondFunc();
	tptr->ThirdFunc();

	sptr->FirstFunc();
	sptr->SecondFunc();
	sptr->ThirdFunc(); // tptr의 멤버 함수는 사용 불가능 (상속의 개념으로 생각; 부모 클래스가 자식클래스의 무언가를 사용할 수 없음)

	fptr->FirstFunc();
	fptr->SecondFunc(); //
	fptr->ThirdFunc();*/
}