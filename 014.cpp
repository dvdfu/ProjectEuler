#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>

using namespace std;

int collatz(int n) {
    long i = n;
    int count = 1;
    //cerr << i << endl;
    while (i != 1) {
        count++;
        if (i%2 == 0) {
            i = i/2;
        }
        else {
            i = i*3+1;
        }
        //cerr << i << endl;
    }
    return count;
}

int main() {
    int maxC = 0;
    int maxI = 0;
    int c;
    for (int i = 1; i < 1000000; i++) {
        c = collatz(i);
        if (c > maxC) {
            maxC = c;
            maxI = i;
            //cout << maxI << " chains " << maxC << endl;
        }
    }
    cout << maxI << endl;
    return 0;
}