//
// Created by top on 2022-11-15.
//


#include "iostream"
using namespace std;
template<typename T>
void mySwap(T &a, T&b)
{
    T temp = a;
    a = b;
    b = temp;
}
template<class T> // 也可以替换成typename
//利用选择排序，进行对数组从大到小的排序
void mySort(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int max = i; //最大数的下标
        for (int j = i + 1; j < len; j++)
        {
            if (arr[max] < arr[j])
            {
                max = j;
            }
        }
        if (max != i) //如果最大数的下标不是i，交换两者
        {
            mySwap(arr[max], arr[i]);
        }
    }
}
template<typename T>
void printArray(T arr[], int len) {

    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void test01()
{
//测试char数组
    char charArr[] = "bdcfeagh";
    int num = sizeof(charArr) / sizeof(char);
    mySort(charArr, num);
    printArray(charArr, num);
}
void test02()
{
//测试int数组
    int intArr[] = { 7, 5, 8, 1, 3, 9, 2, 4, 6 };
    int num = sizeof(intArr) / sizeof(int);
    mySort(intArr, num);
    printArray(intArr, num);
}
void test03()
{
//测试int数组
    double doubleArr[] = { 732.1, 15.2, 0.128, 1.12, 31.2, 91.24, 213.2, 1.4, 123.6 };
    mySort(doubleArr,sizeof(doubleArr)/sizeof(double ));
    printArray(doubleArr,sizeof(doubleArr)/sizeof(double ));
}

template<class NameType, class AgeType = int> //默认初始
class Person{
public:
    Person(NameType name, AgeType age)
    {
        this->mName = name;
        this->mAge = age;
    }
    void showPerson()
    {
        cout << "name: " << this->mName << " age: " << this->mAge << endl;
    }
public:
    NameType mName;
    AgeType mAge;
};

//1、类模板没有自动类型推导的使用方式
void test04()
{
// Person p("孙悟空", 1000); // 错误 类模板使用时候，不可以用自动类型推导
    Person <string ,int>p("孙悟空", 1000); //必须使用显示指定类型的方式，使用类模板
    p.showPerson();
}
//2、类模板在模板参数列表中可以有默认参数
void test05()
{
    char chrdata[12] = "猪宝宝";
    Person <char*> p(chrdata, 999); //类模板中的模板参数列表 可以指定默认参数
    p.showPerson();
}

//-----------------------------------------------

template<class NameType, class AgeType = int>
class Person2
{
public:
    Person2(NameType name, AgeType age)
    {
        this->mName = name;
        this->mAge = age;
    }
    void showPerson()
    {
        cout << "name: " << this->mName << " age: " << this->mAge << endl;
    }
public:
    NameType mName;
    AgeType mAge;
};
//1.
void printPerson1(Person2<string, int> &p)
{
    p.showPerson();
}
void test06()
{
    Person2 <string, int >p("孙悟空", 100);
    printPerson1(p);
}
//2、参数模板化
template <class T1, class T2>

void printPerson2(Person2<T1, T2>&p)
{
    p.showPerson();
    cout << "T1的类型为： " << typeid(T1).name() << endl;
    cout << "T2的类型为： " << typeid(T2).name() << endl;
}
void test07()
{
    Person2 <string, int >p("猪八戒", 90);
    printPerson2(p);
}
//3、整个类模板化
template<class T>
void printPerson3(T & p)
{
    cout << "T的类型为： " << typeid(T).name() << endl;
    p.showPerson();
}
void test08()
{
    Person2 <string, int >p("唐僧", 30);
    printPerson3(p);
}