#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int>heightStack;
	int height[30];
	int a = 0; // �迭�ȿ� ����ִ� ��
	int space = 0; // ����

	cout << "���̸� �Է��ϼ���(�Է��� ������ -1�� ������ enter) :";
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

		cout << "������ ��" << space << "��, ��õ� ���� ���� " << space * 1000 << "�� �̴�.";
		return 0;
	
}