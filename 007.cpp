#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(long n) {
    if (n < 2) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n%2 == 0 or n % 3 == 0) {
        return false;
    }
    int maxDiv = sqrt(n);
    int divi = 5;
    while (divi <= maxDiv) {
        if (n%divi == 0 || n%(divi+2) == 0) {
            return false;
        }
        divi += 6;
    }
    return true;
}

int main() {
    int n = 0;
    int prime;
    for (int i; n < 10001; i++) {
        if (isPrime(i)) {
            n++;
            prime = i;
        }
    }
    cout << prime << endl;
    return 0;
}