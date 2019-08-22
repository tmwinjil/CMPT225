class Point {
public:
    static Point *makeCartesian(double x, double y);
    static Point *makePolar(double r, double theta);

    double getX();
    double getY();
    double getR();
    double getTheta();

    Point* rotate(double alpha);
    Point* translate(double dx, double dy);
    Point* scale(double scaleFactor);

private:
    Point(double r, double theta);
    double r; 
    double theta;
};

