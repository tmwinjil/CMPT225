#include <iostream>
#include <fstream>
using namespace std;

//Heler mode functions. Mode1 is the main but mode 2 is for cases such as test 5 where mode1 is too slow.
long mode1 (long *arr, int n, long maxValue, long minValue);
long mode2 (long *arr, int n);

/**
 *@brief	Function that returns the mode of an array arr  
 *
 *@params	(arr) array of long integers
 *		(n) number of elements in array
 *
 *@return	value of the arrays mode
 */
long mode(long *arr, int n) {
	int maxValue = arr[0];
	int minValue = arr[0];
	if (n == 0)
		return -1;
	else if (n == 1)
		return arr[0];
	
	//Find Max Value
	for (int i = 1; i < n; i++) {
		if(arr[i] > maxValue)
			maxValue = arr[i];
		if(arr[i] < minValue)
			minValue = arr[i];
	}
	if (maxValue > 1000000 && n < 100000) {
		//Use the O(nlogn) method where maxvalue is very large but few number of elements number of elements
		return mode2(arr, n);
	}
	else {
		//Use O(n) method otherwise
		return mode1(arr, n, maxValue, minValue);
	}
}
/**
 *@brief	uses array values as indexes to find mode
 *
 *@order	O(n)
 *
 *@params	{arr} array of long integers
 *		{n} number of elements in arr
 *		{minValue} minimum value in arr (will be index 0)
 *		{maxValue} maximum value in arr
 *@return	the array mode
 */
long mode1 (long *arr, int n, long maxValue, long minValue) {
	long arrayMode = arr[0];
	long arrayLength = maxValue - minValue + 1;
	int *arrayCount = new int[arrayLength];

	for (long i = 0; i < arrayLength; i++) {
		arrayCount[i] = 0;
	}
	for (long i = 0; i < n; i++) {
		arrayCount[arr[i] - minValue]++;
	}
	int maxCount = 0;
	for (long i = 0; i < arrayLength; i++) {
		if (arrayCount[i] > maxCount) {
			maxCount = arrayCount[i];
			arrayMode = i + minValue;
		}
	}
	delete[] arrayCount;
	return arrayMode;
}

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
static void merge(long arr[], int leftIndex, int middleIndex, int rightIndex) 
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
  
static void mergeSort(long arr[], int leftIndex, int rightIndex) 
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


/**
 *@brief	Sorts array using mergeSort and then in order, counts how many
 *		of each element is present and returns the max value
 *
 *@order	O(nlogn)		
 *
 *@params	{arr} array of long integers
 *		{n} number of elements in arr
 *		{minValue} minimum value in arr (will be index 0)
 *		{maxValue} maximum value in arr
 *@return	the array mode
 */
long mode2(long *arr, int n) {
	long arrayMode = -1;
	mergeSort(arr, 0, n-1);
	int arrayCount[n];

	for( int i = 0; i < n; i++)
		arrayCount[i] = 0;

	arrayCount[0] = 1;
	int j = 0;
	int max = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] == arr[i - 1])
			arrayCount[j] += 1;
		else {
			if (arrayCount[j] > max) {
				max = arrayCount[j];
				arrayMode = arr[i - 1];
			}
			j++;
			arrayCount[j] = 1;
		}
	}
	if (arrayCount[j] > max)
		arrayMode = arr[n - 1];
	return arrayMode;	
}


// Input is the number of elements, followed by that many integers.
// Writes mode of elements to file specified as first command-line argument.
int main (int argc,  char* argv[]) {

	// ofstream for writing result.
	ofstream outputfile;

	// Parse command-line arguments.
	if (argc != 2) {
		// Note that the program name is the first argument, so argc==1 if there are no additional arguments.
		cerr << "Expected one argument." << endl;
		cerr << "  Usage: " << argv[0] << " output_filename" << endl;
		return 1;
	} else {
		// Open the filename specified for input.
		outputfile.open (argv[1]);
	}


	// Read a set of elements into an array.
	int n;
	long *arr;

	// Get the number of elements
	cout << "Enter the number of elements:" << endl;
	cin >> n;

	// Create array in dynamic memory.
	arr = new long[n];

	for (int i=0; i<n; i++) {
		cout << "Enter a number:" << endl;
		cin >> arr[i];
	}

	long m = mode(arr,n);

	cout << "The mode is " << m << endl;

	outputfile << m << endl;
	outputfile.close();

	// Free up memory.  Note use of delete [], since this is an array.
	delete [] arr;

	return 0;
}
