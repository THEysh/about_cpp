//
// Created by top on 2022-12-06.
//
#include "iostream"
#include "function.h"
using namespace std;
bool probability(float f){

    int re =(int) round(10000*f);
    int rand_number = rand()%10000+1; //1--1000随机数
    if (rand_number<=re){
        return true;
    }
    else{
        return false;
    }
}
Role::Role(string n,int sta){
    this->name = n;
    this->start = sta;
}
void Role::show(){
    cout<<start<<"星,"<<name<<endl;
}

MHY::MHY() {

}
void MHY::add5(Role r) {
    this->v5.push_back(r);
}
void MHY::add4(Role r) {
    this->v4.push_back(r);
}
void MHY::show_v() {
    for(auto s:v5){
        s.show();
        cout<<endl;
    }
    cout<<endl;
}
