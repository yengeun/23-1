#include <iostream>
using namespace std;
int main()
{
	cout << "Enter a temperature: ";
	double temperature;
	cin >> temperature;
	try {
		cout << "Start of try block …" << endl;
		if (temperature > 94) throw temperature;
		cout << "End of try block ... " << endl;
	}
	catch (double /*temperature 이래도 작동함*/)
	{
		cout << "The temperature is " << temperature << endl;
		cout << "It is too hot" << endl;
	}
	cout << "Execution continues..." << endl;

	return 0;
}
