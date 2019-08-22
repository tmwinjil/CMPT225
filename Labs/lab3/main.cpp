#include <iostream>
#include "RuntimeException.h"
#include "LaboratoryException.h"
#include "Laboratory.h"

using namespace std;

void test1(void);
void test2(void);
void test3(void);
void test4(void);

int main()
{
	test1();
	test2();
	test3();
	test4();
};

void test1()
{
	try{
		throw RuntimeException("error");
		cout<<"Failed to throw in test1"<<endl;
	}
	catch(RuntimeException e) {
		cout<<"Passed. "<<e.getMessage()<<endl;
	}
	return;
}

void test2(void)
{
	for (int i = 1; i <= 100 ; i++)
	{
		try {
			if (i == 4)
			{
				throw RuntimeException("error: i = 4");
				cout<<"Failed to throw \"i = 4\" exception"<<endl;
			}
		}
		catch(RuntimeException e) {
			cout<<"Passed at  i = "<< i << " "<<e.getMessage()<<endl;
			return;
		}
	}
	cout<<"Failed. i reached 100"<<endl;

}

void test3(void)
{
	for (int i = 1; i <= 100 ; i++)
	{
		try {
			if (i == 4)
			{
				throw LaboratoryException("error: i = 4");
				cout<<"Failed to throw \"i = 4\" exception"<<endl;
			}
		}
		catch(RuntimeException e) {
			cout<<"Passed at  i = "<< i << " "<<e.getMessage()<<endl;
			return;
		}
	}
	cout<<"Failed. i reached 100"<<endl;

}

void test4(void)
{
	try{
		Laboratory lab;
		lab.execute();
		cout<<"Failed to execute lab"<<endl;
	}
	catch(LaboratoryException e) {
		cout<<"Passed. "<<e.getMessage()<<endl;
	}
}
