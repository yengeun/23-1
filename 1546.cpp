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

	// 과목의 개수 N만큼 나누면 평균 값이 완성된다.
	cout << result / n;

	return 0;
}