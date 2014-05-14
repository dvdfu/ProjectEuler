#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int n = 0;

// Largest Problem in a Grid
// Problem 11
// What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20x20 grid?

void setP(int i1, int i2, int i3, int i4) {
    if (i1*i2*i3*i4 > n) {
        n = i1*i2*i3*i4;
    }
}

int main() {
    int p;
    int grid[20][20];
    string line;
    ifstream file;
    file.open("input011.txt");
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            file >> line;
            grid[j][i] = atoi(line.c_str());
        }
    }
    file.close();
    
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 16; j++) {
            setP(grid[j][i], grid[j+1][i], grid[j+2][i], grid[j+3][i]);
            setP(grid[i][j], grid[i][j+1], grid[i][j+2], grid[i][j+3]);
        }
    }
    
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            setP(grid[i][j], grid[i+1][j+1], grid[i+2][j+2], grid[i+3][j+3]);
            setP(grid[19-i][j], grid[18-i][j+1], grid[17-i][j+2], grid[16-i][j+3]);
        }
    }
    
    cout << n << endl;
    return 0;
}
