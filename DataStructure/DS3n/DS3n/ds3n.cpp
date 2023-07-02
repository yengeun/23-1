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
	while ((c = getc(fp)) != '\n') { // 파일에서 expr 한 문자 씩 읽어서
		if (c == '+' || c == '-' || c == '*' || c == '/') { //연산자이면
			oper_count = oper_count + 1;
			if (oper_count == 3) {
				st.threepop();
				thcount = counts;
			}
			double val2 = st.pop(); //피연산자 2개 pop하여
			double val1 = st.pop(); //계산
			switch (c) {
			case'+': st.push(val1 + val2); break; // 계산결과를
			case'-': st.push(val1 - val2); break; // 다시 스택에
			case'*': st.push(val1 * val2); break; // 저장
			case'/': st.push(val1 / val2); break;
			}
			printStackSize(st, maxStackSize, countMaxStackSize);
		}
		else if (c >= '0' && c <= '9') { // 피연산자이면 스택에 push
			ungetc(c, fp); // 읽어 들인 문자 한 개를 반납
			fscanf_s(fp, "%lf", &val); // 피연산자를 실수로 read
			st.push(val); // 피연산자를 스택에 push
			printStackSize(st, maxStackSize, countMaxStackSize);
		}
	}
	cout << "스택의 최대 크기: " << maxStackSize << endl;
	cout << "스택의 최대 크기가 나타난 횟수: " << countMaxStackSize << endl;
	return (st.pop());
}


int main()
{
	cout << "수식 입력(Postfix): ";
	double res = calcPostfixExpr();
	cout << "계산 결과: " << res << endl;

	cout << "세 번째 연산자 직전의 스택의 상태: ";
	for (int i = thcount - 1; i >= 0; --i) {
		cout << t[i] << " ";
	}
	if (oper_count < 3) {
		cout << "empty";
	}


	return 0;
}
