//
// Created by Marius on 7/29/2017.
//

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

struct square{
    int **matrix;
    int lines, columns, size;
};

struct checker{
    bool condition;
    int sum = -1;
};

checker ColumnSum(int **matrix, int size){
    int sum = -1, last = 0;
    checker ck;
    for(int j = 0 ; j < size;j++){
        sum = 0;
        for(int i = 0 ; i < size; i++){
            sum += *(*(matrix + i) + j);
        }

        if(sum != last && j != 0){
            ck.condition = false;
            return ck;
        }
        last = sum;
    }

    ck.condition = true;
    ck.sum = sum;

    return ck;
}

checker LineSum(int **matrix, int size){
    int sum = -1, last = 0;
    checker ck;
    for(int i = 0 ; i < size;i++){
        sum = 0;
        for(int j = 0 ; j < size; j++){
            sum += *(*(matrix + i) + j);
        }

        if(sum != last && i != 0){
            ck.condition = false;
            return ck;
        }
        last = sum;
    }

    ck.condition = true;
    ck.sum = sum;

    return ck;
}

checker DiagonalSum(int **matrix, int size){
    int sum = 0, sum1 = 0;
    checker ck;
    for(int i = 0 ; i < size;i++){
        for(int j = 0 ; j < size; j++){
            if(i == j) {
                sum += *(*(matrix + i) + j);
            }
            if(i + j == size - 1){
                sum1 += *(*(matrix + i) + j);
            }
        }

    }

    if(sum != sum1){
        ck.condition = false;
        return ck;
    }

    ck.condition = true;
    ck.sum = sum;

    return ck;
}

bool IsMagicSquare(square s){

    checker col = ColumnSum(s.matrix, s.size);
    checker line = LineSum(s.matrix, s.size);
    checker diagonal = DiagonalSum(s.matrix, s.size);

    if(col.condition == false || line.condition == false || diagonal.condition == false){
        return false;
    }

    if(col.sum != line.sum || col.sum != diagonal.sum || line.sum != diagonal.sum){
        return false;
    }

    return true;
}

int main(){
    square m;
    m.matrix = new int*[3];
    m.size = 3;
    for(int i = 0 ;i < 3; i++){
        m.matrix[i] = new int[3];
    }

    srand((unsigned)time(0));

    do{
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                m.matrix[i][j] = (rand()%10) + 1;
            }

        }
    }
    while (IsMagicSquare(m) == 0);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
           std::cout << m.matrix[i][j] << " ";
        }
        std::cout << std::endl;

    }
}
