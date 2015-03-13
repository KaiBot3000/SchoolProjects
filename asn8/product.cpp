/**
    CS-11 Asn 8
    product.cpp
    Purpose:
    @author riselikethemoon
    @version 1.0 04/24/13
*/

#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

class Product {
public:
    /**
        Constructor with no parameters, initializes variable to default values.
    */
    Product();
    /**
        Constructor, initializes variable to default values.

        @param initialName the default name
        @param initialPrice the default price
        @param initialQuantity the default quantity
    */
    Product(string initialName, double initialPrice, int initialQuantity);
    /**
        Accesses private variable.
        @return name
    */
    string getName() const;
    /**
        Accesses private variable.
        @return price
    */
    double getPrice() const;
    /**
        Accesses private variable.
        @return quantity
    */
    int getQuantity() const;
    /**
        Mutates private variable name.
        @param newName the new value for name
    */
    void setName(string newName);
    /**
        Mutates private variable price.
        @param newPrice the new value for price
    */
    void setPrice(double newPrice);
    /**
        Mutates private variable quantity.
        @param newQuantity the new value for quantity
    */
    void setQuantity(int newQuantity);
    /**
        Calculates value of inventory by multiplying price and quantity.
        @return value
    */
    double getValue() const;
    /**
        Displays data for a given product.
    */
    void print() const;
    /**
        Creates string with data for a given product.
        @return a string listing name, quantity, price, and value.
    */
    string toString() const;

private:
    string name;
    double price;
    int quantity;

};

int main() {
    const int WIDE_DISPLAY = 16; // Display constants
    const int NARROW_DISPLAY = 8;

    const string APPLE_NAME = "Apple";
    const double APPLE_PRICE= .75;
    const int APPLE_QUANTITY = 100;
    Product apple(APPLE_NAME, APPLE_PRICE, APPLE_QUANTITY);

    const string CUCUMBER_NAME = "Cucumber";
    const double CUCUMBER_PRICE= 1.30;
    const int CUCUMBER_QUANTITY = 40;
    Product cucumber(CUCUMBER_NAME, CUCUMBER_PRICE, CUCUMBER_QUANTITY);

    const string AVOCADO_NAME = "Avocado";
    const double AVOCADO_PRICE= 2.25;
    const int AVOCADO_QUANTITY = 50;
    Product avocado;
        avocado.setName(AVOCADO_NAME);
        avocado.setPrice(AVOCADO_PRICE);
        avocado.setQuantity(AVOCADO_QUANTITY);
    cout << "My products:" << endl;
    cout << setw(WIDE_DISPLAY) << left << "Name" << setw(NARROW_DISPLAY)
        << right << "Price" << setw(NARROW_DISPLAY) << right << "Qty"
        << setw(NARROW_DISPLAY) << right <<"Value" << endl;
    apple.print();
    cucumber.print();
    avocado.print();

    cout << "\n\nExtra Credit toString function output:\n" ;
    cout << apple.toString() << endl;
}

    // Constructors
Product::Product() {
    name = "none";
    price = 0.0;
    quantity = 0;
}

Product::Product(string initialName, double initialPrice, int initialQuantity) {
    name = initialName;
    price = initialPrice;
    quantity = initialQuantity;
}

    // Accessor functions
string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

int Product::getQuantity() const {
    return quantity;
}

    // Mutator functions
void Product::setName(string newName) {
    name = newName;
}

void Product::setPrice(double newPrice) {
    price = newPrice;
}

void Product::setQuantity(int newQuantity) {
    quantity = newQuantity;
}

    // Value function
double Product::getValue() const {
    double value = price * quantity;
    return value;
}

    // Print function
void Product::print() const {
    cout << setw(16) << left << name;
    cout << setw(8) << right << price;
    cout << setw(8) << right << quantity;
    cout << setw(8) << right << getValue() << endl;
}

    // Extra Credit String Function
string Product::toString() const {
    string stringPrice;
    ostringstream convertPrice;
    convertPrice << price;
    stringPrice = convertPrice.str();

    string stringQuantity;
    ostringstream convertQuantity;
    convertQuantity << quantity;
    stringQuantity = convertQuantity.str();

    double value = getValue();
    string stringValue;
    ostringstream convertValue;
    convertValue << value;
    stringValue = convertValue.str();

    string info = name + "          " + stringPrice + "   " + stringQuantity
        + "   " + stringValue;
    return info;
}
