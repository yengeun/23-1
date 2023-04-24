#include <iostream>
using namespace std;


int func(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int func(int array[], int size) {
	int max = array[0];
	for (int i = 1; i < size; i++) {
		if (array[i] > max) {
			max = array[i];
		}
	}
	return max;
}

int main() {
	int array[5] = { 1, 9, -1, 5, 4 };
	// 2와 3 중 큰 수 반환
	cout << func(2, 3) << endl; // 2와 3 중 큰 수 반환
	// 배열 array, array의 크기 5를 이용해 배열에서 가장 큰 수 반환
	cout << func(array, 5) << endl;
	return 0;
}