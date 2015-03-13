/**
    CS-11 Asn 9
    store.cpp
    Purpose: Keeps track of inventory in store vector
    @author riselikethemoon
    @version 1.0 05/01/13
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
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
    /**
        Reads data from cin and loads into product.
    */
    void read();

private:
    string name;
    double price;
    int quantity;

};

/**
    Displays a menu of functions
*/
int menu();

/**
    Reports Inventory
    @param vector to be reported
*/
void inventoryReport(vector<Product>& store);

/**
    Reports Inventory
    @param vector to be added
*/
void addProduct(vector<Product>& store);

/**
    Reports Inventory
    @param vector to be deleted
*/
void deleteProduct(vector<Product>& store);

/**
    Reports Inventory
    @param vector to be sold
*/
void sellProduct(vector<Product>& store);

/**
    Reports Inventory
    @param vector to be restocked
*/
void restockProduct(vector<Product>& store);

/**
    Updates price of product **Extra Credit**
    @param vecotr containing price to be updated
*/
void updatePrice(vector<Product>& store);

int main() {
    // Display constants
    const int WIDE_DISPLAY = 16;
    const int NARROW_DISPLAY = 8;

    const string APPLE_NAME = "Apple";
    const double APPLE_PRICE= .75;
    const int APPLE_QUANTITY = 100;

    const string AVOCADO_NAME = "Avocado";
    const double AVOCADO_PRICE= 2.25;
    const int AVOCADO_QUANTITY = 50;

    const string CUCUMBER_NAME = "Cucumber";
    const double CUCUMBER_PRICE= 1.30;
    const int CUCUMBER_QUANTITY = 40;

    const int SIZE = 3; //Initial size of <vector>store


    Product apple(APPLE_NAME, APPLE_PRICE, APPLE_QUANTITY);

    Product cucumber(CUCUMBER_NAME, CUCUMBER_PRICE, CUCUMBER_QUANTITY);

    Product avocado;
        avocado.setName(AVOCADO_NAME);
        avocado.setPrice(AVOCADO_PRICE);
        avocado.setQuantity(AVOCADO_QUANTITY);


        //Leftover product class code
    cout << "My products:" << endl;
    cout << setw(WIDE_DISPLAY) << left << "Name" << setw(NARROW_DISPLAY)
        << right << "Price" << setw(NARROW_DISPLAY)
        << right << "Qty" << setw(NARROW_DISPLAY)
        << right << "Value" << endl;
    apple.print();
    cucumber.print();
    avocado.print();

    /** Extra Credit from Asn #9
    cout << "\n\nExtra Credit toString function output:\n" ;
    cout << apple.toString() << endl;
    */

    // store code
    vector<Product> store(SIZE);
    store[0] = apple;
    store[1] = avocado;
    store[2] = cucumber;

    int choice = menu();
    while (choice != 0) {
         if (choice == 1) {
            inventoryReport(store);
            cout << endl;
            choice = menu();
        } else if (choice == 2) {
            addProduct(store);
            choice = menu();
        } else if (choice == 3) {
            cout << endl;
            deleteProduct(store);
            choice = menu();
        } else if (choice == 4) {
            sellProduct(store);
            cout << endl;
            choice = menu();
        } else if (choice == 5) {
            restockProduct(store);
            cout << endl;
            choice = menu();
        } else if (choice == 6) {
            updatePrice(store);
            cout << endl;
            choice = menu();
        } else {
            cout << endl << "Invalid choice!" << endl;
            choice = menu();
        }
    }


return 0;
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
    cout << setw(8) << right << fixed << setprecision(2) << price;
    cout << setw(8) << right << quantity;
    cout << setw(8) << right << fixed << setprecision(2) << getValue() << endl;
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

    // Read function
void Product::read() {
    cout << "Enter the name of the product: ";
    cin >> ws;
    getline(cin, name);
    cout << "Enter the price for a " << name << ": ";
    cin >> price;
    cout << "Enter the initial inventory: ";
    cin >> quantity;
    cout << endl;
    //cout << name << quantity << quantity;
}

    //Menu function
int menu() {
    int choice;
    cout << "Please choose one of the following operations:\n";
    cout << "0. Exit program" << endl;
    cout << "1. Report inventory" << endl;
    cout << "2. Add a new product" << endl;
    cout << "3. Delete a product" << endl;
    cout << "4. Sell a product" << endl;
    cout << "5. Restock a product" << endl;
    cout << "6. Change a product price" << endl;
    cout << "Choice (0-6): ";
    cin >> choice;
    return choice;
}

    // Reports Inventory
void inventoryReport(vector<Product>& store) {
    const int WIDE_DISPLAY = 16;
    const int NARROW_DISPLAY = 8;
    const int TINY_DISPLAY = 3;
    cout << endl;
    cout << setw(TINY_DISPLAY) << " # ";
    cout << setw(WIDE_DISPLAY) << left << "Name";
    cout << setw(NARROW_DISPLAY) << right << "Price";
    cout << setw(NARROW_DISPLAY) << right << "Qty";
    cout << setw(NARROW_DISPLAY) << right << "Value" << endl;
    for (unsigned num = 0; num < store.size(); num++) {
        cout << " " << (num + 1) << " ";
        store[num].print(); //prints product [num]
    }
}

    // Adds Product
void addProduct(vector<Product>& store) {
    cout << "\nAdding a new product:\n";
    Product prod;
    prod.read();
    store.push_back(prod);
}

    // Deletes a product
void deleteProduct(vector<Product>& store) {
    int choice;
    int lastPos = store.size() - 1;
    cout << "Deleting a product:";
    inventoryReport(store);
    cout << "Which product: ";
    cin >> choice;
    store[choice - 1] = store[lastPos];
    store.pop_back();
    cout << endl;
}
    // Decrements product qty
void sellProduct(vector<Product>& store) {
    int choice;
    cout << endl << "Selling a product: ";
    inventoryReport(store);
    cout << "Which product: ";
    cin >> choice;
    choice--;
    Product temp = store[choice];
    int qty = temp.getQuantity();
    qty = (qty - 1);
    temp.setQuantity(qty);
    store[choice] = temp;
}

    // Restocks product
void restockProduct(vector<Product>& store) {
    int choice, items;
    cout << endl << "Restocking a product: ";
    inventoryReport(store);
    cout << "Which product: ";
    cin >> choice;
    choice--;
    cout << "Number of items to add: ";
    cin >> items;
    /** (class notes) instead of temp, could have done...
        int quantity = store[choice].getQuantity();
        store[choice].setQuantity(qty + items);
        Then skip the rest of this function...*/
    Product temp = store[choice];
    int qty = temp.getQuantity();
    qty = (qty + items);
    temp.setQuantity(qty);
    store[choice] = temp;
}

    // Changes product price
void updatePrice(vector<Product>& store) {
    int choice;
    double price;
    cout << endl << "Changing a product price: ";
    inventoryReport(store);
    cout << "Enter the number of the product to change: ";
    cin >> choice;
    choice--;
    cout << "Enter the new price: ";
    cin >> price;
    Product temp = store[choice];
    double newCost = temp.getPrice();
    newCost = price;
    temp.setPrice(newCost);
    store[choice] = temp;
}




