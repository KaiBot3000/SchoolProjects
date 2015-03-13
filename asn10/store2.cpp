/**
    CS-11 Asn 10
    store2.cpp
    Purpose: Keeps track of inventory in store vector
    @author riselikethemoon
    @version 1.0 05/08/13
*/

#include <iostream>
#include <fstream>
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
    /**
        Loads information about this Product from the file stream.

        @param fin An input stream connected to the files with the
        data to load.
    */
    void read(ifstream& fin);

    /**
        Writes information about this Product to the file stream.

        @param fout An output stream connected to the file in
        which to save the data.
    */
    void write(ofstream& fout) const;

    /**
        EXTRA CREDIT: Prints report to the file stream.

        @param fout An output stream connected to the file in
        which to save the data.
    */
    void print(ofstream& fout) const;

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
    @param vector containing price to be updated
*/
void updatePrice(vector<Product>& store);

/**
    Loads the Product data from the specified file name and
    returns the data in a vector of Product objects.

    @param store The list of products to display.
    @param fileName The name of the file from which to read.
*/
void loadData(vector<Product>& store, string fileName);

/**
    Writes store data to an output file.

    @param store The vector of Product objects.
    @param fileName The name of the file to which to write.
*/
void saveData(const vector<Product>& store, string fileName);

/**
    Writes a report to a file named report.txt.

    @param store The vector of Product objects.
    @param fileName The name of the file to which to write.
*/
void writeReport(vector<Product> store, string fileName);


int main() {
    vector<Product> store(0);

    loadData(store, "products.txt");

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
        } else if (choice == 99) {
            writeReport(store, "report.txt");
            cout << endl;
            choice = menu();
        } else {
            cout << endl << "Invalid choice!" << endl;
            choice = menu();
        }
    }
    saveData(store, "store.txt");
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
    const int WIDE_DISPLAY = 16;
    const int NARROW_DISPLAY = 8;

    cout << setw(WIDE_DISPLAY) << left << name;
    cout << setw(NARROW_DISPLAY) << right << fixed << setprecision(2) << price;
    cout << setw(NARROW_DISPLAY) << right << quantity;
    cout << setw(NARROW_DISPLAY) << right << fixed << setprecision(2)
         << getValue() << endl;
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
}
    // Reads data from input stream
void Product::read(ifstream& fin) {
    fin >> ws;
    getline(fin, name);
    fin >> price;
    fin >> quantity;
}

    // Writes data to output stream
void Product::write(ofstream& fout) const {
    fout << name << endl;
    fout << fixed << setprecision(2) << price << endl;
    fout << quantity << endl;
}

    //Menu function
int menu() {
    int choice;
    cout << "Please choose one of the following operations:\n";
    cout << "0.  Exit program" << endl;
    cout << "1.  Report inventory" << endl;
    cout << "2.  Add a new product" << endl;
    cout << "3.  Delete a product" << endl;
    cout << "4.  Sell a product" << endl;
    cout << "5.  Restock a product" << endl;
    cout << "6.  Change a product price" << endl;
    cout << "99. Print Report" << endl;
    cout << "Choice (0-6, 99): ";
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
    // Loads product data from file
void loadData(vector<Product>& store, string fileName) {
        ifstream fin(fileName.c_str());
        if (fin.fail()) {
            cout << "Input file failed to open.\n";
            exit(-1);
        }
        while (fin.good()) {
            Product temp;
            temp.read(fin);
            if (fin.good()) {
                store.push_back(temp);
            }
        }
        fin.close();
}
    // Writes store data to an output file
void saveData(const vector<Product>& store, string fileName) {
    ofstream fout(fileName.c_str());
    if (fout.fail()) {
        cout << "Output file failed to open.\n";
        exit(-1);
    }

    for (unsigned i = 0; i < store.size() ; i++) {
        store[i].write(fout);
    }
    fout.close();
}
    // Extra Credit: Writes report to file
void writeReport(vector<Product> store, string fileName) {
    const int WIDE_DISPLAY = 16;
    const int NARROW_DISPLAY = 8;
    const int TINY_DISPLAY = 3;
    double value = 0;

    ofstream fout(fileName.c_str());
    if (fout.fail()) {
        cout << "Output failed.\n";
        exit(-1);
    }
    fout << "Report for my store:\n";
    fout << setw(TINY_DISPLAY) << " # ";
    fout << setw(WIDE_DISPLAY) << left << "Name";
    fout << setw(NARROW_DISPLAY) << right << "Price";
    fout << setw(NARROW_DISPLAY) << right << "Qty";
    fout << setw(NARROW_DISPLAY) << right << "Value" << endl;
    for (unsigned num = 0; num < store.size() ; num++) {
        fout << " " << (num + 1) << " ";
        store[num].print(fout);
        value += store[num].getValue();

    }
    fout << endl << "Total inventory value: "
                 << fixed << setprecision(2) << value;
    fout.close();

}

    // Extra Credit Print member function
void Product::print(ofstream& fout) const {
    const int WIDE_DISPLAY = 16;
    const int NARROW_DISPLAY = 8;

    fout << setw(WIDE_DISPLAY) << left << name;
    fout << setw(NARROW_DISPLAY) << right << fixed << setprecision(2) << price;
    fout << setw(NARROW_DISPLAY) << right << quantity;
    fout << setw(NARROW_DISPLAY) << right << fixed << setprecision(2)
         << getValue() << endl;

}


