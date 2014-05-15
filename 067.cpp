#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

// Maximum Path Sum II
// Problem 67
// Find the maximum total from top to bottom of the triangle below:

int main() {
    const int height = 100;
    int nums[height][height] = { 0 };
    int sum[height][height] = { 0 };
    int n = 0;
    ifstream input;
    input.open("input067.txt");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= i; j++) {
            string line;
            input >> line;
            nums[i][j] = atoi(line.c_str());
            
            if (i == 0) {
                sum[0][0] = nums[0][0];
            }
            else if (j == 0) {
                sum[i][0] = sum[i-1][0] + nums[i][0];
            }
            else if (j == i) {
                sum[i][j] = sum[i-1][j-1] + nums[i][j];
            }
            else {
                sum[i][j] = max(sum[i-1][j], sum[i-1][j-1]) + nums[i][j];
            }
            
            if (sum[i][j] > n) {
                n = sum[i][j];
            }
            // cout << sum[i][j] << " ";
        }
        // cout << endl;
    }
    cout << n << endl;
    input.close();
    
    return 0;
}
