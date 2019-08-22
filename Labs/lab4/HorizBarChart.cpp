#include <iostream>
#include "HorizBarChart.h"

using namespace std;

//const int NULL = 0;

HorizBarChart::HorizBarChart() :
    size(0), data(NULL), labels(NULL), scale(0) {
}

void HorizBarChart::setN(int n) {
    this->size = n;
}

void HorizBarChart::setData(int* data) {
    this->data = data;
}

void HorizBarChart::setLabels(string* labels) {
    this->labels = labels;
}

void HorizBarChart::setScale(int scale) {
    this->scale = scale;
}

void HorizBarChart::draw() {
    cout << endl;

    for(int i=0; i<size; i++) {
        cout << labels[i] << " | ";
        drawBar(i);
        cout << endl;
    }
    cout << endl << endl;
}

void HorizBarChart::drawBar(int i) {
    int numChars = data[i] / scale;
    for(int j=0; j<numChars; j++) {
        cout << 'X';
    }
}

