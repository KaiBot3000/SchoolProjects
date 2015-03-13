/**
    CS-11 Asn 4
    grader.cpp
    Purpose: Ex 4.2
    @author riselikethemoon
    @version 1.0 03/13/13
*/

#include <iostream>
using namespace std;

int main() {
    double score;
    cout << "Enter a score: ";
    cin >> score;

    string grade;
    if (score >= 90) {
        grade = "A";
    } else if (score >= 80) {
        grade = "B";
    } else if (score >= 70) {
        grade = "C";
    } else if (score >= 60) {
        grade = "D";
    } else if (score < 60) {
        grade = "F";
    }
    cout << grade << endl;

    return 0;
}
