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

bool isRotationPrime(int n) {
    int digits = log10(n) + 1;
    int number[digits];
    for (int i = 0; i < digits; i++) {
        number[i] = n % 10;
        n /= 10;
    }
    for (int i = 1; i < digits; i++) {
        int spot = i % digits;
        int perm = 0;
        for (int j = 0; j < digits; j++) {
            perm += number[(i+j)%digits] * pow(10, j%digits);
        }
        if (!isPrime(perm)) {
            return false;
        }
    }
    return true;
}

int main() {
    int sum = 0;
    for (int i = 2; i < 1000000; i++) {
        if (isPrime(i) && isRotationPrime(i)) {
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}
