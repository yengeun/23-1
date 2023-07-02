#include <iostream>
using namespace std;

int main()
{
	double radius = 5;
	const double const* pValue = &radius;

	pValue = &radius;
	cout << *pValue;
	radius++;
	*pValue = 0; //간접참조
	(*pValue)++;

	return 0;
}