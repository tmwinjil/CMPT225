#include <string>
#include <iostream>
#include "CharList.h"

using namespace std;

int main(int argc, char** argv)
{
	CharList *c =new CharList("abd");
	c->insert('c', 'd');
	cout << "result: "<< c.toString()<< endl;
}
