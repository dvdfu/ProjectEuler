#include <iostream>

using namespace std;

int main() {
	const int size = 200;
	long sum = 0;
	long f[size];
	int stop = 0;
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i < size; i++) {
		f[i] = f[i-1]+f[i-2];
		if (f[i] > 4000000) {
			stop = i;
			break;
		}
	}

	for (int i = 0; i < stop; i++) {
		if (f[i]%2 == 0) {
			sum += f[i];
		}
	}

	cout << sum << endl;

	return 0;
}