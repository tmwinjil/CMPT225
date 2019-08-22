#include <iostream>
#include "VectorGraph.h"
using namespace std;

VectorGraph::VectorGraph(vector<int> vec, vector<string> headers, int scaleFactor) :
	v(vec), heads(headers), scale(scaleFactor) {}

void VectorGraph::draw(ostream& out) {
    columnLength = maxHeaderLength() + 1; 

    drawData(out);
    drawLine(out);
    drawHeaders(out); 
}


void VectorGraph::drawData(ostream& out) {
    int height = maxEntry() / scale;
    while(height > 0) {
        drawEntries(out, height);
        height--; 
    }
}

void VectorGraph::drawEntries(ostream& out, int height) {
    out.width(columnLength/2 - 1);
    out << ' ';

    for(auto iter = v.begin(); iter != v.end(); iter++) {
        out.width(columnLength);
        out << left;
        if(*iter >= height*scale) {
            out << 'X';
        }
        else {
            out << ' ';
        }
    }
    out << endl;
}

void VectorGraph::drawLine(ostream& out) {
    int width = columnLength * v.size();

    for(int i=0; i<width; i++) {
        out << '-';
    }
    out << endl;
}

void VectorGraph::drawHeaders(ostream& out) {
    for(auto iter = heads.begin(); iter != heads.end(); iter++) {
	out.width(columnLength);
        out << *iter;
    }
    out << endl;
}


int VectorGraph::maxEntry() {
    int max = 0;
    for (auto iter = v.begin(); iter != v.end(); iter++) {
        if(*iter > max) {
            max = *iter;
        }
    }
    return max;
}

int VectorGraph::maxHeaderLength() {
    int max = 0;
    for (auto iter = heads.begin(); iter != heads.end(); iter++) {
        if(iter->length() > max) {
            max = iter->length();
        }
    }
    return max;
}
