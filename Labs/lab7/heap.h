#pragma once

#include <string>
#include <iostream>
using namespace std;


class Heap {
 public:
	Heap(int n);			// Create a heap with space for n numbers.
	~Heap();
	
	// heap operations
	bool insert(string n);	// Insert a value into a heap.
	string remove();		// Remove and return the root of the heap.

	// Debugging methods
	void printHeap();		// Print out the contents of the heap.
	bool isHeapOrdered();		// Check the ordering property of the heap.


 private:
	string* arr;	// Array to hold the heap's data.
	int capacity;	// Capacity of heap, i.e. size of arr.
	int size;		// Number of items in the heap.
	
	// Bubble down (downheap) -- fix the heap from the root to the bottom.
	void bubbleDown(int i);

	// Bubble up (upheap) -- fix the heap from a leaf to the root.
	void bubbleUp(int i);

	// Helpers for printing the heap's contents.
	void printHeapRecursive(int i, int depth);
	void printOneNode(int i, int depth);

	// Recursive helper to check partial ordering.
	bool isHeapOrderedRecursive(int i);

	int leftChildIndex(int index);
	int rightChildIndex(int index);
	int parentIndex(int index);
	bool hasNoChildren(int index);
	bool hasRightChild(int index);
	void swapElements(int index1, int index2);
	int lexicographicallyLeastChildIndex(int index);
};
