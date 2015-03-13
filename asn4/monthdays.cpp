/**
    CS-11 Asn 4
    monthdays.cpp
    Purpose: Outputs number of days in the month provided
    @author riselikethemoon
    @version 1.0 03/12/13
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "I will print the number of days in a month." << endl;
    string repeat = "y";
    int month;
    while (repeat == "y") {
        cout << "Enter the month (1-12): ";
        cin >> month;
        if (month == 1 || month == 3 || month == 5 || month == 7
                || month == 8 || month == 10 || month == 12) {
                cout << "31 days" << endl;
            } else if (month == 4 || month == 6 || month == 9 || month == 11) {
                cout << "30 days" << endl;
            } else if (month == 2) {
                cout << "28 or 29 days" << endl;}
        cout << "Run again? (y/n) ";
        cin >> repeat;
        cout << endl;
    }
}
