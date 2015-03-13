/**
    CS-11 Asn 3
    length.cpp
    Purpose: Converts meters into miles, feet, and inches.
    @author riselikethemoon
    @version 1.0 03/04/13
*/

#include <iostream>
using namespace std;

int main() {
    double meters = 0.0;
    cout << "Enter the distance in meters: ";
    cin >> meters;
    cout << meters << " meters is "
    << meters * 0.000621371 << " miles," << endl
    << "or " << meters * 3.28084 << " feet" << endl
    << "or " << meters * 39.3701 << " inches." << endl;
}
