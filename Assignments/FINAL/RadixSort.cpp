#include "RadixSort.h"
using namespace std;

RadixSort::RadixSort()
{
    ;
}

vector<Entry>* RadixSort::sortVector(vector<Entry> v)
{
    for (int i = 1 ; i >= 0; i--)
        bucketSort(v, i);
}

void  RadixSort::bucketSort(vector<Entry> v, int selector) 
{
    int Entry::*  data;
    vector<vector<Entry>> bucket;
    for (int j = 0; j < 12; j++) {
        bucket.push_back(vector<Entry>());
        end = 12;
    }
    if (selector == 1) {
        data = &Entry::month;
     } else {
        for (int j = 12; j < 31; j++) {
            bucket.push_back(vector<Entry>());
        }
        data = &Entry::day;
    }
    for (auto p = v.begin(); p < v.end(); p++) {
        bucket[p.*data].push_back(p);
    }
    int i = 0;
    for (auto p = bucket->begin(); p < bucket->end(); p++ ) {
        for (auto q = p->begin(); q < p->end(); q++) {
            v[i] = *q;
            i++;
        }
    }
}