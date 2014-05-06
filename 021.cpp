#include <iostream>
#include <math.h>

using namespace std;

// Amicable Numbers
// Problem 21
// Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
// If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
// Evaluate the sum of all the amicable numbers under 10000.

int d(int n) {
	int sum = 0;
	int k = sqrt(n);
	for (int i = 1; i <= k; i++) {
		if (n%i == 0) {
			sum += i + n/i;
			}
		}
		if (k*k == n) {
			sum -= k;
		}
	sum -= n;
	return sum;
}

int main() {
	int sumAmicable = 0;
	for (int i = 1; i < 10000; i++) {
		if (i == d(d(i)) && i != d(i)) {
			sumAmicable += i;
			}
		}
	cout << sumAmicable << endl;
	return 0;
}