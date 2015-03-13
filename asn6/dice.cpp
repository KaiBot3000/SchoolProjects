#include <iostream>
using namespace std;

int main() {
    int i = 0;
    srand(time(0));
    for (i = 0; i < 10; i++) {
        int die1 = rand() % 6 + 1;
        int die2 = rand() % 6 + 1 ;
        cout << "You rolled a " << die1
        << " and a " << die2 << endl;
    }

    return 0;
}
