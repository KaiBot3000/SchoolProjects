/**
    CS-11 Asn 6
    doublefun.cpp
    Purpose: Reads double numbers.
    @author riselikethemoon
    @version 1.0 04/10/13
*/

#include <iostream>
using namespace std;

/**
    Reads in double numbers with input validation

    @prompt the desired prompt
    @return the number entered
*/

double readDouble(string prompt) {
    double num;
    bool finished = true;
    do {
        cout << prompt;
        cin >> num;
        if (cin.fail()) {
            cout << "Please enter numbers only!\n";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        } else {
            finished = false;
        }
    } while (finished);
        return num;
}


int main() {
    double num;
    num = readDouble("Enter a floating-point number: ");
    cout << "You entered:" << num << endl;
    return 0;
}
