//
// Created by Marius on 7/30/2017.
//

#include <algorithm>
#include <iostream>


struct node {
    int value;
    node *next;
};

node *head;
node *tail;

void print();

void initialize();

void swap(int a, int b);

bool insert(int value);

node *find(int value);

int main() {
    initialize();

    for(int i = 1 ; i < 10;i++){
        insert(i);
    }
    print();
    std::cout << "\n";
    swap(4,6);
    std::cout << "\n";
    print();
    swap(1,8);
    std::cout << "\n";
    print();
    swap(8,9);
    std::cout << "\n";
    print();
    swap(2,8);
    std::cout << "\n";
    print();
    swap(3,6);
    std::cout << "\n";
    print();
    swap(7,1);
    std::cout << "\n";
    print();
    swap(3,3);
    std::cout << "\n";
    print();

}

void initialize() {

    head = new node();
    tail = new node();

    head->value = -1;
    head->next = tail;
    tail->next = tail;
}

void print() {

    node *n = head;
    while (n != tail) {
        std::cout << n->value << " ";
        n = n->next;
    }
    std::cout << n->value;
}

bool insert(int value) {

    if (find(value) == NULL) {

        if (head->value == -1) {
            head->value = value;
            head->next = tail;
            return true;
        }
        else {
            tail = tail->next;
            node *new_tail = new node();
            tail->value = value;
            tail->next = new_tail;

            return true;
        }

    }

    return false;
}

node *find(int value) {

    node *n = head;

    while (n != tail) {
        if (n->value == value) {
            return n;
        }
        n = n->next;
    }
    if (n->value == value) {
        return n;
    }
    return NULL;
}

void swap(int v1, int v2) {


    node *p1 = find(v1);
    node *p2 = find(v2);

    if (p1 != NULL && p2 != NULL && v1 != v2) {
        if (p1 == head && p1->next == p2) {
            p1->value = v2;
            p1->next = head;

            p2->value = v1;
            head->next = p2;

        }

        else if (p1 == head && p2 == tail) {

            tail->value = v1;
            p1->value = v2;
            p1->next = head->next;

        }

        else{
            node *prev_p1 = NULL, *suc_p1 = NULL, *prev_p2 = NULL, *suc_p2 = NULL;
            node *n = head;

            do{
                if(n->next == p1){
                    prev_p1 = n;
                }
                if(p1->next == n){
                    suc_p1 = n;
                }

                if(p2 -> next == n){
                    suc_p2 = n;
                }

                if(n->next == p2){
                    prev_p2 = n;
                }

                if(n == tail){
                    break;
                }

                n = n->next;
            }
            while(true);

            if(p1->next == p2){
                prev_p1->next = p2;
                p1->next = suc_p2;
                p2->next = p1;

            }

            else if(prev_p1 != NULL && prev_p2 != NULL && suc_p1 != NULL && suc_p2 != NULL) {
                prev_p1->next = p2;
                p2->next = suc_p1;

                prev_p2->next = p1;
                p1->next = suc_p2;
            }

            else{

                if(prev_p1 == NULL){

                    prev_p2->next = p1;
                    p1->next = p2->next;

                    p2->next = suc_p1;
                    head = p2;
                }

                else if(suc_p2 == NULL){

                    prev_p1->next = p2;
                    p2->next = suc_p1;

                    prev_p2->next = p1;
                    p1->next = p1;
                    tail = p1;
                }
            }

        }

    }
}