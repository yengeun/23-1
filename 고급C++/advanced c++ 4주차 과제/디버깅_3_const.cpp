#include <iostream>
using namespace std;

class CClass {
public:
	int mint[999];
};
void consoleout(const CClass& Cref);  //�������� �ʾƵ� Ʋ���� ����
int main() {
	CClass test;
	test.mint[0] = 0;
	consoleout(test);
	return 0;
}
void consoleout(const CClass& Cref) {
	cout << "��� : " << Cref.mint[0] << endl;
}