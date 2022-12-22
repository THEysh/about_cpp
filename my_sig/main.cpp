#include "TanMetaObject.h"
#include <iostream>
using namespace std;
class A
{
public:
    TanSignal<int, const char*> signal;

    void function(int a, const char* str){
        printf("function slot:%d, %s\n", a, str);
    }
};

class B
{
public:
    void function1(int a, const char* str){
        printf("class B slot:%d, %s\n", a, str);
    }
};

class C
{
public:
    void function2(vector<int> a){
        for (int i=0;i<10;i++){
            cout<<"i="<<a[i]<<endl;
        }
    }
};


int main(void)
{
    A a; B b; C c;
    connect(&a.signal, &a, &A::function);
    connect(&a.signal, &b, &B::function1);

    a.signal.emit(111, "123");
    TanSignal<vector<int>> signal_test;connect(&signal_test, &c, &C::function2);
    vector<int> data;
    for(int i=0;i<10;i++){
        data.push_back(i*i);
    }
    signal_test.emit(data);
    printf("**********\n");
    a.signal.emit(123, "abc");

    return 0;
}
