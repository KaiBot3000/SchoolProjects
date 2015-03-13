/**
    CS-11 Asn 5
    numanalysis.cpp
    Purpose: Averages inputs
    @author riselikethemoon
    @version 1.0 03/19/13
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int num = 0;
    int small;
    int large;
    int total = 0;
    int count = 0;
    cout << "This program analyzes numerical input.\n\n"
        << "Enter a number (Q to quit) : ";
        cin >> num;
        small = num;
        large = num;
        total = num;
        count = 1;
        while (cin) {
            cout << "Enter a number (Q to quit) : ";
            cin >> num;
            total += num;
            if (num > large) large = num;
            if (num < small) small = num;
            count++;

        }
    cout << "\nAverage value: " << total / count << endl;
    cout << "Smallest value: " << small << endl;
    cout << "Largest value: " << large << endl;
    cout << "Range: " << large - small << endl;
}
