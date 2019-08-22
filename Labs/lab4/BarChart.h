#ifndef BARCHART_H
#define BARCHART_H
#include <string>
using namespace std;

class BarChart {
public:
    virtual void setN(int n) = 0;		// sets the number of data items
    virtual void setData(int* data) = 0;	// sets the data array.
    virtual void setLabels(string* labels) = 0;	// sets the label array.
    virtual void setScale(int scale) = 0;	// sets how many units in data = one character
    virtual void draw() = 0;			// draws the bar chart to cout
};
#endif
