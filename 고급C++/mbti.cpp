
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(void)
{
	string search;
	int offset;
	string line;
	ifstream input;
	input.open("MBTIdata.txt");

	// ã�� MBTI �Է�
	cout << "MBTI�Է�: " << endl;
	cin >> search;

	//mbti ������ ���� ����
	if (input.is_open())
	{
		while (!input.eof())
		{
			getline(input, line);

			//�� �پ� �Էµ� mbti ã�� ���Ե� �� ���
			if ((offset = line.find(search,0)) != string::npos)
				cout << line << endl;
		}
		input.close();
	}

	system("pause");
	return 0;
}