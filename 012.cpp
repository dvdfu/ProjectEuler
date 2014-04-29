#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>

using namespace std;

long countDiv(long n) {
    long div = 0;
    long k = sqrt(n);
    for (long i = 1; i <= k; i++) {
        if (n%i == 0) {
            div += 2;
        }
    }
    if (k*k == n) {
        div--;
    }
    return div;
}

int main() {
    long d = 1;
    long k = 1;
    int n = 1;
    while (d < 500) {
        k = n*(n+1)/2;
        d = countDiv(k);
        n++;
    }
    cout << k << endl;
    return 0;
}