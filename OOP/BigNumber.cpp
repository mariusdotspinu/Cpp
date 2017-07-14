//
// Created by Marius on 7/3/2017.
//

#include <cstring>
#include <string>
#include <iostream>
#include <stdlib.h>
#include "BigNumber.h"

using namespace std;

bool containsNonNumeric(const char *number) {
    for (int i = 0; i < strlen(number); i++) {
        if (!isdigit(number[i])) {
            return true;
        }
    }

    return false;
}

BigNumber::BigNumber() {
    Number[0] = {0};
    CharactersCount = 0;
}

BigNumber::BigNumber(int value) {
    CharactersCount = 0;

    char stringValue[256];
    itoa(value, stringValue, 10);

    for (int i = 0; i < strlen(stringValue); i++) {
        Number[i] = stringValue[i];
        CharactersCount++;
    }

    Number[CharactersCount] = '\0';
}

BigNumber::BigNumber(const char *number) {
    CharactersCount = 0;

    for (int i = 0; i < strlen(number); i++) {
        Number[i] = number[i];
        CharactersCount++;
    }

    Number[CharactersCount] = '\0';
}

BigNumber::BigNumber(const BigNumber &number) {
    this->CharactersCount = number.CharactersCount;
    strcpy(this->Number, number.Number);

    this->Number[this->CharactersCount] = '\0';
}

bool BigNumber::Set(int value) {
    if (value < 0) {
        return false;
    }
    this->CharactersCount = 0;

    char stringValue[256];
    itoa(value, stringValue, 10);

    for (int i = 0; i < strlen(stringValue); i++) {
        this->Number[i] = stringValue[i];
        this->CharactersCount++;
    }

    this->Number[this->CharactersCount] = '\0';

    return true;
}

bool BigNumber::Set(const char *number) {
    if (containsNonNumeric(number)) {
        return false;
    }
    this->CharactersCount = 0;

    for (int i = 0; i < strlen(number); i++) {
        this->Number[i] = number[i];
        this->CharactersCount++;
    }

    this->Number[this->CharactersCount] = '\0';
    return true;
}

BigNumber BigNumber::operator+(const BigNumber &number) {
    char result[256];

    for (int i = 0; i < 256; i++) {
        result[i] = -1;
    }

    result[255] = '\0';
    int carry = 0, position = 254, sum = 0, firstNumber = 0, secondNumber = 0;
    bool done = false;

    for (int i = this->CharactersCount - 1; i >= 0; i--) {
        if (!done) {
            for (int j = number.CharactersCount - 1; j >= 0; j--) {
                firstNumber = this->Number[i] - '0';
                secondNumber = number.Number[j] - '0';

                if (firstNumber + secondNumber > 9) {

                    sum += (firstNumber + secondNumber) % 10 + carry;
                    carry = (firstNumber + secondNumber) / 10;
                } else {
                    sum += firstNumber + secondNumber + carry;
                    carry = 0;
                }

                result[position] = sum + '0';

                i--;
                position--;
                sum = 0;
            }
        }
        done = true;
        if (carry != 0) {

            if (this->Number[i] - '0' + carry > 9) {
                result[position] = (((this->Number[i] - '0') + carry) % 10) + '0';
                carry = ((this->Number[i] - '0' + carry) / 10) + '0';
            } else {
                result[position] = ((this->Number[i] - '0') + carry) + '0';
                carry = 0;
            }
        } else {
            result[position] = this->Number[i];
        }

        position--;

    }

    char finalResult[256], currentNumber[2];
    strcpy(finalResult, "");

    for (int i = 0; i < strlen(result); i++) {
        if (result[i] != -1 and isdigit(result[i])) {
            currentNumber[0] = result[i];
            currentNumber[1] = '\0';
            strcat(finalResult, currentNumber);
        }
    }

    return BigNumber((const char *) finalResult);
}

bool operator==(const BigNumber &n1, const BigNumber &n2) {
    if (strlen(n1.Number) > strlen(n2.Number) || strlen(n1.Number) < strlen(n2.Number)) {
        return false;
    } else {
        for (int i = 0; i < n1.CharactersCount; i++) {
            if (n1.Number[i] != n2.Number[i]) {
                return false;
            }
        }
    }

    return true;
}

bool operator!=(const BigNumber &n1, const BigNumber &n2) {
    if (strlen(n1.Number) > strlen(n2.Number) || strlen(n1.Number) < strlen(n2.Number)) {
        return true;
    } else {
        for (int i = 0; i < n1.CharactersCount; i++) {
            if (n1.Number[i] != n2.Number[i]) {
                return true;
            }
        }
    }
    return false;
}

