#include <iostream>
using namespace std;

int main() {
	auto x = 4;  // int //type inference ���� ������ �����Ϸ�(c++)�� �˾Ƽ� Ÿ���� ������, ����: �ڵ带 �бⰡ �����
	auto y = 3.37; //double
	auto z = 3.37f;
	auto c = 'a';
	auto ptr = &x;
	auto pptr = &ptr;

	cout << typeid(x).name() << endl
		<< typeid(y).name() << endl
		<< typeid(z).name() << endl
		<< typeid(c).name() << endl
		<< typeid(ptr).name() << endl
		<< typeid(pptr).name() << endl;
}