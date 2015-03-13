/**
    CS-11 Asn 3
    nameapp.cpp
    Purpose: Processes names
    @author riselikethemoon
    @version 1.0 02/28/13
*/

#include <iostream>
using namespace std;

int main() {
    string firstName, lastName, fullName;
    cout << "First Name: ";
    cin >> firstName;
    cout << "Last Name: ";
    cin >> lastName;
    fullName = firstName + " " + lastName;
    cout << "Welcome \"" << fullName << "\"!\n";
    string initials = firstName.substr(0, 1)
        + lastName.substr(0, 1);
    cout << "Your initials: " << initials << endl;

    return 0;
}
