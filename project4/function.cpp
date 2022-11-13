//
// Created by top on 2022-11-13.
//
#include "iostream"

using namespace std;

#include "function.h"

Box::Box(double w, double h, double l) {
    length = l;
    breadth = w;
    height = h;
    boxnums[0] = l;
    boxnums[1] = w;
    boxnums[2] = h;
    cout << "创建盒子成功" << endl;
}

Box::Box() {
    length = 0;
    breadth = 0;
    height = 0;
    cout << "创建盒子成功,长度均为0" << endl;
}

double Box::getVolume(void) {
    return length * breadth * height;
}

double Box::getLength() {
    return length;
}

double Box::getBreadth() {
    return length;
}

double Box::getHeight() {
    return height;
}

// 重载 + 运算符，用于把两个 Box 对象相加
Box Box::operator+(const Box &b) {
    Box box;
    box.length = this->length + b.length;
    box.breadth = this->breadth + b.breadth;
    box.height = this->height + b.height;
    return box;
}

Box Box::operator-() {
    Box box;
    box.length = -length;
    box.breadth = -breadth;
    box.height = -height;
    return box;
}

bool Box::operator<(Box const &b) {//比较两个box的长宽高和
    double one, two;

    one = b.length + b.height + b.breadth;
    two = length + height + this->breadth; //this->breadth 等价 breadth
    return (two < one);
}

bool Box::operator>(Box const &b) {
    return !this->operator<(b);
}

double Box::operator[](const int i) {
    return boxnums[i];
}