//
// Created by top on 2022-11-15.
//

#ifndef STL__TEMPLATE_H
#define STL__TEMPLATE_H
#include "cstring"
template<typename T>
void mySwap(T &a, T&b);
template<class T>
// 也可以替换成typename
//利用选择排序，进行对数组从大到小的排序
void mySort(T arr[], int len);
template<typename T>
void printArray(T arr[], int len);
void test01();
void test02();
void test03();

template<class NameType, class AgeType = int> //默认初始
class Person
{
public:
    Person(NameType name, AgeType age);
    void showPerson();
public:
    NameType mName;
    AgeType mAge;
};

void test04();
void test05();

//-----------------------------------------------

template<class NameType, class AgeType = int>
class Person2;
//1.
void printPerson1(Person2<std::string, int> &p);
void test06();
//2、参数模板化
template <class T1, class T2>
void printPerson2(Person2<T1, T2>&p);
void test07();
//3、整个类模板化
template<class T>
void printPerson3(T & p);
void test08();
#endif //STL__TEMPLATE_H
