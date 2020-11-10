// Program name: Lab2a
//
// Description: Program readsin user input of number of items, then 
//          name, quantity, price until list of items are full.
//
// What's on your mind about this lab? 
//          I learned how to use structures within functions using pointers.
//
// Author: Allester Ramayrat
//
// Date: 10/24/2020
//
// IDE Used: C++ Shell

#include <iostream>
#include <iomanip>

using namespace std;

// Define a data structure named Sale.
// The structure has the following fields:
struct Sale {
    string itemName;  // name of sale item
    int quantity;     // quantity of item
    double unitPrice; // unit price of item
};

Sale *getUserInput(int *items);
double getItemTotal(const Sale *sale);
double getTotal(const Sale *salePtr, int items);
void printData(const Sale *salePtr, int items);

int main() {
    int items {0};
    Sale* users = getUserInput(&items);
    printData(users, items);
    delete [] users;
    
    return 0;
}

//**********************************************************************
//* getUserInput - This function gets a list of Sale item from the user.
//*   This functions dynamically allocates an array and returns a pointer
//*   to the allocated array. The caller is responsible for deleting
//*   the allocated array.
//*
//* Parameters:
//*   items - pointer to the callers variable for item counts.
//*
//* Return:
//*   The pointer to the first Sale item in the allocated array of Sale
//*   items.
//*
//**********************************************************************
Sale *getUserInput(int *items) {
    int userItems {0};
    cin >> userItems;

    //cout << "userItems " << userItems << endl;
    Sale *ptr = new Sale[userItems] {};
    
    Sale *tptr = ptr;
    while (tptr < ptr + userItems) {
        // This is necessary because the previous operation is a >>
        // that left the newline in the buffer.
        cin.ignore();
        getline(cin, tptr->itemName);
        cin >> tptr->quantity;
        cin >> tptr->unitPrice;
        ++tptr;
    }
    *items = userItems;
    return ptr;
}

//**********************************************************************
//* getItemTotal - This function returns the total price of one
//*     sale item.
//*
//* Parameters:
//*   salePtr - pointer to one sale item
//*
//* Return:
//*   The total price of the item.
//*
//**********************************************************************
double getItemTotal(const Sale *salePtr) {
    
    //multiplies the unitPrice and quantity of salePtr and returns it
    return (salePtr->unitPrice * salePtr->quantity);
    
}

//**********************************************************************
//* getTotal - This function returns the total price of the sale items.
//*
//* Parameters:
//*   salePtr - pointer to the first sale item
//*   items - number of sale items
//*
//* Return:
//*   The total price of the items.
//*
//**********************************************************************
double getTotal(const Sale *salePtr, int items) {
    double total = 0.0;
    //adds to total after multiplying quantity and unitPrice of salePtr
    for (int index = 0; index < items; index++) {
        total += salePtr[index].quantity * salePtr[index].unitPrice;
    }
    return total;
}

//**********************************************************************
//* printData - This function prints a report of the sale items.
//*
//* Parameters:
//*   salePtr - pointer to the first sale item
//*   items - number of sale items
//*
//* Return:
//*   void
//*
//**********************************************************************
void printData(const Sale *salePtr, int items) {
    
    //Rounds all floats to the hundreths place
    cout << fixed << setprecision(2);
    
    //Labels
    cout << endl << "Sales" << endl;
    cout << "Item               Qty     Unit     Amt" << endl;
    cout << "========================================" << endl;
    
    //prints name, qty, unit, amt on one line per loop
    for (int index = 0; index < items; index++) {
        //prints name and right aligns for Qty
        cout << salePtr[index].itemName << setw(22-salePtr[index].itemName.length());
        //prints quantity and right aligns for unit
        cout << salePtr[index].quantity << setw(9);
        //prints unitPrice and right aligns for Amt
        cout << salePtr[index].unitPrice << setw(9);
        //prints Amt
        cout << getItemTotal(salePtr + index) << endl;
    }
    
    //Prints total bill of all items
    cout << endl << "Total" << setw(35) << getTotal(salePtr, items) << endl;
   
}