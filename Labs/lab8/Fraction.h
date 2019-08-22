#pragma once
#include <string>
using namespace std;

class Fraction
{
public:
	// Constructors and Destructor
	Fraction(void);
	Fraction(int n, int d);
	~Fraction(void);
	
	// Overloaded operators
	Fraction operator+(const Fraction & f) const;
	Fraction operator-(const Fraction & f) const;
	Fraction operator*(const Fraction & f) const;
	Fraction operator/(const Fraction & f) const;


private:
	int numerator;		//the "top" of the fraction
	int denominator;	//the "bottom" of the fraction

	// PRE: 
	// POST: Fraction is simplified, e.g. 3/9, simplifies to 1/3
	void simplify();

	// PRE:
	// POST: Returns the (positive) greatest common divisor of a and b
	int gcd(int a, int b)const;
	
	// Friend functions
	friend ostream & operator<<(ostream & os, const Fraction & f);
};

class DivideByZeroException {};
