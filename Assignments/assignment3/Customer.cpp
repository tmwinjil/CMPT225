/*
 * Customer.cpp
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 * 
 * 	Edited in: July 27 2019
 * 		Editor: Takunda Mwinjilo (301344066)
 */
#include<string>
#include "Customer.h"

Customer::Customer(void)
{
    lastName = "";
    initial = '\0';
    balance = 0;
}

Customer::Customer(string surname, char firstInitial, int customerBalance) 
{
    lastName = surname;
    initial = firstInitial;
    balance = customerBalance;

}

Customer::Customer(const Customer& c)
{
    lastName = c.getLastName();
    initial = c.getInitial();
    balance = c.getBalance();
}


string Customer::getLastName(void) const
{
    return lastName;
}

char Customer::getInitial(void) const
{
    return initial;
}

double Customer::getBalance(void) const
{
    return balance;
}

void Customer::setBalance(double newBalance)
{
    balance = newBalance;
}

bool Customer::operator<(const Customer& c) const
{
    if(this->lastName < c.lastName) {
        return true;
    }
    else if (this->lastName == c.lastName && this->initial < c.initial) {
        return true;
    }
    else {
        return false;
    }
}

bool Customer::operator<=(const Customer& c) const
{
    return !(*this > c);
}

bool Customer::operator>(const Customer& c) const
{
    if(this->lastName > c.lastName) {
        return true;
    }
    else if (this->lastName == c.lastName && this->initial > c.initial) {
        return true;
    }
    else {
        return false;
    }
}

bool Customer::operator>=(const Customer& c) const
{
    return !(*this < c);
}

bool Customer::operator==(const Customer& c) const
{
    if (this->lastName == c.lastName && this->initial == c.initial)
        return true;
    else
        return false;

}

bool Customer::operator!=(const Customer& c) const
{
    if (this->lastName != c.lastName || this->initial != c.initial) 
        return true;
    else
        return false;
}

ostream& operator<<(ostream & os,  Customer& c) 
{
    os<<c.lastName<<", "<<c.initial<<". ("<<c.balance<<")";
    return os;
}
