#include <iostream>
using namespace std;
int main()
{
	cout << "Enter a temperature: ";
	double temp;
	cin >> temp;
	try {
		cout << "start of try block ..." << endl;
		if (temp > 95)
			throw runtime_error("Exceptional temperature");
		cout << "End of try block..." << endl;
	}
	catch (runtime_error& ex) {
		cout << ex.what() << endl;
		cout << "It is too hot" << endl;
	}
	cout << "Continue..." << endl;
	return 0;} 