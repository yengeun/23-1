
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

	// 찾을 MBTI 입력
	cout << "MBTI입력: " << endl;
	cin >> search;

	//mbti 데이터 파일 열기
	if (input.is_open())
	{
		while (!input.eof())
		{
			getline(input, line);

			//한 줄씩 입력된 mbti 찾고 포함된 행 출력
			if ((offset = line.find(search,0)) != string::npos)
				cout << line << endl;
		}
		input.close();
	}

	system("pause");
	return 0;
}