#include <iostream>

using namespace std;

int main() {
	for (int i = 1; i < 500; i++) {
		for (int j = i; j < 500; j++) {
			int k = 1000-i-j;
			if (i*i+j*j == k*k) {
				cout << i*j*k << endl;
				break;
			}
		}
	}
	return 0;
}