bool operator<(const BigNumber &n1, const BigNumber &n2) {
    short int same = 0;
    if (strlen(n1.Number) > strlen(n2.Number)) {
        return false;
    } else if (strlen(n1.Number) == strlen(n2.Number)) {
        for (int i = 0; i < n1.CharactersCount; i++) {
            if (n1.Number[i] > n2.Number[i]) {
                return false;
            }
            if (n1.Number[i] == n2.Number[i]) {
                same++;
            }
        }

        if (same == strlen(n1.Number)) {
            return false;
        }
    }

    return true;
}

bool operator>(const BigNumber &n1, const BigNumber &n2) {
    short int same = 0;
    if (strlen(n1.Number) < strlen(n2.Number)) {
        return false;
    } else if (strlen(n1.Number) == strlen(n2.Number)) {
        for (int i = 0; i < n1.CharactersCount; i++) {
            if (n1.Number[i] < n2.Number[i]) {
                return false;
            }
            if (n1.Number[i] == n2.Number[i]) {
                same++;
            }
        }

        if (same == strlen(n1.Number)) {
            return false;
        }
    }

    return true;
}

bool operator<= (const BigNumber &n1, const BigNumber &n2){
    short int same = 0;
    if (strlen(n1.Number) > strlen(n2.Number)) {
        return false;
    } else if (strlen(n1.Number) == strlen(n2.Number)) {
        for (int i = 0; i < n1.CharactersCount; i++) {
            if (n1.Number[i] > n2.Number[i]) {
                return false;
            }
            if (n1.Number[i] == n2.Number[i]) {
                same++;
            }
        }

        if (same == strlen(n1.Number)) {
            return true;
        }
    }

    return true;
}

bool operator>= (const BigNumber &n1, const BigNumber &n2){
    short int same = 0;
    if (strlen(n1.Number) < strlen(n2.Number)) {
        return false;
    } else if (strlen(n1.Number) == strlen(n2.Number)) {
        for (int i = 0; i < n1.CharactersCount; i++) {
            if (n1.Number[i] < n2.Number[i]) {
                return false;
            }
            if (n1.Number[i] == n2.Number[i]) {
                same++;
            }
        }

        if (same == strlen(n1.Number)) {
            return true;
        }
    }

    return true;
}

BigNumber::operator int() {
    return BigNumber(atoi((const char *) this->Number));
}

char BigNumber::operator[](int index) {
    if (index < 0 || index >= CharactersCount) {
        return '\0';
    }

    return this->Number[index];
}

BigNumber BigNumber::operator()(int start, int end) {
    if (start < 0 || end >= this->CharactersCount || start >= this->CharactersCount || end < 0) {
        return BigNumber();
    }

    char subNumber[256], current[2];
    strcpy(subNumber, "");

    for (int i = start; i <= end; i++) {
        current[0] = this->Number[i];
        current[1] = '\0';
        strcat(subNumber, current);
    }

    return BigNumber((const char *) subNumber);
}

int BigNumber::GetCount() {
    return this->CharactersCount;
}

char *BigNumber::GetNumber() {
    return this->Number;
}

void BigNumber::show() {
    for (int i = 0; i < this->CharactersCount; i++) {
        cout << this->Number[i] << " ";
    }
    cout << endl;
}

int main() {
    //tests

    BigNumber simpleNumber = BigNumber();
    simpleNumber.show();

    BigNumber valueNumber = BigNumber(1024);
    valueNumber.show();

    BigNumber charNumber = BigNumber("12443654323");
    charNumber.show();

    BigNumber bigNumber = BigNumber(valueNumber);
    bigNumber.show();

    charNumber.Set("1243432324");
    charNumber.show();

    bigNumber.Set("1253432324");
    bigNumber.show();

    cout << bigNumber[2] << endl;
    bigNumber(0, 5).show();

    cout << bigNumber.GetNumber() << endl;
    cout << bigNumber.GetCount() << endl;

    (bigNumber + bigNumber).show();

    cout << (bigNumber == bigNumber) << endl;
    cout << (bigNumber == charNumber) << endl;
    cout << (bigNumber != charNumber) << endl;
    cout << (bigNumber != bigNumber) << endl;

    cout << (bigNumber < charNumber) << endl;

    cout << (bigNumber > charNumber) << endl;
    cout << (bigNumber > bigNumber) << endl;

    cout << (bigNumber >= bigNumber) << endl;
    cout << (bigNumber <= charNumber) << endl;
    cout << (charNumber <= bigNumber) << endl;
}