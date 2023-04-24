#include <iostream>
using namespace std;

class Vector {
private:
    double x, y, z;

public:
    Vector(double a = 0, double b = 0, double c = 0) {
        x = a;
        y = b;
        z = c;
    }

    friend Vector operator-(const Vector& v1, const Vector& v2) {
        return Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
    }

    Vector& operator+=(const Vector& v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Vector& operator++() {
        ++x;
        ++y;
        return *this;
    }

    Vector operator++(int) {
        Vector temp = *this;
        ++(*this);
        return temp;
    }

    bool operator==(const Vector& v) const {
        return (x == v.x) && (y == v.y);
    }

    void display() {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }
};


int main() {
    Vector v1(1, 2, 3);
    Vector v2(4, 5, 6);
    Vector v3 = v2 - v1;
    v3 += v1;
    v3.display();
    Vector v4(2, 4);
    Vector v5(2, 3);
    cout << boolalpha << (v4 == v5) << endl;

    ++v1;
    v1.display();

    Vector v6 = ++v1;
    v6.display();
    v1.display();

    Vector v7 = v1++;
    v7.display();
    v1.display();

    return 0;
}
