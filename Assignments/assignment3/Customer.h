/*
 * Customer.h
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 * 
 * 	Edited in: July 27 2019
 * 		Editor: Takunda Mwinjilo (301344066)
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include <iostream>

using namespace std;

class Customer {
public:
	Customer(void);
	Customer(string,char,int);
	Customer(const Customer& c);
	string getLastName(void) const;
	char getInitial(void) const;
	double getBalance(void) const;
	void setBalance(double);

	bool operator<(const Customer & c) const;
	bool operator<=(const Customer & c) const;
	bool operator>(const Customer & c) const;
	bool operator>=(const Customer & c) const;
	bool operator==(const Customer & c) const;
	bool operator!=(const Customer & c) const;

private:
	string lastName;
	char initial;
	double balance;
	friend ostream& operator<<(ostream & os,  Customer & c);

};

#endif /* CUSTOMER_H_ */
