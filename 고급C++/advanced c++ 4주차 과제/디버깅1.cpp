#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char e1[] = "sung";
	char e2[] = { 's', 'u', 'n', 'g' };

	string s1 = ("sung");
	s1.append("shin");
	s1.assign("shin");
	s1.assign("university");
	s1.assign("university student");

	string s2 = "";
	s2 = "sung";

	return 0;
}