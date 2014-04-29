#include <iostream>

using namespace std;

int main() {
	long num = 0;
	bool check = false;
	for (long i = 1; !check; i++) {
		check = true;
		num = i;
		for (int j = 2; j <= 20; j++) {
			if (i%j == 0) {
				continue;
			}
			else {
				check = false;
				break;
			}
		}
	}
	cout << num << endl;
	return 0;
}