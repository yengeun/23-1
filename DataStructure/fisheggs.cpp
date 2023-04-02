#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int>heightStack;
	int height[30];
	int a = 0; // 배열안에 들어있는 수
	int space = 0; // 공간

	cout << "길이를 입력하세요(입력이 끝나면 -1을 누르고 enter) :";
	for (int i = 0; i < 30; i++) {
		cin >> height[i];
		a++;

		if (height[i] == -1) {
			break;
		}
	}

	int temp;
	for (int i = 0; i < a; i++) {
		for (int k = i + 1; k < a; k++) {
			if (height[i] > height[k]) {
				temp = height[i];
				heightStack.push(height[k]);
			}
			if (!heightStack.empty())
			{
				space += temp - heightStack.top();
				heightStack.pop();
			}
			if (height[i] < height[k]) {
				i++;
				break;
			}

		}
		if (i >= a)
			break;
	}

		cout << "공간은 총" << space << "개, 산천어가 낳은 알은 " << space * 1000 << "개 이다.";
		return 0;
	
}