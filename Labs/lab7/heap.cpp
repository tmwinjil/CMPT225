#include "heap.h"


// Create a heap with space for n strings.
Heap::Heap(int n) {
	arr = new string[n];
	capacity = n;
	size = 0;
}

Heap::~Heap() {
	delete[] arr;
}


int Heap::leftChildIndex(int index) {
	return 2 * index + 1;
}
int Heap::rightChildIndex(int index) {
	return 2 * index + 2;
}
int Heap::parentIndex(int index) {
	return (index - 1) / 2;			// integer arithmetic rounds down
}
bool Heap::hasNoChildren(int index) {
	return leftChildIndex(index) > size - 1;
}
bool Heap::hasRightChild(int index) {
	return rightChildIndex(index) < size;
}
void Heap::swapElements(int index1, int index2) {
	string tmp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = tmp;
} 
int Heap::lexicographicallyLeastChildIndex(int index) {
	int lchild = leftChildIndex(index);
	int rchild = rightChildIndex(index);

	int leastChild = lchild;
	if (hasRightChild(index) && (arr[rchild] < arr[lchild])) {
		leastChild = rchild;
	}
	return leastChild;
}


// Insert a value into a heap.
// TO DO:: You need to write this.
bool Heap::insert(string n) {
	if (size == capacity)	
		return false;
	else {
		arr[size] = n;
		bubbleUp(size);
		size++;
		return true;
	}
}

// Bubble up (upheap) -- fix heap from a node up to the top.
// TO DO:: You need to write this.
void Heap::bubbleUp(int i) {		
	if(i == 0) {
		return;
	}
	int parent = parentIndex(i);
	if(i != 0 && arr[i] < arr[parent]) {
		swapElements(i, parent);
		bubbleUp(parent);
	}
}


// Remove and return the root of the heap.
string Heap::remove() {
	// Make sure the heap has something in it.
	if (size==0) {
		return "";
	}
	// Get the item to return.
	string rtn_string = arr[0];
		
	// Copy rightmost leaf into 0 position.
	arr[0] = arr[size-1];
	size--;
		
	// Bubble down the first element into its correct position.
	bubbleDown(0);
		
	return rtn_string;
}
	

// Bubble down (downheap) -- fix the heap from the root to the bottom.
void Heap::bubbleDown(int index) {
	if (hasNoChildren(index)) {
		return;
	}

	int leastChildIndex = lexicographicallyLeastChildIndex(index);

	if (arr[leastChildIndex] < arr[index]) {
		swapElements(leastChildIndex, index);
		bubbleDown(leastChildIndex);
	}
}



// Debugging methods.

// Print out the contents of the heap.
void Heap::printHeap() {
	printHeapRecursive(0,0);
}

// Recursive helper to print the heap's contents.
void Heap::printHeapRecursive(int i, int depth) {
	if (i >= size) {
		return;
	}
	
	// Note the preorder traversal.
	printOneNode(i, depth);							// Print the node i
	printHeapRecursive(leftChildIndex(i),  depth+1);		// Print the left subtree.
	printHeapRecursive(rightChildIndex(i), depth+1);		// Print the right subtree
}

void Heap::printOneNode(int i, int depth) {
	for (int indent=0; indent<depth; indent++) {
		cout << "  ";
	}
	cout << "--";
	cout << arr[i] << endl;
}



// Debug method, check the ordering property of the heap.
bool Heap::isHeapOrdered() {
	return isHeapOrderedRecursive(0);
}

bool Heap::isHeapOrderedRecursive(int i) {
	if (hasNoChildren(i)) {
		return true;
	}
	else if (!hasRightChild(i)) {
		return arr[i] < arr[leftChildIndex(i)];
	}
	else {
		if ((arr[i] < arr[leftChildIndex(i)]) && (arr[i] < arr[rightChildIndex(i)])) {
			return isHeapOrderedRecursive(leftChildIndex(i)) &&
                       isHeapOrderedRecursive(rightChildIndex(i)); 
		} else {
			return false;
		}
	}
}
