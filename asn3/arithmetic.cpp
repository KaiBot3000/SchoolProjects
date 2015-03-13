/**
    CS-11 Asn 3
    arithmetic.cpp
    Purpose: Basic math
    @author riselikethemoon
    @version 1.0 03/04/13
*/

#include <iostream>
#include <cmath> // math function library
using namespace std;

int main() {
    int a = 7, b = 2;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;
    cout << "a + b / 2 = " << a + b / 2 << endl;
	cout << "(a + b) / 2 = " << (a + b) / 2 << endl;
	cout << "a % b = " << a % b << endl;
	cout << "sqrt(a + b) = " << sqrt(a + b) << endl;
    return 0;
}
