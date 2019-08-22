#include<iostream>
#include<vector>
#include<cstdlib>
#include<time.h>
#include "Entry.h"
#include "RadixSort.h"
using namespace std;
#define NUM_OF_ENTRIES 20
int main()
{
    vector<Entry> v;
    Entry* e;
    int d,m;
    char letters[3];
    srand(time(NULL));
//Create vectors
    for (int i = 0; i < NUM_OF_ENTRIES; i++) {
        m = (rand() % 11) + 1;
        d = (rand() % 30) + 1;
        for (int j = 0; j < 3; j++)
            letters[j] = 'A' + (rand() % 25);
        e = new Entry(m, d, letters);
        v.push_back(*e);
    }
    RadixSort t;
    t.sortVector(v);
    //Print the sorted vector
    for (auto p = v.begin(); p != v.end(); p++) {
        p->printEntry();
        cout<<endl;
    }
    cout<<endl<<endl;

    v.clear();
}