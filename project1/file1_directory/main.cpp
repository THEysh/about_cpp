#include <iostream>
#include "file1.h"

using namespace std;

// 这是定义常量
const int  NUM = 10;
int main (){


    fun3();
    cout << "常量 : " << NUM << endl;
    fun4time();
    for(int k; k<5;k++){
        funstatic();
    }
    funoperators();

    int a=100;int b=200;
    swap(a,b); // 这样传值是改变地址，不用返回也也能交换
    cout<<"a="<<a<<"b="<<b<<endl;
    //生产随机数
    randnumber();
    return 0;
}   // 函数返回两个数中较大的那个数

