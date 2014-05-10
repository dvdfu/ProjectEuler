#include <iostream>
#include <vector>

using namespace std;

// Coin Sums
// Problem 31
// How many different ways can £2 be made using any number of coins?

int count(int p) {
	int count = 0;
	for (int n200 = 0; n200 <= p; n200+=200) {
		for (int n100 = 0; n100 <= p-n200; n100+=100) {
			for (int n50 = 0; n50 <= p-n200-n100; n50+=50) {
				for (int n20 = 0; n20 <= p-n200-n100-n50; n20+=20) {
					for (int n10 = 0; n10 <= p-n200-n100-n50-n20; n10+=10) {
						for (int n5 = 0; n5 <= p-n200-n100-n50-n20-n10; n5+=5) {
							for (int n2 = 0; n2 <= p-n200-n100-n50-n20-n10-n5; n2+=2) {
								cout << n200 << "+" << n100 << "+" << n50 << "+" << n20 << "+" <<
		    					n10 << "+" << n5 << "+" << n2 << "+" << (p-n200-n100-n50-n20-n10-n5-n2) << "" << endl;
		    					count++;

								}	
							}	
						}	
					}	
				}	
			}
		}
	return count;
	}

int main() {
	cout << count(200) << endl;
	return 0;
}