/**
    CS-11 Asn 4
    seasons.cpp
    Purpose: Extra Credit; outputs season from Month and Day
    @author riselikethemoon
    @version 1.0 03/13/13
*/

#include <iostream>
using namespace std;

int main() {
    cout << "I will print the seasons " << endl;

    string repeat = "y";
    int month, day;
    string season;

    while (repeat == "y") {
        cout << "Enter the month (1-12): ";
        cin >> month;
        cout << "Enter the day (1-31): ";
        cin >> day;

        if (month >= 0 && month <= 3) {
            season = "Winter";
        } else if (month < 7) {
            season = "Spring";
        } else if (month < 10) {
            season = "Summer";
        } else if (month < 13) {
            season = "Fall";
        }

        if (month % 3 == 0 && day >= 21) {
            if (season == "Winter") {
                season = "Spring";
            } else if (season == "Spring") {
                season = "Summer";
            } else if (season == "Summer") {
                season = "Fall";
            } else if (season == "Fall") {
                season = "Winter";
            }
        }
        cout << "The season is " << season << endl;
        cout << "Run again? (y/n) ";
        cin >> repeat;
        cout << endl;
}


}
