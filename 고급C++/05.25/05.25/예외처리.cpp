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

	//try catch throw 모두 키워드임
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
	catch (int ex) // 예외를 처리하기 위한 코드 작성 부분, catch부분 없어도 실행되긴 함, 즉 어떤 값을 반드시 가져올 필요는 없음
	{
		cout << "Exception: an integer " << ex
			<< " cannot be divided by zero" << endl;
	}
	cout << "Execution continues..." << endl;

	// try catch이점 : 가독성 좋아짐