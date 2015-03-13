#include <fstream>   // for file I/O
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ifstream fin;
    fin.open("rawdata.txt");
    if (fin.fail()) {
        cout << "Input file failed to open.\n";
        exit(-1);
    }

    vector<double> data;
    double value;
    while (fin >> value) {
        cout << "Read: " << value << endl;
        data.push_back(value);
    }
    fin.close();

    double sum = 0;
    int count = data.size();
    for (int i = 0; i < count; i++) {
        sum = sum + data[i];
    }
    double average = sum / count;
    cout << "average = " << average << endl;

    ofstream fout;
    fout.open("output.txt");
    if (fout.fail()) {
        cout << "Output failed\n";
        exit(-1);
    }

    for (int i = 0; i < count; i++) {
        fout << data[i] << endl;
    }
    fout << "average = " << average << endl;
    fout.close();

    return 0;
}
