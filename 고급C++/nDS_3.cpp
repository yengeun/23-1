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
		if (isFull()) error("스택 포화 에러");
		counts += 1;
		data[++top] = e;

	}

	double pop() {
		if (isEmpty()) error("스택 공백 에러");
		counts -= 1;
		return data[top--];
	}

	double peek() {
		if (isEmpty()) error("스택 공백 에러");
		return data[top];
	}

	double threepop()
	{
		for (int i = 0; i < top + 1; ++i)
			t[i] = data[i];
		return 0;
	}

};

int k = 0;
int max_count = 0;
int oper_count = 0;
int M;
int a[100];
int thcount;

double calcPostfixExpr(FILE* fp = stdin)
{
	char c;
	double	val;
	OperandStack st;

	while ((c = getc(fp)) != '\n') {
		if (c == '+' || c == '-' || c == '*' || c == '/') {
			oper_count = oper_count + 1;
			if (oper_count == 3) {
				st.threepop();
				thcount = counts;
			}
			double val2 = st.pop();
			double val1 = st.pop();
			switch (c) {
			case '+': st.push(val1 + val2); break;
			case '-': st.push(val1 - val2); break;
			case '*': st.push(val1 * val2); break;
			case '/': st.push(val1 / val2); break;
			}
			a[k] = counts;
			k += 1;

		}
		else if (c >= '0' && c <= '9') {
			ungetc(c, fp);
			fscanf_s(fp, "%lf", &val);

			st.push(val);
			a[k] = counts;
			k += 1;
		}
	}
	return st.pop();
}

void max() {
	M = a[0];
	for (int i = 1; i < 100; ++i) {
		if (a[i] > M) {
			M = a[i];
			max_count = 1;
		}
		else if (a[i] == M) {
			max_count = max_count + 1;
		}
		if (a[i] == -1) {
			break;
		}
	}
}


int main()
{
	for (int i = 0; i < MAX_STACK_SIZE; ++i) {
		a[i] = -1;
	}
	cout << "Postfix 입력: ";
	double res = calcPostfixExpr();
	max();
	cout << M << endl << max_count << endl;
	cout << "-------------" << endl;
	for (int i = thcount - 1; i >= 0; --i) {
		cout << t[i] << endl;
	}
	if (oper_count < 3) {
		cout << "empty";
	}
	cout << "-------------" << endl << res;

	return 0;
}
