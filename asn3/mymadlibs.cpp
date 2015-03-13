/**
    CS-11 Asn 3
    mymadlibs.cpp
    Purpose: Extra Credit Madlibs
    @author riselikethemoon
    @version 1.0 03/05/13
*/

#include <iostream>
using namespace std;

int main() {
    string planet;
    string fuel;
    string chemical;
    string adjective;
    string food;

    cout << "Enter a planet: ";
    cin >> planet;
    cout << "Enter a fuel type: ";
    cin >> fuel;
    cout << "Enter a chemical: ";
    cin >> chemical;
    cout << "Enter an adjective: ";
    cin >> adjective;
    cout << "Enter an food: ";
    cin >> food;

    string madlib = "\nFor our trip to " + planet +
        ", we'll need lots of " + fuel
        + ".\nI hope we remember to pack the " +
        chemical + " device,\nbecause without it we'll die a " +
        adjective + " death.\nHow many tons of "
        + food + " do you think we'll need?\n";
    cout << madlib << endl;

}
