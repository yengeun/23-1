#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

#define MAX_DEGREE 80

int main()
{
	class Polynomial
	{
		int degree;  // 다항식의 최고 차수
		float coef[MAX_DEGREE] = { 0 }; // 각 항의 계수


	public:
		Polynomial()
		{
			degree = 0; //생성자
		}

		void read()  //다항식의 내용 입력
		{
			printf("다항식의 최고 차수를 입력하시오: ");
			scanf_s("%d", &degree);
			printf("각 항의 계수를 입력하시오 (총 %d개): ", degree + 1);
			for (int i = 0; i <= degree; i++)
				scanf_s("%f", coef + i);
		}

		void display(const char* str = " Poly = ") {  //다항식 내용출력용
			printf("\t%s", str);
			for (int i = 0; i < degree; i++)
				printf("%5.1f x^%d + ", coef[i], degree - i);
			printf(" %4.1f\n", coef[degree]);
		}


		void add(Polynomial a, Polynomial b) {  //덧셈
			if (a.degree > b.degree) {
				*this = a;
				for (int i = 0; i <= b.degree; i++)
					coef[i + (degree - b.degree)] += b.coef[i];
			}

			else {
				*this = b;
				for (int i = 0; i <= a.degree; i++)
					coef[i + (degree - a.degree)] += a.coef[i];
			}
		}

		void sub(Polynomial a, Polynomial b)  //뺄셈
		{
			if (a.degree > b.degree) {
				*this = a;
				for (int i = 0; i <= b.degree; i++)
					coef[i + (degree - b.degree)] -= b.coef[i];
			}

			else {
				b.negate();
				*this = b;
				for (int i = 0; i <= a.degree; i++)
					coef[i + (degree - a.degree)] += a.coef[i];
			}
		}

		void mult(Polynomial a, Polynomial b) //곱셈
		{
			degree = a.degree + b.degree;
			for (int i = 0; i <= degree; i++)
				coef[i] = 0;
			for (int i = 0; i <= a.degree; i++)
				for (int j = 0; j <= b.degree; j++)
					coef[i + j] += a.coef[i] * b.coef[j];
		}


		bool isZero() { return degree == 0; } //최고차수 0인지
		void negate() {  //모든 계수의 부호 바꾸기
			for (int i = 0; i <= degree; i++)
				coef[i] = -coef[i];
		}

		void trim() {  //최고차항의 계수가 0이 아닌 값이 나오도록 다항식의 속성 변경
			int count = 0;

			while (!coef[count])
				count++;
			if (count)
			{
				int temp = degree;
				degree -= count;

				for (int i = 0; i <= temp - count; i++)
					coef[i] = coef[i + count];
			}
		}
	};

	Polynomial a, b, c;
	a.read();
	b.read();
	c.add(a, b);
	a.display("A = ");
	b.display("B = ");
	c.display("A+B = ");
	c.sub(a, b);
	c.display("A-B = ");
	c.mult(a, b);
	c.display("A*B = ");

	return 0;
}
