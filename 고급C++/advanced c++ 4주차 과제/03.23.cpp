#include <iostream>
#include <string>
using namespace std;

class Cstudent {
	string grade; // private
public:
	void set_grade(string grade_) { // 외부에서 받아오는 값
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
	Cstudent Ostudent; // 디폴트 생성자 Ostudent
	return 0;
}
//structure 는 기본이 public, class는 반대
//int, const 등등은 keyword, class X 미리 지정된애들은 runtime에 영향x