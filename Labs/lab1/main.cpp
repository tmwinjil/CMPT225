#include <cstdlib>
#include <iostream>
#include "Point.h"

const double PI = 3.1415926;

using namespace std;

int main() {
    Point* p = Point::makeCartesian(10, 15);
    cout << "cartesian: " << p->getX() << " " << p->getY() << endl;
    cout << "polar: " << p->getR() << " " << p->getTheta() << endl;
    cout << endl;

    p = Point::makePolar(12, PI/6.0);
    cout << "cartesian: " << p->getX() << " " << p->getY() << endl;
    cout << "polar: " << p->getR() << " " << p->getTheta() << endl;
    cout << endl;

    Point* r = p->rotate(PI/6.0);
    cout << "rotated: " << r->getX() << " " << r->getY() << endl;

    Point* t = p->translate(3.2, -1.1);
    cout << "translated: " << t->getX() << " " << t->getY() << endl;

    Point* s = p->scale(2.5);
    cout << "scaled: " << s->getX() << " " << s->getY() << endl;
}

