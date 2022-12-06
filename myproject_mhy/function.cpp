//
// Created by top on 2022-12-06.
//
#include "iostream"
#include "function.h"
using namespace std;

Role::Role(string n,int sta){
    this->name = n;
    this->start = sta;
}
void Role::show(){
    cout<<start<<"星,"<<name<<endl;
}

MHY::MHY() {
    cout<<"创建成功"<<endl;
}
void MHY::add(Role r) {
    this->v.push_back(r);
}
void MHY::show_v() {
    for(auto s:v){
        s.show();
        cout<<endl;
    }
    cout<<endl;
}
