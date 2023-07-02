#include <iostream>
#include <fstream>
using namespace std;
/*
int main() {
	ofstream output;
	// Create a file
	output.open("scores.txt");
	// Write two lines
	output << "John" << " " << "T" << " " << "Smith" << " " << 90 << endl;
	output << "Eric" << " " << "K" << " " << "Jones" << " " << 85 << endl;
	output.close();
	cout << "Done" << endl;
	return 0;
}*/
int main() {
	ifstream input("scores.txt");
	// Read data
	string firstName;
	char mi;
	string lastName;
	int score;

	input >> firstName >> mi >> lastName >> score;
	cout << firstName << " " << mi << " " << lastName << " " << score << endl;

	input >> firstName >> mi >> lastName >> score;
	cout << firstName << " " << mi << " " << lastName << " " << score << endl;

	input.close();

	cout << "Done" << endl;
	return 0;
}