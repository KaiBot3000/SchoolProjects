/**
    CS-11 Asn 4
    comptime.cpp
    Purpose: Correctly order the years inputted
    @author riselikethemoon
    @version 1.0 03/11/13
*/

#include <iostream>
using namespace std;

int main () {
    cout << "Enter two times and I will print which comes first." << endl;
    string repeat = "y";
    int time1, time2;
    while (repeat == "y") {
            cout << "Enter the first time in military format (like, 1930): ";
            cin >> time1;
            cout << "Enter the second time: " ;
            cin >> time2;
            if (time1 < time2) {
                cout << time1 << " " << time2 << endl;
            } else if (time1 > time2) {
                cout << time2 << " " << time1 << endl;
            } else if (time1 == time2) {
                cout << time1 << " == " << time2 << endl;
            }
            cout << "Run again? (y/n) ";
            cin >> repeat;
            }
}
