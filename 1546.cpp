#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int arr[1000] = { 0 };
	int max = 0;
	double result = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];

		
		if (max < arr[i])
			max = arr[i];
	}


	for (int i = 0; i < n; i++)
	{
		result += (double)arr[i] / (double)max * 100.l;
	}

	// ������ ���� N��ŭ ������ ��� ���� �ϼ��ȴ�.
	cout << result / n;

	return 0;
}