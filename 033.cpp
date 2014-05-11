#include <iostream>
#include <vector>

using namespace std;

// Digit Cancelling Fractions
// Problem 33
// The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.
// We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
// There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.
// If the product of these four fractions is given in its lowest common terms, find the value of the denominator.

bool isCurious(int n, int d) {
	// n1/d1 == n2/d2
	// n1*d2 == n2*d1
	if (n/10 == d/10 && n/10 != 0) { // nt = dt
		return n*(d%10) == (n%10)*d;
	}
	else if (n/10 == d%10 && n/10 != 0) { // nt = do
		return n*(d/10) == (n%10)*d;
	}
	else if (n%10 == d/10 && n%10 != 0) { // no = dt
		return n*(d%10) == (n/10)*d;
	}
	else if (n%10 == d%10 && n%10 != 0) { // no = do
		return n*(d/10) == (n/10)*d;
	}
	return false;
}

int gcdOf(int a, int b) {
	if (a > b) {
		return gcdOf(a-b, b);
	}
	else if (a < b) {
		return gcdOf(a, b-a);
	}
	return a;
}

int main() {
	int num = 1;
	int den = 1;
	int gcd = 1;
	for (int i = 10; i < 100; i++) {
		for (int j = i+1; j < 100; j++) {
			if (isCurious(i,j)) {
				num *= i;
				den *= j;
			}
		}
	}
	gcd = gcdOf(num, den);
	num /= gcd;
	den /= gcd;
	cout << num << "/" << den << endl;
	return 0;
}