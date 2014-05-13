#include <iostream>

using namespace std;

// Integer Right Triangles
// Problem 39
// If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.
// {20,48,52}, {24,45,51}, {30,40,50}
// For which value of p = 1000, is the number of solutions maximised?

int numSolutions(int p) {
    int count = 0;
    // a <= b <= c
    // c >= p/3
    // b >= (p-c)/2
    // a^2+b^2=c^2
    for (int c = p/3; c < p; c++) {
        for (int b = (p-c)/2; b < p-c; b++) {
            int a = p-c-b;
            if (a*a+b*b == c*c) {
                count++;
                // cout << "{ " << a << ", " << b << ", " << c << " }" << endl;
            }
        }
    }
    return count;
}

int main() {
    int maxP = 0;
    int max = 0;
    for (int p = 1; p <= 1000; p++) {
        int s = numSolutions(p);
        if (s > max) {
            max = s;
            maxP = p;
            // cout << p << " has " << s << " solutions" << endl;
        }
    }
    cout << maxP << endl;
    return 0;
}
