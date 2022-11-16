//
// Created by top on 2022-11-16.
//

#ifndef STL__PERSON_HPP
#define STL__PERSON_HPP

#pragma once
#include <iostream>
using namespace std;
#include <string>
template<class T1, class T2>
class Personhpp {
public:
    Personhpp(T1 name, T2 age);
    void showPerson();
public:
    T1 m_Name;
    T2 m_Age;
    void test09(Personhpp<string, int> &p);
};
//构造函数 类外实现
template<class T1, class T2>
Personhpp<T1, T2>::Personhpp(T1 name, T2 age) {
    this->m_Name = name;
    this->m_Age = age;
}
//成员函数 类外实现
template<class T1, class T2>
void Personhpp<T1, T2>::showPerson() {
    cout << "姓名: " << this->m_Name << " 年龄:" << this->m_Age
         << endl;
}

template<class T1, class T2>
void Personhpp<T1, T2>::test09(Personhpp<string, int> &p) { //必须要在类文件里先说明test09
    p.showPerson();
}

#endif //STL__PERSON_HPP
