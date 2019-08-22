#include <string>
#include <vector>
#include <iostream>
#include "BarChart.h"
#include "VectorGraph.h"

using namespace std;

class VertBarChart: public BarChart {
public:
	virtual void setN(int n) {		// sets the number of data items
		this->size = n;
	}
	virtual void setData(int* data) {	// sets the data array.
		this->data = data;
	}	
	virtual void setLabels(string* labels) {	// sets the label array.
		this->labels = labels;
	}	
	virtual void setScale(int scale){		// sets how many units in data = one character
		this->scale = scale;
	}
	virtual void draw(){			// draws the bar chart to cout
		vector<int> vecData(data, data + size);
		vector<string> vecLabels(labels, labels + size); 
		VectorGraph graph(vecData, vecLabels, scale);
		cout<<endl;
		graph.draw(cout);
		cout<<endl<<endl;
	}
private:
    int size;
    int* data;
    string* labels;
    int scale;

    void drawBar(int i);
};

