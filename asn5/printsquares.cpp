/**
    CS-11 Asn 5
    printsquares.cpp
    Purpose: Prints squares.
    @author riselikethemoon
    @version 1.0 03/20/13
*/

#include <iostream>
using namespace std;

int main() {
    cout << "This program prints a filled and hollow square.\n\n"
         << "Enter the length of a side: ";
    int size;
    cin >> size;
    for (int row = 1; row <= size; row++) {
        for (int col = 1; col <= size; col++) {
            cout << "*";
        }
        cout << " ";
        for (int col = 1; col <= size; col++) {
            if (row == 1 || row == size || col == 1 || col == size) {
                cout << "*";
            } else {
                cout << " ";
        }
        }
            cout << endl;
    }
}
