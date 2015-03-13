/**
    CS-11 Asn 6
    vowels.cpp
    Purpose: Counts vowels in phrase
    @author riselikethemoon
    @version 1.0 04/10/13
*/

#include <iostream>
using namespace std;

/**
    Counts the vowels in input phrase

    @str the input phrase
    @return the number of vowels
*/

unsigned countVowels(string str) {
    int vowels = 0;
    for (unsigned i = 0; i < str.length(); i++) {
        if (str[i] == 'a' || str[i] == 'A' || str[i] == 'e' || str[i] == 'E'
            || str[i] == 'i' || str[i] == 'I' || str[i] == 'o' || str[i] == 'O'
            || str[i] == 'u' || str[i] == 'U') {
            vowels++;
        }
    }

return vowels;
}

int main() {
    cout << "Enter a word or phrase: ";
    string phrase;
    getline(cin, phrase);
    unsigned vowels = countVowels(phrase);
    cout << "Your input contains " << vowels << " vowels." << endl;

    return 0;
}
