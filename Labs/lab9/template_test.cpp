#include "LinkedList.h"

#include <iostream>
#include<string>
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl;     // prints !!!Hello World!!!
	cout<<"Firstly the int list"<<endl<<endl;

	LinkedList<int> list1;
	list1.add(14);
	list1.add(20);
	list1.add(26);

	list1.printList(cout);
	cout << endl;

	LinkedList<int> l1(list1);
	l1.printList(cout);
	cout << endl<<endl;

	cout<<"Lastly the string list"<<endl<<endl;

	LinkedList<string> list2;
	list2.add("Takunda");
	list2.add("Jeffrey");
	list2.add("Thomas");

	list2.printList(cout);
	cout << endl;

	LinkedList<string> l2(list2);
	l2.printList(cout);
	cout << endl;

	return 0;
}
