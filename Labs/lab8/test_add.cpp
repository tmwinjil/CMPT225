#include "Fraction.h"
#include <iostream>

using namespace std;

int main (void) {
  Fraction a(2,3);
  Fraction b(1,6);

  // Test addition of fractions.
  cout << a + b;
}
