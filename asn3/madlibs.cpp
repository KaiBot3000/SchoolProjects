/**
    CS-11 Asn 3
    madlibs.cpp
    Purpose: Play the game of Madlibs!
    @author riselikethemoon
    @version 1.0 03/03/13
*/

#include <iostream>
using namespace std;

int main() {
    string firstName;
    string inName;
    string food;
    string number;
    string adj;
    string color;
    string animal;

    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your instructor's last name: ";
    cin >> inName;
    cout << "Enter a food: ";
    cin >> food;
    cout << "Enter a number between 100 and 120: ";
    cin >> number;
    cout << "Enter an adjective: ";
    cin >> adj;
    cout << "Enter a color: ";
    cin >> color;
    cout << "Enter an animal: ";
    cin >> animal;

    string madlib = "\nDear Instructor " + inName +
        ",\n \nI am sorry I am unable to turn in my homework today."
        + " First I ate a\nrotten " + food + ", which made me turn "
        + color + " and very sick. I came down \nwith a fever of "
        + number + ". Next, my " + adj
        + " pet must have \nsmelled the remains of the " + food
        + " on my homework, because my pet ate \nmy homework.\n\n"
        + "I knew I should not have ordered that " + animal
        + " on eBay!\n\nI know you do not accept late homework but"
        + " I am hoping you will make\nan exception in my case.\n\n"
        + "Sincerely,\n" + firstName;
    cout << madlib << endl;

}
