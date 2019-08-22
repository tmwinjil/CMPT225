#include <vector>
#include <string>
#include <iostream>
using namespace std;


class VectorGraph {
public:
    VectorGraph(vector<int> v, vector<string> heads, int scale);
    void draw(ostream& o);

private:
    vector<int> v;
    vector<string> heads;
    int scale;
    int columnLength;

    int maxHeaderLength();
    int maxEntry();
    void drawData(ostream& o);
    void drawEntries(ostream& o, int height);
    void drawLine(ostream& o);
    void drawHeaders(ostream& o);
};
