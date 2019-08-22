#include "Customer.h"
#include "BSTree.h"

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;


void readCustomersFile(string fname, BSTree &);
void printCustVec(vector<Customer> vc);

int main()
{
	BSTree bst;
	vector<Customer> vc;
	vector<Customer> vc2;
	readCustomersFile("small_names.txt", bst);
	BSTree t(bst);
	t.remove("Franco", 'E');
	t.remove ("Garrison", 'A');	
	vc = bst.rangeSearch("Berger",'U',"Harris",'Z');
	printCustVec(vc);
	cout<<"New Tree:"<<endl;
	vc2 = t.rangeSearch("Berger",'U',"Harris",'Z');
	printCustVec(vc2);
	
}

void readCustomersFile(string fname, BSTree& bst) {
	// Read customer data from a file.
	// Create a file object and open the file
	ifstream inStream;
	inStream.open(fname.c_str());

	// Temporary variables for reading customers.
	string lname;
	char finit;
	int balance;

	// Only process file if opening it is successful
	if(!inStream.fail()){
		// Insert words in the vector
		while(!inStream.eof()){
			inStream >> lname >> finit >> balance; // Read customer.
			bst.insert(lname,finit,balance);
		}

		inStream.close(); //don't forget to close file
	}else{
		cout << "file not found ...";
	}
}


void printCustVec(vector<Customer> vc) {
	// Iterate over vc to print its contents.
	cout << "Customers in range:" << endl;
	for (int i=0; i < (int) vc.size(); i++) {
		cout << " " << vc[i] << endl;
	}
}