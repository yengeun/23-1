#include <iostream>
#include <string>
using namespace std;

class Cstudent {
	string grade; // private
public:
	void set_grade(string grade_) { // �ܺο��� �޾ƿ��� ��
		grade = grade_;
	}
	string get_grade;

	void set_student_grade(string grade_)
	{
		Ostudent.set_grade(grade_);
	}
};

int main()
{
	Cstudent Ostudent; // ����Ʈ ������ Ostudent
	return 0;
}
//structure �� �⺻�� public, class�� �ݴ�
//int, const ����� keyword, class X �̸� �����Ⱦֵ��� runtime�� ����x