//
// Created by Marius on 7/12/2017.
//

//sorting roman numbers

#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include<algorithm>

using namespace std;



bool IsSubtractionAvailable(char n1, char n2) {

    if (n1 == 'I' && n2 == 'V' ||
        n1 == 'I' && n2 == 'X' ||
        n1 == 'X' && n2 == 'L' ||
        n1 == 'X' && n2 == 'C' ||
        n1 == 'C' && n2 == 'D' ||
        n1 == 'C' && n2 == 'M') {

        return true;
    }

    return false;
}

int GetArabicValue(char romanLetter) {

    switch (romanLetter) { //ascii code
        case 67:
            return 100;
        case 68:
            return 500;
        case 73:
            return 1;
        case 76:
            return 50;
        case 77:
            return 1000;
        case 86:
            return 5;
        case 88:
            return 10;
        default:
            return 0;
    }
}

int RomanToArabic(string number) {

    if (number.length() == 0) {
        return -1;
    }

    if (number.length() == 1) {
        return GetArabicValue(number[0]);
    } else if (number.length() == 2) {
        if (GetArabicValue(number[0]) >= GetArabicValue(number[1])) {
            return GetArabicValue(number[0]) + GetArabicValue(number[1]);
        } else if (IsSubtractionAvailable(number[0], number[1])) {
            return GetArabicValue(number[1]) - GetArabicValue(number[0]);
        } else {
            return -1;
        }
    } else {

        int arabicNumber = 0;

        for (int i = 0; i < number.length(); i++) {
            if (GetArabicValue(number[i]) < GetArabicValue(number[i + 1]) &&
                IsSubtractionAvailable(number[i], number[i + 1])) {
                arabicNumber += GetArabicValue(number[i + 1]) - GetArabicValue(number[i]);
                i++;
            } else if (GetArabicValue(number[i]) > GetArabicValue(number[i + 1]) &&
                       GetArabicValue(number[i + 1] > GetArabicValue(number[i + 2]))) {

                arabicNumber += GetArabicValue(number[i]) + GetArabicValue(number[i]);
                i++;
            }
            else{
                arabicNumber += GetArabicValue(number[i]);
            }

        }
        return arabicNumber;
    }
}

vector<string> GetNumbers(const char* fileName){
    FILE* fp = fopen(fileName, "r");
    char line[1000];
    vector<string> numbers;
    if(fp != NULL){
        while(fgets(line, sizeof(line), fp) != NULL){
            numbers.push_back(line);
        }

        cout <<"File end reached !";
    }
    else{
        perror("Failed reading from file!");
    }

    return numbers;
}

struct RomanComparator{

    bool operator()(string n1, string n2){
        return RomanToArabic(n1) < RomanToArabic(n2);
    }
} roman;

int main() {
    vector<string>numbers = GetNumbers("C:\\Users\\Marius\\Desktop\\CTraining\\OOP\\stl3.txt");

    sort(numbers.begin(), numbers.end(), roman);

    cout << endl;
    for(unsigned int i = 0 ; i < numbers.size(); i++){
        cout << numbers.at(i) <<"\t" << RomanToArabic(numbers.at(i)) << "\n";
    }
}
