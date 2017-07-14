//
// Created by Marius on 7/2/2017.
//

#ifndef CTRAINING_INTLIST_H
#define CTRAINING_INTLIST_H


class IntList {
private:
    int Elements[1000];
    int Count;

public:
    IntList();
    bool Add(int element); //false if list is full (1000 elements)
    bool Insert(int index, int element);
    bool Delete(int index);
    void Clear();
    int IndexOf(int valoare, int startPosition); // index of value or "-1" otherwise
    void RemoveDuplicates();
    void Intersection(IntList* withList, IntList* resultList);
    void Reunion(IntList* withList, IntList* resultList);
    void Sort();
    void Reverse();
    int Get(int index); //position or "-1" if not found
    int GetCount();
};


#endif //CTRAINING_INTLIST_H
