/**
    CS-11 Asn 5
    minvalue.cpp
    Purpose: Finds minimum value.
    @author riselikethemoon
    @version 1.0 03/20/13
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "This program finds a minimum input value.\n\n";
    cout << "Enter a number (Q to quit): ";
    int num;
    cin >> num;
    int min = num;
    while (cin) {
        cout << "Enter a number (Q to quit): ";
        cin >> num;
        if (num < min) min = num;
    }
    cout << "\nMinimum value: " << min << endl;
}
