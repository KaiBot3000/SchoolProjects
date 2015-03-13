/**
    CS-11 Asn 4
    spectrum.cpp
    Purpose: Outputs part of spectrum from wavelength
    @author riselikethemoon
    @version 1.0 03/13/13
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "Enter a wavelength and I will report the type of";
    cout << endl << "the electromagnetic spectrum. \n"  << endl;

    string repeat = "y";
    float wave;

    while (repeat == "y") {
        cout << "Enter a wavelength in meters: ";
        cin >> wave;
        if (wave >= 10e-1) {
            cout << "Radio Waves" << endl;
        } else if (wave >= 10e-3) {
            cout << "Microwaves" << endl;
        } else if (wave >= 7 * 10e-7) {
            cout << "Infrared" << endl;
        } else if (wave >= 4 * 10e-7) {
            cout << "Visible Light" << endl;
        } else if (wave >= 10e-8) {
            cout << "Ultraviolet" << endl;
        } else if (wave >= 10e-11) {
            cout << "X-rays" << endl;
        } else if (wave < 10e-11) {
            cout << "Gamma Rays" << endl;}

        cout << "Run again? (y/n) ";
        cin >> repeat;
        cout << endl;
    }
}
