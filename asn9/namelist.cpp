#include <iostream>
#include <vector>
using namespace std;

    void showNames(vector<string>& names);

int main() {
    vector<string> names;
        cout << "Enter a list of names\n"
             << "When finished enter the word: done\n";
        string input;
        do {
            getline(cin, input);
            if (input != "done") {
                names.push_back(input);
            }
        } while (input != "done");
    cout << "The first name on the list is: " << names[0] << endl;
    cout << "The last name on the list is: " << names[names.size() - 1] << endl;
    cout << "You entered:\n";
    showNames(names);

    return 0;
}

    void showNames(vector<string>& names) {
        for (unsigned i = 0; i < names.size(); i++) {
            cout << names[i] << endl;
    }
}
