//
// Created by top on 2022-11-12.
//

#ifndef PROJECT3_FUNICTON_H
#define PROJECT3_FUNICTON_H

#include <string>

class Box{
private:
    int year;
protected:
    std::string name;
public:
    double box_l;
    double box_w;
    double box_h;
    double getvol();
    void setinf(double l,double w,double h);
    void setname(std::string str);
    void setyear(int y);
};

class SmallBox: public Box {// SmallBox 是派生类
public:
    double getmin_length();
    std::string getname();
    int getyear();
};

#endif //PROJECT3_FUNICTON_H
