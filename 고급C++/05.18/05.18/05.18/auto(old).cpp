#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	for (auto iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << endl;
	}
	/* auto(new)_ for (auto i : v) {
cout << i << endl;}*/
	return 0;
}