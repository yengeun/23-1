#include <iostream>
using namespace std;

class MyClass {
public:
	inline int square(int x) {
		return x * x;
	}
};
int main() {
	MyClass obj;
	int result = obj.square(5);
	cout << "Result: " << result << endl;
	return 0;
}