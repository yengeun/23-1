#include <iostream>
using namespace std;

int main() {
	int a = 6;
	int& b = a;  //type�� & ǥ�ø� ������
	b = 10;
	cout << a << endl;

	int x = 5;
	int* ptr = &x;
	*ptr = 10;
	cout << x << endl;
	return 0;
}