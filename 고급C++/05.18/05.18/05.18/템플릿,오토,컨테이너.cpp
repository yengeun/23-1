#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

template<typename T>
void print(string name, T const& q ) {
	cout << name << ": \t";
	for (auto const& n : q) {
		cout << n << ' ';
	}

	cout << "\n";
}

template<typename Q>
void print_queue(string name, Q q) {
	for (cout << name << ": \t"; !q.empty(); q.pop())
		cout << q.top() << ' ';
	cout << '\n';
}
int main() {
	const auto data = { 1, 8, 5, 6, 3, 4,
	0, 9, 7, 2 };
		print("data", data);

		priority_queue<int> q1;
		for (int n : data)
			q1.push(n);

	print_queue("q", q1);
	return 0;
}
