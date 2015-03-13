#include <iostream>
#include <cmath>
using namespace std;

int main() {
    string str;
    int sum = 0;
    int num = 0;
    cout << "Enter an integer number: ";
    cin >> str;

    cout << "The number of characters is " << str.length() << ".\n" ;
    for (unsigned i = 0; i < str.length(); i++) {
        char ch = str[i];
        int digit = ch - 48;
        cout << "Digit: " << digit << endl;
        sum = sum + digit;
        int exp = str.length() - (int) i - 1;
        num = num + (int) (digit * pow(10.0, exp));
    }
    cout << "The sum of the digits is: "
         << sum << endl;
    cout << "The number is: " << num << endl;
    return 0;
}
