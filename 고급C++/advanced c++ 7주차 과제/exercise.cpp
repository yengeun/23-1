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
	// 2�� 3 �� ū �� ��ȯ
	cout << func(2, 3) << endl; // 2�� 3 �� ū �� ��ȯ
	// �迭 array, array�� ũ�� 5�� �̿��� �迭���� ���� ū �� ��ȯ
	cout << func(array, 5) << endl;
	return 0;
}