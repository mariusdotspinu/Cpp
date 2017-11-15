//
// Created by Marius on 8/2/2017.
//

#include <iostream>
#include <cstdlib>

struct queue{
    int *elements;
    size_t size = 0;

    bool enqueue(int x);
    int dequeue();
    void print();
};

bool queue::enqueue(int x) {
    if(!size){
        try {
            elements = (int *)std::malloc(++size);
        }
        catch (std::bad_alloc){
            return false;
        }
    }
    else{
        try {
            std::realloc(elements, ++size);
        }
        catch (std::bad_alloc){
            return false;
        }
    }

    elements[size - 1] = x;
    return true;

}

int queue::dequeue() {
    if (!size){
        return -1;
    }

    int first = elements[0];

    for(int i = 0 ; i < size;i++){
        elements[i] = elements[i + 1];
    }
    size--;

    return first;
}

void queue::print(){
    for(int i = 0 ; i < size;i++){
        std::cout << elements[i] << " ";
    }
    std::cout << std::endl;
}

int main(){

    queue my_queue;
    my_queue.enqueue(4);
    my_queue.enqueue(5);
    my_queue.enqueue(125);
    my_queue.enqueue(1643);
    std::cout << my_queue.dequeue() << std::endl;
    my_queue.print();
}