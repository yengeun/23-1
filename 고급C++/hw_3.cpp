#include <iostream>
#include <string>
using namespace std;

class MBTI {

public:
	void API()
	{

		int num = 0;
		cout <<" ��ó�� ���� �����ð��� ����� ������ �� ���ΰ���? �Ʒ� �׸� �� ������ ����(����)�� �Է��ϰ� ���͸� ġ����." << endl <<
			"1.��������" << endl << "2.���డ��" << endl << "3.�����ϱ�" << endl << "4.���� �ֱ�" << endl << "5.��ϱ�" << endl;
		cin >> num;

		if (num == 1)
			cout << "����� 1���� �����Ͽ����ϴ�"<< endl << "����� MBTI�� INFP�Դϴ�.";
		if (num == 2)
			cout << "����� 2���� �����Ͽ����ϴ�" << endl << "����� MBTI�� ENFP�Դϴ�.";
		if (num == 3)
			cout << "����� 3���� �����Ͽ����ϴ�" << endl << "����� MBTI�� ISTJ�Դϴ�.";
		if (num == 4)
			cout << "����� 4���� �����Ͽ����ϴ�" << endl << "����� MBTI�� INTP�Դϴ�.";
		if (num == 5)
			cout << "����� 5���� �����Ͽ����ϴ�" << endl << "����� MBTI�� ISFJ�Դϴ�.";

	}
};

int main()
{

	MBTI ombti;
	ombti.API();

	return 0;

}