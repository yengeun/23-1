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
	CThird* tptr = new CThird();  //������ ��ü ����
	CSecond* sptr = tptr;  //������ ���� �� ū �����̶� �־��ֱ� ����
	CFirst* fptr = sptr;

	fptr->MyFunc(); //���̽� Ŭ������ ��� ȣ��
	sptr->MyFunc(); // �� ��° Ŭ������ ��� ȣ��
	tptr->MyFunc(); // �� ��° Ŭ������ ��� ȣ��
	fptr->MyVirtualFunc(); 
	sptr->MyVirtualFunc(); //�ȿ� �� ���� ��ü ȣ��/ �� ��° Ŭ������ ���� ��ü ���� ����
	tptr->MyVirtualFunc();

	return 0;

	/*tptr->FirstFunc();
	tptr->SecondFunc();
	tptr->ThirdFunc();

	sptr->FirstFunc();
	sptr->SecondFunc();
	sptr->ThirdFunc(); // tptr�� ��� �Լ��� ��� �Ұ��� (����� �������� ����; �θ� Ŭ������ �ڽ�Ŭ������ ���𰡸� ����� �� ����)

	fptr->FirstFunc();
	fptr->SecondFunc(); //
	fptr->ThirdFunc();*/
}