#include <iostream>
#include <math.h>

using namespace std;

// Digit Factorials
// Problem 34
// Find the sum of all numbers which are equal to the sum of the factorial of their digits.

int f(int n) {
	switch (n) {
		case 0: return 1;
		case 1: return 1;
		case 2: return 2;
		case 3: return 6;
		case 4: return 24;
		case 5: return 120;
		case 6: return 720;
		case 7: return 5040;
		case 8: return 40320;
		case 9: return 362880;
		default: return 0;
	}
}

int digit(int n, int d) {
	return n%((int)pow(10, d+1)) / pow(10, d);
}

int main() {
	// for any given set of numbers with d digits,
	// 9999...9 d times will have the greatest sum of digit factorials
	// the sum of factorials is greater than 9999...9 itself, until d = 7
	// no need to check for numbers greater than 9! * 7, since from then on,
	// the factorial sum will always be smaller than he number itself
	for (int i = 10; i < 2540160; i++) {
		int numDigits = log10(i) + 1;
		int sum = 0;
		for (int j = 0; j < numDigits; j++) {
			sum += f(digit(i, j));
		}
		if (sum == i) {
		cout << sum << endl;
		}
	}
	return 0;
}