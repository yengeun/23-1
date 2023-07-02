#include <iostream>
using namespace std;

const int MAX_STACK_SIZE = 20;
int counts = 0;
double t[100];


inline void error(const char* message) {
	cout << message;
	exit(1);
}

class OperandStack
{
	int top;
	double data[MAX_STACK_SIZE];


public:
	OperandStack() { top = -1; }
	~OperandStack() {}


	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_STACK_SIZE - 1; }

	void push(double e) {
		if (isFull()) error("���� ��ȭ ����");
		counts += 1;
		data[++top] = e;

	}

	double pop() {
		if (isEmpty()) error("���� ���� ����");
		counts -= 1;
		return data[top--];
	}

	double peek() {
		if (isEmpty()) error("���� ���� ����");
		return data[top];
	}

	int getSize() {
		return top + 1;
	}

	double threepop()
	{
		for (int i = 0; i < top + 1; ++i)
			t[i] = data[i];
		return 0;
	}


};

void printStackSize(OperandStack& st, int& maxStackSize, int& countMaxStackSize) {
	int size = st.getSize();
	if (size > maxStackSize) {
		maxStackSize = size;
		countMaxStackSize = 1;
	}
	else if (size == maxStackSize) {
		countMaxStackSize++;
	}

}

int oper_count = 0;
int thcount;

double calcPostfixExpr(FILE* fp = stdin) {
	char c;
	double val;
	OperandStack st;
	int maxStackSize = 0;
	int countMaxStackSize = 0;
	while ((c = getc(fp)) != '\n') { // ���Ͽ��� expr �� ���� �� �о
		if (c == '+' || c == '-' || c == '*' || c == '/') { //�������̸�
			oper_count = oper_count + 1;
			if (oper_count == 3) {
				st.threepop();
				thcount = counts;
			}
			double val2 = st.pop(); //�ǿ����� 2�� pop�Ͽ�
			double val1 = st.pop(); //���
			switch (c) {
			case'+': st.push(val1 + val2); break; // �������
			case'-': st.push(val1 - val2); break; // �ٽ� ���ÿ�
			case'*': st.push(val1 * val2); break; // ����
			case'/': st.push(val1 / val2); break;
			}
			printStackSize(st, maxStackSize, countMaxStackSize);
		}
		else if (c >= '0' && c <= '9') { // �ǿ������̸� ���ÿ� push
			ungetc(c, fp); // �о� ���� ���� �� ���� �ݳ�
			fscanf_s(fp, "%lf", &val); // �ǿ����ڸ� �Ǽ��� read
			st.push(val); // �ǿ����ڸ� ���ÿ� push
			printStackSize(st, maxStackSize, countMaxStackSize);
		}
	}
	cout << "������ �ִ� ũ��: " << maxStackSize << endl;
	cout << "������ �ִ� ũ�Ⱑ ��Ÿ�� Ƚ��: " << countMaxStackSize << endl;
	return (st.pop());
}


int main()
{
	cout << "���� �Է�(Postfix): ";
	double res = calcPostfixExpr();
	cout << "��� ���: " << res << endl;

	cout << "�� ��° ������ ������ ������ ����: ";
	for (int i = thcount - 1; i >= 0; --i) {
		cout << t[i] << " ";
	}
	if (oper_count < 3) {
		cout << "empty";
	}


	return 0;
}
