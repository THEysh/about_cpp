#include <iostream>
using namespace std;
#include "funciton.h"
#include "cstring"
template <typename T>  // or class T
void Swap(T &a, T &b)
{
    cout<<"原始:"<<a<<","<<b<<endl;
    T temp;   // temp a variable of type T
    temp = a;
    a = b;
    b = temp;
    cout<<"交互后:"<<a<<","<<b<<endl;
}

int main (){
    // 模板
    char ad[4] ="abc" ;
    char *p = new char[4];
    strcpy(p,ad);
    cout<<ad<<endl;
    string sa= "avd";
    strlen(ad);


    int i = 10;
    int j = 20;
    Swap(i, j); //Swap必须在main函数

    string *p2 = nullptr;
    string teststr = "helloworld";
    p2 = &teststr;
    auto p_a = &teststr; //利用auto 与上面等价
    cout<<*p2<<endl;

    char chardata2[] = {'q','w'};
    char *p_char2 = chardata2;
    cout<<*p_char2<<endl;

    char chardata[3] = {'a','b','c'};
    char *p3 = chardata;
    cout<<*p3<<endl;

    cout<<"动态内存分配"<<endl;
    int ROW = 2;
    int COL = 3;
    // 动态内存分配
    int nums[][2] = {23,435,63,7,4,2};
    int **p_nums = new int*[ROW];//等价 int *p_nums[2];
    auto p_auto_nums = nums;
    cout<<"auto of p,p_auto_nums[0][0]"<<p_auto_nums[0][0]<<endl;
    cout<<"auto of p,*(p_auto_nums+1)"<<*(p_auto_nums+1)<<endl; //第二行第一列地址
    cout<<"auto of p,**(p_auto_nums+1)"<<**(p_auto_nums+1)<<endl;
    for (int i=0;i<COL;i++){
        p_nums[i] = new int[i];
        p_nums[i] = nums[i];
        for(int j =0;j<2;j++){
            cout<< nums[i][j] <<endl;
            cout<< p_nums[i][j]<<endl;
            cout<<"----"<<endl;
        }
    }
    // 清除内存
    for(int i = 0; i < COL; i++) {
        delete[] p_nums[i];
    }
    delete [] p_nums;


    return 0;
}

