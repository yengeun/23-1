# include <iostream>
using namespace std;

int main()
{
	int n = 0;
	int np = 0;
	int max = 1000000;
	int min = -1000000;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> np;
		if (np < max)
		{
			max = np;
		}
		if (np > min)
		{
			min = np;
		}
	}

	cout << max << " " << min << endl;

	return 0;
}