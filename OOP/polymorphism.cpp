//
// Created by Marius on 7/6/2017.
//

#include <math.h>
#include <iostream>

using namespace std;

class Form {
public:
    virtual double ComputeArea() = 0;

    virtual const char *GetName() = 0;
};

class Rectangle : public Form {
    int width, length;
public:
    Rectangle(int width, int height) {
        this->width = width;
        this->length = height;
    }

    double ComputeArea() {
        return width * length;
    }

    const char *GetName() {
        return "Rectangle";
    }
};

class Circle : public Form {
    int ray;
public:
    Circle(int ray) {
        this->ray = ray;
    }

    double ComputeArea() {
        return M_PI * ray * ray;
    }

    const char *GetName() {
        return "Circle";
    }
};

class Triangle : public Form {
    int x1, y1, x2, y2, x3, y3;
public:
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
        this->x1 = x1;
        this->y1 = y1;

        this->x2 = x2;
        this->y2 = y2;

        this->x3 = x3;
        this->y3 = y3;
    }

    double ComputeArea() {
        return fabs((double) (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2);
    }

    const char *GetName() {
        return "Triangle";
    }
};


int main() {

    Form *elements[3];
    elements[0] = new Rectangle(2,3);
    elements[1] = new Circle(4);
    elements[2] = new Triangle(15, 15, 23, 30, 50, 25);

    cout << elements[0]->GetName() << "\t" << elements[0]->ComputeArea() << endl;
    cout << elements[1]->GetName() << "\t" << elements[1]->ComputeArea() << endl;
    cout << elements[2]->GetName() << "\t" << elements[2]->ComputeArea() << endl;

    return 0;
}
