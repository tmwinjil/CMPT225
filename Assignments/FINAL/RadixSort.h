#ifndef RADIXSORT_H
#define RADIXSORT_H
#include<vector>
#include "Entry.h"
using namespace std;

class RadixSort {
public:
    RadixSort();
    vector<Entry>* sortVector(vector<Entry> v);
private:
    void bucketSort(vector<Entry> v, int max);
};
#endif