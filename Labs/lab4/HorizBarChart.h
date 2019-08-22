#include <string>
#include "BarChart.h"
using namespace std;

class HorizBarChart: public BarChart {
public:
    HorizBarChart();			// constructor
    void setN(int n);			// sets the number of data items
    void setData(int* data);		// sets the data array.
    void setLabels(string* labels);	// sets the label array.
    void setScale(int scale);		// sets how many units in data = one character
    void draw();			// draws the bar chart to cout

private:
    int size;
    int* data;
    string* labels;
    int scale;

    void drawBar(int i);
};

