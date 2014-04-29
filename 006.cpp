#include <iostream>

using namespace std;

int main() {
	const int num = 100;
	int squareSum = 0;
	int sumSquare = 0;
	for (int i = 1; i <= 100; i++) {
		squareSum += i;
		sumSquare += i*i;
	}
	squareSum *= squareSum;
	cout << squareSum-sumSquare << endl;
	return 0;
}