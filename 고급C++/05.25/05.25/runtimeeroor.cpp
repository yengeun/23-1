#include <iostream>
#include <stdexcept>
using namespace std;
int quotient(int number1, int number2)
{
	if (number2 == 0)
		throw runtime_error("Divisor cannot be zero"); //*
	return number1 / number2;
}
int main()
{
	int number1, number2;
	cout << "Enter two integers: ";
	cin >> number1 >> number2;

	try
	{
		int result = quotient(number1, number2);
		cout << number1 << " / "
			<< number2 << " is "
			<< result << endl;
	}
	catch (runtime_error& ex) // *
	{
		cout << ex.what() /**/ << endl;
	}
	cout << "Execution continues ..." << endl;

	//bad allocation 부분
	try
	{
		for (int i = 1; i <= 100; i++)
		{
			new int[70000000]; // 동적 할당 후 삭제 안해줘서 문제생김/ 힙메모리에 할당가능한 영역이 없을떄
			cout << i << " arrays have been created" << endl;
		}
	}
	catch (bad_alloc& ex)
	{
		cout << "Exception: " << ex.what() << endl;
	}

	return 0;
} // 예외클래스들 외울 필요 없음
