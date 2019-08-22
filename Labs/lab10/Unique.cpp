#include "Unique.h"
using namespace std;

/**
 *@brief		Generic merge and merge sort algorithm modified from https://www.geeksforgeeks.org/merge-sort/
 *	merge:			merges 2 subarrays of arr	
 *	mergeSort:		sort array using mergesort
 *
 *@params		{arr} array to be sorted
 *			{leftIndex} index of the start of the sort
 *			{rightIndex} index of the end of the sort
 *			{middleIndex} index of the middle of the sort
 *
 *@return
 *	merge:		void
 *	mergesort:	void
 *
 */
void merge(int arr[], int leftIndex, int middleIndex, int rightIndex) 
{ 
    int i, j, k; //Array Indices
    int subArray1Size = middleIndex - leftIndex + 1; 
    int subArray2Size =  rightIndex - middleIndex; 
  
    /* create temp arrays */
    int leftArray[subArray1Size], rightArray[subArray2Size]; 
  
    /* Copy data to temp arrays leftArray[] and rightArray[] */
    for (i = 0; i < subArray1Size; i++) 
        leftArray[i] = arr[leftIndex + i]; 
    for (j = 0; j < subArray2Size; j++) 
        rightArray[j] = arr[middleIndex + 1+ j]; 
  
    /* Merge the temp arrays back into arr[leftIndex..rightIndex]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = leftIndex; // Initial index of merged subarray 
    while (i < subArray1Size && j < subArray2Size) 
    { 
        if (leftArray[i] <= rightArray[j]) 
        { 
            arr[k] = leftArray[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = rightArray[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of leftArray[], if there 
       are any */
    while (i < subArray1Size) 
    { 
        arr[k] = leftArray[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of rightArray[], if there 
       are any */
    while (j < subArray2Size) 
    { 
        arr[k] = rightArray[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int arr[], int leftIndex, int rightIndex) 
{ 
    if (leftIndex < rightIndex) 
    { 
        // Same as (leftIndex+rightIndex)/2, but avoids overflow for 
        // large leftIndex and h 
        int middleIndex = leftIndex+(rightIndex-leftIndex)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, leftIndex, middleIndex); 
        mergeSort(arr, middleIndex+1, rightIndex); 
        merge(arr, leftIndex, middleIndex, rightIndex); 
    } 
} 

bool Unique::unique(int* A, int n)
{
    int* b = new int[n];
    for (int j = 0; j < n; j++) {
        b[j] = A[j];
    }
    mergeSort(b, 0, n - 1);
    for (int i = 0; i < n - 1; i++) {
        if (b[i] == b[i + 1]) {
            delete[] b;
            return false;
        }
    }
    delete[] b;
    return true;
}