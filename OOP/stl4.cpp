//
// Created by Marius on 7/13/2017.
//

//implementation of vector

#include <iostream>
#include <utility>

using namespace std;

class StrVector {
private:
    int size;
    string *elements;

    string *GetElements() {
        return elements;
    }

public:
    StrVector(initializer_list<string> s) : size(s.size()){
        elements = new string[size];
        int i = 0;
        for (initializer_list<string>::iterator it = s.begin(); it != s.end(); ++it) {
            elements[i++] = *it;
        }
    }

    StrVector(int s) : size(s) {
        elements = new string[s];
        for (int i = 0; i < s; i++) {
            elements[i] = "";
        }
    }

    int GetCount() {
        return size;
    }

    StrVector &operator=(StrVector &v) {
        if (this != &v) {
            if (this->size != v.GetCount()) {
                delete[] elements;
                this->size = 0;
                elements = new string[v.GetCount()];
                this->size = v.GetCount();
            }
            std::copy(v.GetElements(), v.GetElements() + v.GetCount(), elements);
        }
        return *this;
    }

    StrVector &operator=(string v[]) {

        delete[] elements;
        this->size = 0;
        int otherStringSize = sizeof(v)/ sizeof(string);
        elements = new string[otherStringSize];
        this->size = otherStringSize;
        std::copy(v, v + otherStringSize, elements);

        return *this;
    }
    string* GetIterator(){
        return elements;
    }
    string* begin(){
        return &elements[0];
    }
    string* end(){
        return &elements[size];
    }
};

int main() {
    StrVector a = {"e", "E", "d"};
    std::cout << a.GetCount()<<endl;
    auto it = a.GetIterator();

    auto count= a.GetCount();

    for(auto index = 0 ;index < count; index++, it++){
        cout << *it <<" ";
    }
    cout << endl;

    for(auto element:a){
        cout << element << " ";
    }
}