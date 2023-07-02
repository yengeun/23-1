#include <iostream>
using namespace std;

class CFirst {
public:
	~CFirst() { cout << "Destruct First" << endl; }  //ptr1 ������ ptr2�� ������� but virtual ���� �޸� ��� �����ϰ� ��������
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
	delete ptr1;  //����°� �ƴ� ���޸� �Ҵ� ����, ���ÿ��� ��� ����

	ptr1 = new CSecond(); // ������ delete�߾ �� �ٸ� ���޸� �Ҵ� ����
	ptr1->MyFunc();
	delete ptr1;

	ptr1 = new CThird();
	ptr1->MyFunc();
	delete ptr1;

	return 0;
}