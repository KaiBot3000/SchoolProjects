#include <iostream>
using namespace std;

int main() {
    double sumScores = 0;
    double nextScore = 0;
    int count = 0;

    do {
        count++;
        cout << "Enter score #" << count << ": ";
        cin >> nextScore;

        if (cin.fail()) {
            cout << "Error: please enter a number. " << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n'); //clear buffer
        } else if (nextScore >= 0) {
            sumScores += nextScore;

        }
    } while (nextScore >= 0);
     cout << "Sum of scores: " << sumScores << endl;

    return 0;
}
