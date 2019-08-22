#ifndef UNIQUE_H
#define UNIQUE_H
using namespace std;

class Unique {
public:

    bool unique(int* A, int n);	// returns true if all n elements in the array A are unique, and false otherwise. Does not change A.
    //Merge sort A and if a similar number is found return false
private:
    friend void mergeSort(int arr[], int leftIndex, int rightIndex);
    friend void merge(int arr[], int leftIndex, int middleIndex, int rightIndex);

};
#endif