/**
    CS-11 Asn 4
    grader.cpp
    Purpose: Ex 4.3
    @author riselikethemoon
    @version 1.0 03/13/13
*/

#include <iostream>
using namespace std;


int main() {
    int guess = 0;
    string repeat = "y";

    while ("y" == repeat) {
        cout << "I'm thinking of a number between"
             << " 1 and 10.\nCan you guess it?\n\n"
             << "Enter your guess: ";
        cin >> guess;

        if (7 == guess) {
            cout << "*** Correct! ***\n";
        } else {
            cout << "Sorry, that is not correct.\n";
            cout << "Try again.\n";
        }
        cout << "\nDo you want to play again? (y/n) ";
        cin >> repeat;
    }
    cout << "Game over\n";
    return 0;
}
