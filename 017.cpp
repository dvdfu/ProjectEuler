#include <iostream>
#include <string>

using namespace std;

// Number Letter Counts
// Problem 17
// If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
// NOTE: Do not count spaces or hyphens.

string numToWord(int n) {
	if (n >= 1000) { // [1000]
		return "onethousand";
	}
	if (n / 100 > 0) { // [100,999]
		if (n % 100 == 0) { // X00, X[1,9]
			return numToWord(n / 100) + "hundred";
			}
		return numToWord(n / 100) + "hundredand" + numToWord(n % 100); // [X01,X99], X[1,9]
	}
	if (n >= 20) { // [20,99]
		if (n % 10 == 0) { // X0, X[2,9]
			switch (n / 10) {
				case 2: return "twenty"; break;
				case 3: return "thirty"; break;
				case 4: return "forty"; break;
				case 5: return "fifty"; break;
				case 6: return "sixty"; break;
				case 7: return "seventy"; break;
				case 8: return "eighty"; break;
				case 9: return "ninety"; break;
			}
		}
		return numToWord(n / 10 * 10) + numToWord(n % 10); // XY, X[2,9], Y[1,9]
	}
	switch (n) { // [0,19]
		case 0: return "zero"; break;
		case 1: return "one"; break;
		case 2: return "two"; break;
		case 3: return "three"; break;
		case 4: return "four"; break;
		case 5: return "five"; break;
		case 6: return "six"; break;
		case 7: return "seven"; break;
		case 8: return "eight"; break;
		case 9: return "nine"; break;
		case 10: return "ten"; break;
		case 11: return "eleven"; break;
		case 12: return "twelve"; break;
		case 13: return "thirteen"; break;
		case 14: return "fourteen"; break;
		case 15: return "fifteen"; break;
		case 16: return "sixteen"; break;
		case 17: return "seventeen"; break;
		case 18: return "eighteen"; break;
		case 19: return "nineteen"; break;
	}
}

int main() {
	int count = 0;
	for (int i = 1; i <= 1000; i++) {
		count += numToWord(i).length();
		}
	cout << count << endl;
	return 0;
}