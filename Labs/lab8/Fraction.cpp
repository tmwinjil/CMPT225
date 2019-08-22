#include <iostream>
#include "Fraction.h"

using namespace std;
// invariant: denominator is always positive.
//            fraction always in lowest terms (simplified).


// Default constructor
Fraction::Fraction(void)
{
	numerator = 0;
	denominator = 1;
}

// Constructor
Fraction::Fraction(int n, int d)
{
	if (d == 0) {
		throw new DivideByZeroException();
	} else {
		numerator = n;
		denominator = d;
		simplify();
	}
}

Fraction::~Fraction(void)
{
}

// Returns the (positive) greatest common divisor of two integers
int Fraction::gcd(int a, int b) const {
	if (a < 0) a = -a;
	if (b < 0) b = -b;

	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

// Simplifies the receiver
void Fraction::simplify(){
	int factor = gcd(numerator, denominator);
	numerator = numerator / factor;
	denominator = denominator / factor;
}

// Overloaded Operators
Fraction Fraction::operator+ (const Fraction& f) const
{
	Fraction result;	
	result.numerator = (this->numerator * f.denominator) + (f.numerator * this->denominator);
	result.denominator = this->denominator * f.denominator;
	result.simplify();
	return result;
}

Fraction Fraction::operator- (const Fraction& f) const
{
	Fraction result;	
	result.numerator = (this->numerator * f.denominator) - (f.numerator * this->denominator);
	result.denominator = this->denominator * f.denominator;
	result.simplify();
	return result;
}

Fraction Fraction::operator* (const Fraction& f) const
{
	Fraction result;	
	result.numerator = this->numerator * f.numerator;
	result.denominator = this->denominator * f.denominator;
	result.simplify();
	return result;
}

Fraction Fraction::operator/ (const Fraction& f) const
{
	Fraction result;	
	result.numerator = this->numerator * f.denominator;
	result.denominator = this->denominator * f.numerator;
	result.simplify();
	return result;
}

ostream & operator<<(ostream & os, const Fraction & f){
	os << f.numerator << "/" << f.denominator << " ";
	return os;
}
