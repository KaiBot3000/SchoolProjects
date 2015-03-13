/**
    CS-11 Asn 7
    postal.cpp
    Purpose: Converts zipcodes into postal barcodes.
    @author riselikethemoon
    @version 1.0 04/16/13
*/

#include <iostream>
#include <iomanip>
using namespace std;

/**
    Turns a single digit into a bar code.

    @param digit the single digit to encode.
    @return a bar code of the digit using "|" as the long
    bar and "," as the half bar.
*/
string buildDigit(int digit);

/**
    Turns a string into a bar code.

    @param zip the string to encode.
    @param checkNumber holds the sum of the digits of the string
    @return a bar code of the string using "|" as the long
    bar and "," as the half bar.
*/
string buildBarcode(string zip, int& checkNumber);


int main() {

    string zip = "1", digitCode, zipCode, checkCode, fullCode;
    cout << "Enter a zip code and I will generate a barcode.\nEnter 0 to exit.\n" << endl;
    cout << "Enter a zip code : ";
    cin >> zip;
    while (zip != "0") {
        int checkNumber = 0;
        zipCode = buildBarcode(zip, checkNumber);
        checkNumber = 10 - checkNumber % 10;
        checkCode = buildDigit(checkNumber);
        cout << "The bar code for " << zip << " is: "
            << "|" << zipCode << checkCode << "|" << endl;
        cout << "\nEnter a zip code : ";
        cin >> zip;
        }
            cout << "\nMay your mail zip to its destination!\n";
}

// Converts single digit to barcode
string buildDigit(int digit) {
    string digitCode;
    if (digit == 1) {
        digitCode = ",,,||";
    } else if (digit == 2) {
        digitCode = ",,|,|";
    } else if (digit == 3) {
        digitCode = ",,||,";
    } else if (digit == 4) {
        digitCode = ",|,,|";
    } else if (digit == 5) {
        digitCode = ",|,|,";
    } else if (digit == 6) {
        digitCode = ",||,,";
    } else if (digit == 7) {
        digitCode = "|,,,|";
    } else if (digit == 8) {
        digitCode = "|,,|,";
    } else if (digit == 9) {
        digitCode = "|,|,,";
    } else if (digit == 0) {
        digitCode = "||,,,";
    } else if (digit == 10) {
        digitCode = "||,,,";
    }
    return digitCode;
}


// Builds Barcode from string, computes check number
string buildBarcode(string zip, int& checkNumber){
    char stringDigit;
    string digitCode, zipCode;
    int digit;
    for (unsigned i = 0; i < zip.length(); i++) {
        stringDigit = zip[i];
        digit = stringDigit - 48;
        checkNumber += digit;
        digitCode = buildDigit(digit);
        zipCode += digitCode;
    }
    return zipCode;
}


