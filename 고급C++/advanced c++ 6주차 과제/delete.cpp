#include <iostream>

using namespace std;

int main() {
    int* p = new int[3];
    int* q = p;
    q[0] = 1;
    q[1] = 2;

    delete[] q;


    return 0;
}
