#include <iostream>
#include <fstream>
#include "Student.h"
using namespace std;

void displayStudent(const Student& student)
{
  cout << student.getFirstName() << " ";
  cout << student.getMi() << " ";
  cout << student.getLastName() << " ";
  cout << student.getScore() << endl;
}

int main()
{ 
  fstream binaryio; // Create stream object
  binaryio.open("student.dat", ios::out | ios::binary);
	
  Student student1("FirstName1", 'A', "LastName1", 10);
  Student student2("FirstName2", 'B', "LastName2", 20);
  Student student3("FirstName3", 'C', "LastName3", 30);
  Student student4("FirstName4", 'D', "LastName4", 40);
  Student student5("FirstName5", 'E', "LastName5", 50);
  Student student6("FirstName6", 'F', "LastName6", 60);
  Student student7("FirstName7", 'G', "LastName7", 70);
  Student student8("FirstName8", 'H', "LastName8", 80);
  Student student9("FirstName9", 'I', "LastName9", 90);
  Student student10("FirstName10", 'J', "LastName10", 100);

  binaryio.write(reinterpret_cast<char*>
    (&student1), sizeof(Student));
  binaryio.write(reinterpret_cast<char*>
    (&student2), sizeof(Student));
  binaryio.write(reinterpret_cast<char*>
    (&student3), sizeof(Student));
  binaryio.write(reinterpret_cast<char*>
    (&student4), sizeof(Student));
  binaryio.write(reinterpret_cast<char*>
    (&student5), sizeof(Student));
  binaryio.write(reinterpret_cast<char*>
    (&student6), sizeof(Student));
  binaryio.write(reinterpret_cast<char*>
    (&student7), sizeof(Student));
  binaryio.write(reinterpret_cast<char*>
    (&student8), sizeof(Student));
  binaryio.write(reinterpret_cast<char*>
    (&student9), sizeof(Student));
  binaryio.write(reinterpret_cast<char*>
    (&student10), sizeof(Student));

  binaryio.close();

  // Read student back from the file
  binaryio.open("student.dat", ios::in | ios::binary); // binary로 가져오기

  Student studentNew;

  binaryio.seekg(2 * sizeof(Student));

  cout << "Current position is " << binaryio.tellg() << endl;

  binaryio.read(reinterpret_cast<char*>
    (&studentNew), sizeof(Student));

  displayStudent(studentNew);

  cout << "Current position is " << binaryio.tellg() << endl;

  binaryio.close();

  return 0;
}
