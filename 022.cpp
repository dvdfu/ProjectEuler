#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Name Scores
// Problem 22
// Using a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score. What is the total of all the name scores in the file?

int getScore(string word) {
    int score = 0;
    for (int i = 0; i < word.size(); i++) {
        score += word.at(i)-64;
    }
    return score;
}

int main() {
    int sum = 0;
    vector<string> names;
    string text;
    string line;
    ifstream input;
    input.open("input022.txt");
    input >> text;
    input.close();
    for (int i = 0; i < text.size(); i++) {
        if (text.substr(i, 1) == "\"") {
            int nextPos = text.substr(i+1).find_first_of("\"");
            line = text.substr(i+1, nextPos);
            names.push_back(line);
            text = text.substr(i+nextPos+2);
            i = 0;
        }
    }

    sort(names.begin(), names.end());
    
    for (int i = 0; i < names.size(); i++) {
        sum += getScore(names[i]) * (i + 1);
    }
    
    cout << sum << endl;
    return 0;
}