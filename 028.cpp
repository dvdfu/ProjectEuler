#include <iostream>

using namespace std;

// Number Spiral Diagonals
// Problem 28
// Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed. It can be verified that the sum of the numbers on the diagonals is 101. What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?

int main() {
    int sum = 0;
    int n = 1001;
    for (int i = 1; i <= n; i += 2) {
        sum += i * i;
        if (i > 1) {
            sum += (i * i - 2 * (i - 1)) * 3;
        }
    }
    cout << sum << endl;
    return 0;
}
