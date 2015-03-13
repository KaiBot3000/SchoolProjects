/**
    CS-11 Asn 6
    words.cpp
    Purpose: Counts words in phrase
    @author riselikethemoon
    @version 1.0 04/10/13
*/

#include <iostream>
using namespace std;

/**
    Counts the words in input phrase

    @str the input phrase
    @return the number of words
*/

unsigned countWords@(string str) {
    int words = 1;
    for (unsigned i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            words++;
        }
    }

return words;
}

int main() {
    cout << "Enter a word or phrase: ";
    string phrase;
    getline(cin, phrase);
    unsigned words = countWords(phrase);
    cout << "Your input contains " << words << " words." << endl;

    return 0;
}
