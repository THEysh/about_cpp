//
// Created by top on 2022-11-12.
//

#ifndef PROJECT3_FUNICTON_H
#define PROJECT3_FUNICTON_H
#include <string>
int* funnums();
class Box{
private:
    int year;
protected:
    std::string name;
public:
    Box(); //构造函数

    ~Box();  // 这是析构函数声明
    //析构函数的名称与类的名称是完全相同的，只是在前面加了个波浪号（~）作为前缀，
    //它不会返回任何值，也不能带有任何参数。析构函数有助于在跳出程序（比如关闭文件、释放内存等）前释放资源。
    double box_l;
    double box_w;
    double box_h;
    double getvol();
    void setinf(double l,double w,double h);
    void setname(std::string str);
    void setyear(int y);
    double boxintface(Box box);
};

class SmallBox: public Box {// SmallBox 是派生类
public:
    SmallBox(std::string name);
    double getmin_length();
    std::string getname();
    int getyear();
};

#endif //PROJECT3_FUNICTON_H
