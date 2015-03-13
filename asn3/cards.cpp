/**
    CS-11 Asn 3
    cards.cpp
    Purpose: Translate shorthand notation for a card
    @author riselikethemoon
    @version 1.0 03/06/13
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    string card;
    cout << "Enter the card notation: ";
    cin >> card;

    string kind = card.substr(0,1);
    string suit;
    string kindName;
    string suitName;

    if ("1" == kind) {
        kindName = "10";
        suit = card.substr(2,1);
    } else if ("2" == kind) {
        kindName = "2";
        suit = card.substr(1,1);
    } else if ("3" == kind) {
        kindName = "3";
        suit = card.substr(1,1);
    } else if ("4" == kind) {
        kindName = "4";
        suit = card.substr(1,1);
    } else if ("5" == kind) {
        kindName = "5";
        suit = card.substr(1,1);
    } else if ("6" == kind) {
        kindName = "6";
        suit = card.substr(1,1);
    } else if ("7" == kind) {
        kindName = "7";
        suit = card.substr(1,1);
    } else if ("8" == kind) {
        kindName = "8";
        suit = card.substr(1,1);
    } else if ("9" == kind) {
        kindName = "9";
        suit = card.substr(1,1);
    } else if ("j" == kind or "J" == kind) {
        kindName = "Jack";
        suit = card.substr(1,1);
    } else if ("q" == kind or "Q" == kind) {
        kindName = "Queen";
        suit = card.substr(1,1);
    } else if ("k" == kind or "K" == kind) {
        kindName = "King";
        suit = card.substr(1,1);
    } else if ("a" == kind or "A" == kind) {
        kindName = "Ace";
        suit = card.substr(1,1);
}

    if ("D" == suit || "d" == suit) {
        suitName = "Diamonds\n";
    } else if ("H" == suit || "h" == suit) {
        suitName = "Hearts\n";
    } else if ("S" == suit || "s" == suit) {
        suitName = "Spades\n";
    } else if ("C" == suit || "c" == suit) {
        suitName = "Clubs\n";

    }

string answer = kindName + " of " + suitName;
cout << answer;

}

