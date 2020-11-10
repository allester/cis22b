// Program name: Lab1c
//
// Description: This program will read user input of a list's size then
//              then numbers in that list. After, it will display the
//              list as well as the total and average of that list.
//
// What's on your mind about this lab? 
//              Some new concepts that I learned from this lab was using
//              pointers as a function parameter as well as how to
//              use output parameters.
//
// Author: Allester Ramayrat
//
// Date: 10/08/20
//
// IDE Used: Visual Studio Code

#include <iostream>
#include <iomanip>

using namespace std;

void printReport(const double *, int);
void totalAndAverage(const double *, int, double *, double *);

int main() {
    // Get count and numbers from user
    int count;
    cin >> count;
    double *ptr = new double [count];
    for (int index = 0; index < count; ++index) {
        cin >> ptr[index];
    }
    printReport(ptr, count);
    delete [] ptr;
    return 0;
}

//**********************************************************************
//* printReport: This funtion prints the given list of numbers
//*     and statistics.
//*
//* Parameters
//*   list - pointer to the first element in the list
//*   size - the number of elements in the list
//*
//**********************************************************************
void printReport(const double *list, int size) {

    cout << fixed << setprecision(2);
    cout << "#              Amount" << endl;
    cout << "----------------------" << endl;
    for (int i = 0; i < size; i++) {
        cout << i << setw(21) << list[i]<< endl;
    }
    
    double total = 0;
    double avg = 0;
    totalAndAverage(list, size, &total, &avg);
    cout << "Total" << setw(17) << total << endl;
    cout << "Average" << setw(15) << avg << endl;

}

//**********************************************************************
//* totalAndAverage: This function calculates the total and average of
//*     a given list of real numbers. The results are returned through
//*     output parameters.
//*
//* Parameters
//*   list - pointer to the first element in the list
//*   size - the number of elements in the list
//*   totPtr - (output) pointer to the caller's total variable
//*   avePtr - (output) pointer to the caller's average variable
//*
//**********************************************************************
void totalAndAverage(const double *list, int size,
                     double *totPtr, double *avePtr) {
    
    for (int i = 0; i < size; i++) {
        *totPtr += list[i];
    }
    *avePtr = *totPtr / size;
}
