#include <iostream>
using namespace std;

template <class T1, class T2>
void mcopy(T1 src[], T2 dest[], int n = 5) { //����Ʈ �� Ȱ��
	for (int i = 0; i < n; ++i) {
		dest[i] = (T2)src[i];
	}
}
int main() {
	int x[] = { 1, 2, 3, 4, 5 };
	double d[5];
	mcopy(x, d); // int x[] ���� 5���� double d[]�� ����
	for (int i = 0; i < 5; ++i) cout << d[i] << " ";
	cout << endl;
	return 0;
}  //��°�: 1 2 3 4 5