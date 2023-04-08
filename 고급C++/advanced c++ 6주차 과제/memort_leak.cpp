#include <iostream>
using namespace std;

int main()
{
	int* p;
	for (int i = 0; i < 999; ++i) {
		p = new int[1000];
	}

	return 0;
}