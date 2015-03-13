#include <iostream>
using namespace std;

class Rectangle {
public:
    // Default constructor
    Rectangle();
    // Overloaded constructor
    Rectangle(int newLength, int newWidth);
    // Read data from the keyboard
    void read();
    // Print data to the console
    void print() const;
    // Accessor functions to use private variables
    int getLength();
    int getWidth();
    // Mutator functions to modify private variables
    void setLength(int newLength);
    void setWidth(int newWidth);
    void setSize(int newLength, int newWidth);
private:
    int length;
    int width;
};


int main() {
    Rectangle toast;
    toast.read();
    toast.print();

    Rectangle pillow(10, 20);
    pillow.print();

    cout << "\nTesting get and set functions\n";
    Rectangle paper(11, 8);
    cout << "The length of paper is: " << paper.getLength() << endl;
    paper.setLength(17);
    cout << "Paper is now: ";
    paper.print();

    cout << "Testing shadowing\n";
    Rectangle shadow;
    shadow.setSize(7, 14);
    shadow.print();

    return 0;
}

Rectangle::Rectangle() {
    length = 0;
    width = 0;
}

Rectangle::Rectangle(int newLength, int newWidth) {
    length = newLength;
    width = newWidth;
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

int Rectangle::getLength() {
    return length;
}

int Rectangle::getWidth() {
    return width;
}

void Rectangle::setLength(int newLength) {
    length = newLength;
}

void Rectangle::setWidth(int newWidth) {
    width = newWidth;
}

void Rectangle::setSize(int newLength, int newWidth) {
    length = newLength;
    width = newWidth;
}
