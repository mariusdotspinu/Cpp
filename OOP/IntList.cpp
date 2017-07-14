//
// Created by Marius on 7/2/2017.
//

#include <iostream>
#include "IntList.h"
using namespace std;

IntList::IntList() {
    Count = 0;
}

bool IntList::Add(int element) {

    if (Count == 1000) {
        return false;
    } else {
        Elements[Count++] = element;
        return true;
    }
}

bool IntList::Insert(int index, int element) {

    if (index < 0 || index >= Count || Count == 1000) {
        return false;
    } else {

        Count++;

        int replacer = Elements[index];
        int replacer2;

        for (int i = index + 1; i < Count; i++) {
            replacer2 = Elements[i];
            Elements[i] = replacer;
            replacer = replacer2;

        }

        Elements[index] = element;
        return true;
    }
}

bool IntList::Delete(int index) {

    if (index < 0 || Count == 0 || index >= Count) {
        return false;
    } else {
        for (int i = index; i < Count; i++) {
            Elements[i] = Elements[i + 1];
        }
        Count--;
        return true;
    }
}

void IntList::Clear() {

    int helperCount = Count;
    for (int i = 0; i < helperCount; i++) {
        Delete(0);
    }
}

int IntList::IndexOf(int valoare, int startPosition) {

    if (startPosition >= Count || startPosition == -1) {
        return -1;
    }

    for (int i = startPosition; i < Count; i++) {
        if (Elements[i] == valoare) {
            return i;
        }
    }
    return -1;
}

void IntList::RemoveDuplicates() {

    for (int i = 0; i < Count; i++) {
        for (int j = i + 1; j < Count; j++) {
            if (Elements[i] == Elements[j]) {
                Delete(this->IndexOf(Elements[i], 0));

                i = 0;
                j = i + 1;
            }
        }
    }
}

void IntList::Intersection(IntList *withList, IntList *resultList) {

    for (int i = 0; i < withList->GetCount(); i++) {
        for (int j = 0; j < GetCount(); j++) {
            if (Elements[j] == withList->Get(i)) {
                resultList->Add(Elements[j]);
            }
        }
    }
}

void IntList::Reunion(IntList *withList, IntList *resultList) {

    for (int i = 0; i < withList->GetCount(); i++) {
        resultList->Add(withList->Get(i));
    }

    for(int i = 0 ; i < Count; i++){
        resultList->Add(Elements[i]);
    }

    resultList->RemoveDuplicates();
}

void IntList::Sort() {
    for(int i = 0 ; i < Count; i++){
        for(int j = i + 1 ; j < Count;j++){
            if(Elements[i] > Elements[j]){
                Elements[i] = Elements[i] + Elements[j];
                Elements[j] = Elements[i] - Elements[j];
                Elements[i] = Elements[i] - Elements[j];
            }
        }
    }
}

void IntList::Reverse() {
    int j = -1;
    int aux[1000];

    for(int i = Count - 1; i >= 0 ; i--){
        aux[++j] = Elements[i];
    }
    for(int i = 0 ; i < Count; i++) {
        Elements[i] = aux[i];
    }
}

int IntList::Get(int index) {
    if(index < 0 || index >= Count){
        return -1;
    }

    return Elements[index];
}

int IntList::GetCount() {
    return Count;
}

int main(){

    //tests

    IntList myList = IntList();
    IntList secondList = IntList();
    IntList resultList = IntList();
    myList.Add(4);
    myList.Add(64);
    myList.Insert(1,24);
    myList.Insert(2,50);
    myList.Insert(67,12);
    myList.Insert(0,1);
    myList.Insert(2,25);
    myList.Insert(0,14);
    myList.Add(4);
    myList.Add(14);
    myList.Add(14);

    myList.Delete(0);
    myList.Delete(3);
    myList.Delete(14);

    cout << myList.IndexOf(64,4) << "\n\n\n";
    myList.RemoveDuplicates();


    secondList.Add(4);
    secondList.Add(25);
    myList.Intersection(&secondList, &resultList);

    cout<<"intersection : \n";
    for(int i = 0 ; i < resultList.GetCount(); i++){
        cout << resultList.Get(i) << "\n";
    }

    secondList.Add(114);
    resultList.Clear();

    myList.Reunion(&secondList, &resultList);

    cout<<"reunion : \n";
    for(int i = 0 ; i < resultList.GetCount(); i++){
        cout << resultList.Get(i) << "\n";
    }

    myList.Sort();
    cout<<"first list \n\n";
    for(int i = 0 ; i < myList.GetCount(); i++){
        cout << myList.Get(i) << "\n";
    }

    myList.Reverse();
    cout<<"reverse first \n\n";
    for(int i = 0 ; i < myList.GetCount(); i++){
        cout << myList.Get(i) << "\n";
    }

    return 0;
}