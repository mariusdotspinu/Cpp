//
// Created by Marius on 8/1/2017.
//

#include <iostream>
#include <cstdlib>

struct stack{
    int *elements;
    size_t size = 0;

    int pop();
    void push(int x);
    void print();
};

int main(){

    stack my_stack;
    std::cout << my_stack.pop() << "\n";
    my_stack.push(4);
    my_stack.print();
    my_stack.push(5);
    my_stack.push(19);
    my_stack.push(20);
    my_stack.push(14);
    std::cout << my_stack.pop() << "\n";
    my_stack.print();
    my_stack.push(3124);
    std::cout << my_stack.pop() << "\n";
    my_stack.print();
}

int stack::pop(){

    if(size == 0){
        return -1;
    }
    int last = elements[size - 1];

    for(int i = size - 1; i < size ; i++){
        elements[i + 1] = elements[i];
    }

    size--;
    return last;
}

void stack::push(int x){

    if(!size){
        try {
            elements = (int *) std::malloc(size + 1);
        }
        catch (std::bad_alloc){
            std::cout << "bad alloc error\n";
        }
    }
    else{
        try {
            std::realloc(elements, size + 1);
        }
        catch (std::bad_alloc){
            std::cout << "bad realloc error\n";
        }
    }

    elements[++size - 1] = x;
}

void stack::print(){
    for(int i = size - 1 ; i >= 0; i--){
        std::cout << elements[i] << " ";
    }

    std::cout << std::endl;
}
