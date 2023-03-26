#include <iostream>
using namespace std;

class SoSimple {
private:
	static int simObjCnt;
public:
	SoSimple() {
		simObjCnt++;
		cout << simObjCnt << "¹øÂ° SoSimple °´Ã¼" << endl;
	}
};
int SoSimple::simObjCnt = 0;
int main(void) {
	SoSimple sim1;
	SoSimple sim2;
	return 0;
}
