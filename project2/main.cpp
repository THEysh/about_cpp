#include <iostream>
#include "funciton.h"
#include <tuple>
#include "ctime"
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    funnums();
    funnums2();
    funpointer();
    funpointer_nums();

    int balance[5] = {1000, 2, 3, 17, 50};
    double avg;
    avg = getAverage(balance, sizeof(balance)/sizeof(int));
    cout<<"arg="<<avg<<endl;

    //可以用元组的方式，返回多个值
    tuple<int *, int, bool> ans =  return_Random(); //定义ans
    int* nums_p;int p1;bool p2; //定义
    tie(nums_p, p1, p2) = ans;
    cout<<"nums_p="<<nums_p<<" p1="<<p1<<" p2="<<p2<<endl;
    for(int i=0;i<p1;i++){
        cout<<"*nums_p+"<<i<<"="<<*(nums_p+i)<<endl;
    }

    fun_str();
    int *p = nullptr;
    p = funppointer();
    cout<<"*p="<<*p<<endl;

    about_time();

    string str_time1="2008-12-13 0:0:0";   string str_time2="2028-12-19 0:0:0";
    time_t time_t_str_time1; time_t time_t_str_time2;
    time_t_str_time1 = StringToDatetime(str_time1); // 字符串转时间
    time_t_str_time2 = StringToDatetime(str_time2); // 字符串转时间
    cout<< "计算之间间隔的天数为:" <<difftime(time_t_str_time2,time_t_str_time1)/(60*60*24)<<endl;

    funinput(); //用cin输入
    return 0;
}
