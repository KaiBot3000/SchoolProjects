#include <iostream>
using namespace std;

struct Rectangle {
    int length;
    int width;
};

void read(Rectangle& rect);

void print(Rectangle& rect);

int main() {
    Rectangle toast;
    read(toast);
    print(toast);

    return 0;
}

void read(Rectangle& rect) {
    cout << "Enter the rectangle length: ";
    cin >> rect.length;
    cout << "Enter the rectangle width: ";
    cin >> rect.width;
}

void print(Rectangle& rect) {
    cout << rect.length << " x " << rect.width << endl;
    return;
}
