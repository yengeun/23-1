#include <iostream>
using namespace std;
template <class T>
T add(T data[], T n) {
	T sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += data[i];
	}
	return sum;
}
int main() {
	int x[] = { 1, 2, 3, 4, 5 };
	double d[] = { 1.2, 2.3, 3.4, 4.5, 5.6, 6.7 };
	cout << "x[] ��: " << add(x, 5) << endl;
	cout << "d[] ��: " << add(x, 5) << endl;
	return 0;}