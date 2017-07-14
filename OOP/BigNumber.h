//
// Created by Marius on 7/3/2017.
//

#ifndef CTRAINING_BIGNUMBER_H
#define CTRAINING_BIGNUMBER_H


class BigNumber {

private:
    char Number[256];
    int CharactersCount;

public:
    BigNumber();
    BigNumber(int value);
    BigNumber(const char* number);
    BigNumber(const BigNumber& number);

    bool Set(int value);
    bool Set(const char* number);

    BigNumber operator+ (const BigNumber & number);
//    BigNumber operator* (const BigNumber & number);
//    BigNumber operator- (const BigNumber & number);
//    BigNumber operator/ (const BigNumber & number);

    friend bool operator == (const BigNumber & n1, const BigNumber & n2);
    friend bool operator != (const BigNumber & n1, const BigNumber & n2);
    friend bool operator < (const BigNumber & n1, const BigNumber & n2);
    friend bool operator > (const BigNumber & n1, const BigNumber & n2);
    friend bool operator >= (const BigNumber & n1, const BigNumber & n2);
    friend bool operator <= (const BigNumber & n1, const BigNumber & n2);

    operator int();
    char operator[] (int index); // returns the character at index or \0 otherwise
    BigNumber operator() (int start, int end); //returns the number from start until end or "0" if start / end not valid

    char *GetNumber();
    int GetCount();
    void show();
};


#endif //CTRAINING_BIGNUMBER_H
