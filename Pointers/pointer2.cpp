//
// Created by Marius on 7/15/2017.
//

/*Write a C++ program to find the max of an integral data set.
 * The program will ask the user to input the number of data values in the set and each value.
 * The program prints on screen a pointer that points to the max value.*/

#include <iostream>
using namespace std;

int main(){
    int n;

    cout << "Enter size of dataset : \n";
    cin >> n;

    int v[n];
    int *max;

    for(int i = 0 ; i < n; i++){

        cout << "Enter number " << i << "\n";
        cin >> v[i];
    }

    max = v;
    for(int i = 1 ; i < n; i++){
        if(*max < v[i]){
            *max = v[i];
        }
    }

    cout << *max;


}