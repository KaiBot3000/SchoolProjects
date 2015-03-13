#include <iostream>
using namespace std;

class Rectangle {
public:
    // Default constructor
    Rectangle();
    // Read data from the keyboard
    void read();
    // Print data to the console
    void print() const;
private:
    int length;
    int width;
};


int main() {
    Rectangle toast;
    toast.read();
    toast.print();

    return 0;
}

Rectangle::Rectangle() {
    length = 0;
    width = 0;
}

void Rectangle::read() {
    cout << "Enter the rectangle length: ";
    cin >> length;
    cout << "Enter the rectangle width: ";
    cin >> width;
}

void Rectangle::print() const {
    cout << length << " x " << width << endl;
    return;
}
