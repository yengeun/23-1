#include <iostream>
using namespace std;

	int fib(int n) {
		if (n > 2)
		{
			return fib(n - 1) + fib(n - 2);
		}
		else if (n == 0)
			return 0;
		else
			return 1;
	}

	int fib_memo(int n)
	{
		int* memo = new int{ -1 };
		for (int i = 0; i < 7; i++)
		{
			memo[i] = -1;
		}

		if (memo[n] != -1)
			return memo[n]; //�޸� ����

		memo[n] = fib(n - 1) + fib(n - 2);
		return memo[n];    //�ʱⰪ�̸� memo ������ x �ʱⰪ�� �ƴϸ� memo�� �־��ֱ�

	}

int main()
{
	fib(5);
}
