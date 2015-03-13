#include <fstream>   // for file I/O
#include <iostream>
using namespace std;

void toScreen(ifstream& fin);

int main() {
    string filename, line;

    cout << "Enter a file name: ";
    cin >> filename;

    // Start adding code here
    ifstream fin;
    fin.open(filename.c_str());
    if (fin.fail()) {
        cout << "Error!";
        exit(-1);
    }

    toScreen(fin);
    fin.close();

    return 0;
}

// Add new function toScreen() here
void toScreen(ifstream& fin) {
    int count = 1;
    string line;
    while (getline(fin, line)) {
        cout << count << ": " << line << endl;
        count++;
    }
}


