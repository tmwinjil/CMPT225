#include <iostream>
#include "heap.h"
using namespace std;

const int HEAP_SIZE = 200;

int main (void) {

	Heap h(HEAP_SIZE);

	int n_insert;

	// Get number of words to be inserted.
	cout << "How many words to insert?" << endl;
	cin >> n_insert;

	string word;
	for (int i=0; i<n_insert; i++) {
		cout << "Enter word" << endl;
		cin >> word;
		// Attempt to insert word.  If heap is full, exit program with return code 1.
		if (!h.insert(word))
			return 1;

		cout << "Current heap contents:" << endl;
		h.printHeap();
		cout << "Is the heap correctly ordered? " << h.isHeapOrdered() << endl;

	}

	h.printHeap();
	cout << h.isHeapOrdered() << endl;

	cout << "Printing in order by removal from heap:" << endl;
	for (int i=0; i<n_insert; i++) {
		cout << h.remove() << endl;
	}

	return 0;
}
