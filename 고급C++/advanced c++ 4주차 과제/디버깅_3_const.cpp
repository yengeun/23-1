#include <iostream>
using namespace std;

class CClass {
public:
	int mint[999];
};
void consoleout(const CClass& Cref);  //참조하지 않아도 틀리진 않음
int main() {
	CClass test;
	test.mint[0] = 0;
	consoleout(test);
	return 0;
}
void consoleout(const CClass& Cref) {
	cout << "출력 : " << Cref.mint[0] << endl;
}