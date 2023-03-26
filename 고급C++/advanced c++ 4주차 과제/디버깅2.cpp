#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1("I have a dream");
	string s2("Computer Programming");

	s1.append(s2);
	s1.append(s2, 9, 7);
	s1.append("NEW", 3);
	s1.append(3, 'N');

	s1.assign(3, 'N');
	s1.assign(s2, 9, 7);
	s1.assign("NEW", 3);
	s1.assign(3, 'N');

	s1.at(0);
	s1.length();
	s1.size();
	s1.capacity();

	return 0;
}