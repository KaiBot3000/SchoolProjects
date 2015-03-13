#include <iostream>
using namespace std;

void print(const int values[], int size);
void printDouble(const double values[], int size);

int main() {
    // A list of integer scores
    const int NUM_SCORES = 10;
    int scores[NUM_SCORES] = {90, 91, 92, 93, 94, 95, 96, 97, 98, 99};
    cout << "Integer scores:\n";
    print(scores, NUM_SCORES);

    // A list of doubles holding temperatures
    const int TEMPS = 3;
    cout << "Double temperatures:\n";
    double temperature[TEMPS]= {25.7, 30.3, 40.9};
    printDouble(temperature, TEMPS);

    // A list of chars holding vowels
    char vowels[] = {'a', 'e', 'i', 'o', 'u', '\0'};
    cout << "\nC-string vowels:\n";
    cout << vowels << endl;


    return 0;
}

void print(const int values[], int size) {
    for (int i = 0; i < size; i++) {
        cout << values[i] << " ";
    }
    cout << endl;
}

void printDouble(const double values[], int size) {
    for (int i = 0; i < size; i++) {
        cout << values[i] << " ";
    }
}



