#include <iostream>
using namespace std;
class Circle {
	int radius;
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }
};
template <class T2>
T2 bigger(T2 a, T2 b) {
	if (a > b) return a;
	else return b;
}
int main() {
	int a = 20, b = 50, c;
	c = bigger(a, b);
	cout << "20�� 50 �� ū ���� " << c << endl;
	Circle waffle(10), pizza(20), y;

	y = bigger(waffle.getRadius(), pizza.getRadius());
	cout << "waffle�� pizza �� ū ���� �������� " << y.getRadius() << endl;
	return 0;
}