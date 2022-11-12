//
// Created by top on 2022-11-12.
//

#include "funicton.h"
#include <iostream>
using namespace std;
/* 关于继承: https://blog.csdn.net/m0_61334618/article/details/125880983 */
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