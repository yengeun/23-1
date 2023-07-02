#include <iostream>
using namespace std;

int main() {
	auto x = 4;  // int //type inference 대충 넣으면 컴파일러(c++)가 알아서 타입을 맞춰줌, 단점: 코드를 읽기가 어려움
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