#include <iostream>

using namespace std;

int main() {
    int* p = new int[3];
    int* q = p;
    q[0] = 1;
    cout << *p;
    /*q[1] = 2;
    cout << q[0] << ", " << q[1];
    delete[] q;*/


    return 0;
}
