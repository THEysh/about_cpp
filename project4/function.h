//
// Created by top on 2022-11-13.
//

#ifndef PROJECT4_FUNCTION_H
#define PROJECT4_FUNCTION_H


class Box
{
    double length;      // 长度
    double breadth;     // 宽度
    double height;      // 高度
    double boxnums[3];
public:
    Box();
    Box(double w,double h,double l);
    double getVolume(void);
    double getLength();
    double getBreadth();
    double getHeight();
    // 重载 + 运算符，用于把两个 Box 对象相加
    Box operator+(const Box& b);
    Box operator-();
    bool operator <(Box const &b);
    bool operator>(Box const &b);
    double operator[](int i);
};


#endif //PROJECT4_FUNCTION_H
