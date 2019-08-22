#include "Point.h"
#include <math.h>

using namespace std;


Point::Point(double r, double theta) {
    this->r = r;
    this->theta = theta;
}

Point* Point::makeCartesian(double x, double y) {
    return new Point(sqrt(x*x + y*y), atan(y / x));
}

Point* Point::makePolar(double r, double theta) {
    return new Point(r, theta);
}

double Point::getX() {
    return r * cos(theta);
}

double Point::getY() {
    return r * sin(theta);
}

double Point::getR() {
    return r;
}

double Point::getTheta() {
    return theta;
}

Point* Point::rotate(double alpha)
{
	return new Point(r, theta + alpha);
}

Point* Point::translate(double dx, double dy)
{
	return makeCartesian(getX() + dx, getY() + dy);
}
Point* Point::scale(double scaleFactor)
{
	return new Point(r* scaleFactor,theta);
}
