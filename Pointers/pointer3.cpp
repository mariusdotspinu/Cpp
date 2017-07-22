//
// Created by Marius on 7/15/2017.
//
#include <iostream>

using namespace std;

int main(){

    int *p, *q, *t, *d, a = 20, b =30, c =50;

    cout << &p << "\n";
    cout << &q << "\n";
    cout << &t << "\n";
    cout << &d << "\n";
    cout << &a << "\n";
    cout << &b << "\n";
    cout << &c << "\n";

    p = &a;
    q = &b;

    t = &c;
    * p++ = * q++;
    *t = 4;

    ++d; //undefined behaviour;

    cout << p << " " << *q << " " << *t << " " << &d;
}