#include <iostream>
using namespace std;

class CStudent {
	int id;
public:
	CStudent(int _id) {
		id = _id;  // �Լ� �����ε�
		        
	}
	/*int get_id() {
		return id;
		}*/

	int set_id(int _id){
		id = _id;
		return id;
	}
};

CStudent* CreateStudent() {
	CStudent Ostudent(2023);
	return &Ostudent;
}

int main()
{
	/*CStudent* Ostudent = CreateStudent();
	int id = Ostudent->get_id();
	int *p = new int;
	return 0;*/

	//heap memory�� �����
	CStudent* C1 = new CStudent();
	CStudent* c2 = C1;
	c2->set_id(2023);
	return 0;
}