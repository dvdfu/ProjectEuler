#include <iostream>

using namespace std;

bool palindrome(int n) {
	return n/100000 == n%10 
	&& n/10000%10 == n/10%10 
	&& n/1000%10 == n/100%10;
}

int main() {
	int max = 0;
	for (int i = 100; i < 1000; i++) {
		for (int j = i; j < 1000; j++) {
			if (palindrome(i*j)) {
				if (i*j > max) {
					max = i*j;
				}
			}
		}
	}
	cout << max << endl;
	return 0;
}