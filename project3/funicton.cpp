//
// Created by top on 2022-11-12.
//

#include "funicton.h"
#include <iostream>
using namespace std;
/* 关于继承: https://blog.csdn.net/m0_61334618/article/details/125880983 */
int* funnums(){
    int nums[5] = {11,22,32,51,46};
    int*p=new int[5];
    p=nums;
    return p;
}

Box::Box() {
    //我们可以使用 static 关键字来把类成员定义为静态的。
    //当我们声明类的成员为静态时，这意味着无论创建多少个类的对象，静态成员都只有一个副本。
    static int objectCount=0;
    objectCount++;
    cout<<"已经创建了盒子"<<objectCount<<"个"<<endl;
}
Box::~Box() {
    cout<<"盒子资源已经释放"<<endl;
}

double Box::getvol() {
    return box_h*box_l*box_w;
}
void Box::setinf(double l,double w,double h){
    box_l=l;box_h=h;box_w=w;
}
void Box::setname(std::string str){
    name = std::move(str);
}
void Box::setyear(int y) {
    year = y;
}
double Box::boxintface(Box box){
    cout<<"不同对象的交互"<<endl;
    double a = this->box_h;
    double b = box.box_h;
    return (a>b)?a:b;

}



SmallBox::SmallBox(std::string name) {
    setname(name);
    cout<<"小盒子创建成功，它的名字是:"<< this->name<<endl;
}
double SmallBox::getmin_length(){
    double min_long;
    min_long = (box_w>box_h)?box_h:box_w;
    min_long = (min_long>box_l)?box_l:min_long;
    return min_long;

}
std::string SmallBox::getname(){
    return name;  //protected 和 public可以被继承
}
int SmallBox::getyear(){
    //return year; // private 私有类无法继承,报错
    cout<<"私有类无法继承，设置返回0"<<endl;
    return 0;
}


