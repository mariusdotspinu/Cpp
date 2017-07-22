//
// Created by Marius on 7/15/2017.
//

/*Write a program that asks the user to enter integers as inputs to be stored in the
 * variables 'a' and 'b' respectively. There are also two integer pointers named
 * ptrA and ptrB. Assign the values of 'a' and 'b' to ptrA and ptrB respectively,
 * and display them.*/

#include <iostream>

using namespace std;

int main(){

    int a, b, *ptrA, *ptrB;

    cout << "Enter integer 1 : ";
    cin >> a;

    cout << "\nEnter integer 2: ";
    cin >> b;

    ptrA = &a;
    ptrB = &b;

    cout << "\n" << *ptrA << " " << *ptrB;
}