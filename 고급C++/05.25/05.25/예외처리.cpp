#include <iostream>
using namespace std;
/*int main()
{
	// Read two integers
	cout << "Enter two integers: ";
	int number1, number2;
	cin >> number1 >> number2;

	if (number2 != 0)
		cout << number1 << " / " << number2
		<< " is " << (number1 / number2)
		<< endl;
	else cout << "Divisor cannot be zero" << endl;

	return 0;

	//try catch throw ��� Ű������
}*/

int main()
{
	// Read two integers
	cout << "Enter two integers: ";
	int number1, number2;
	cin >> number1 >> number2;
	try {
		if (number2 == 0) throw number1;
		cout << number1 << " / " << number2 << " is " << (number1 / number2) << endl;
	}
	catch (int ex) // ���ܸ� ó���ϱ� ���� �ڵ� �ۼ� �κ�, catch�κ� ��� ����Ǳ� ��, �� � ���� �ݵ�� ������ �ʿ�� ����
	{
		cout << "Exception: an integer " << ex
			<< " cannot be divided by zero" << endl;
	}
	cout << "Execution continues..." << endl;

	// try catch���� : ������ ������