#include <iostream>

using namespace std;

void printDate(int days, int day, int month, int year) {
    string dayPrint;
    string monthPrint;
    int dayOfWeek = days % 7;
    switch (dayOfWeek) {
        case 0: dayPrint = "Sunday"; break;
        case 1: dayPrint = "Monday"; break;
        case 2: dayPrint = "Tuesday"; break;
        case 3: dayPrint = "Wednesday"; break;
        case 4: dayPrint = "Thursday"; break;
        case 5: dayPrint = "Friday"; break;
        case 6: dayPrint = "Saturday"; break;
    }
    switch (month) {
        case 1: monthPrint = "January"; break;
        case 2: monthPrint = "February"; break;
        case 3: monthPrint = "March"; break;
        case 4: monthPrint = "April"; break;
        case 5: monthPrint = "May"; break;
        case 6: monthPrint = "June"; break;
        case 7: monthPrint = "July"; break;
        case 8: monthPrint = "August"; break;
        case 9: monthPrint = "September"; break;
        case 10: monthPrint = "October"; break;
        case 11: monthPrint = "November"; break;
        case 12: monthPrint = "December"; break;
    }
    cout << "Day " << days << ", " << dayPrint << ", " << monthPrint << " " << day << ", " << year << endl;
}

int main() {
    int numSundays = 0;
    int days = 0;
    int day = 31;
    int month = 12;
    int year = 1899;
    while (year < 2001) {
        days++;
        if (days % 7 == 0 && year > 1900 && day == 1) {
            numSundays++;
        }
        
        day++;
        switch (month) {
        case 4: case 6: case 9: case 11:
            if (day == 31) {
                day = 1;
                month++;
            }
        break;
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if (day == 32) {
                day = 1;
                month++;
            }
        break;
        case 2:
            bool leapYear = (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
            if (leapYear) {
                if (day == 30) {
                    day = 1;
                    month++;
                }
            } else if (day == 29) {
                day = 1;
                month++;
            }
        break;
        }
        
        if (month == 13) {
            month = 1;
            year++;
        }
        // printDate(days, day, month, year);
    }
    cout << numSundays << " Sundays";
    return 0;
}
