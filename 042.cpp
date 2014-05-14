#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Coded Triangle Numbers
// Problem 42
// By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value.
// If the word value is a triangle number then we shall call the word a triangle word.
// Using a 16K text file containing nearly two-thousand common English words, how many are triangle words?

int getScore(string word) {
    int score = 0;
    for (int i = 0; i < word.size(); i++) {
        score += word.at(i)-64;
    }
    return score;
}

bool isTriangular(int n) {
    int total = 0;
    int i = 1;
    while (total < n) {
        total += i;
        i++;
        if (total == n) {
            return true;
        }
    }
    return false;
}

int main() {
    int numTriangular = 0;
    vector<string> words;
    string text;
    string line;
    ifstream input;
    input.open("input042.txt");
    input >> text;
    for (int i = 0; i < text.size(); i++) {
        if (text.substr(i, 1) == "\"") {
            int nextPos = text.substr(i+1).find_first_of("\"");
            line = text.substr(i+1, nextPos);
            words.push_back(line);
            text = text.substr(i+nextPos+2);
            i = 0;
        }
    }
    input.close();
    
    for (int i = 0; i < words.size(); i++) {
        if (isTriangular(getScore(words[i]))) {
            numTriangular++;
        }
    }
    
    cout << numTriangular << endl;
    return 0;
}
