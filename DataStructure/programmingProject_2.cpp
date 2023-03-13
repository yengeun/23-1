#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

#define MAX_DEGREE 80

int main()
{
	class Polynomial
	{
		int degree;  // ���׽��� �ְ� ����
		float coef[MAX_DEGREE] = { 0 }; // �� ���� ���


	public:
		Polynomial()
		{
			degree = 0; //������
		}

		void read()  //���׽��� ���� �Է�
		{
			printf("���׽��� �ְ� ������ �Է��Ͻÿ�: ");
			scanf_s("%d", &degree);
			printf("�� ���� ����� �Է��Ͻÿ� (�� %d��): ", degree + 1);
			for (int i = 0; i <= degree; i++)
				scanf_s("%f", coef + i);
		}

		void display(const char* str = " Poly = ") {  //���׽� ������¿�
			printf("\t%s", str);
			for (int i = 0; i < degree; i++)
				printf("%5.1f x^%d + ", coef[i], degree - i);
			printf(" %4.1f\n", coef[degree]);
		}


		void add(Polynomial a, Polynomial b) {  //����
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

		void sub(Polynomial a, Polynomial b)  //����
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

		void mult(Polynomial a, Polynomial b) //����
		{
			degree = a.degree + b.degree;
			for (int i = 0; i <= degree; i++)
				coef[i] = 0;
			for (int i = 0; i <= a.degree; i++)
				for (int j = 0; j < b.degree; j++)
					coef[i + j] += a.coef[i] * b.coef[j];
		}

		bool isZero() { return degree == 0; } //�ְ����� 0����
		void negate() {  //��� ����� ��ȣ �ٲٱ�
			for (int i = 0; i <= degree; i++)
				coef[i] = -coef[i];
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