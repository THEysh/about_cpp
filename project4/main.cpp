#include <iostream>
using namespace std;
#include "function.h"

// 程序的主函数
int main( )
{
    Box Box1(1,2,3);                // 声明 Box1，类型为 Box
    Box Box2(2.3,4.2,4.1);                // 声明 Box2，类型为 Box
    Box Box3;                // 声明 Box3，类型为 Box
    double volume = 0.0;     // 把体积存储在该变量中

    // Box1 的体积
    volume = Box1.getVolume();
    cout << "Volume of Box1 : " << volume <<endl;

    // Box2 的体积
    volume = Box2.getVolume();
    cout << "Volume of Box2 : " << volume <<endl;

    // 把两个对象相加，得到 Box3
    Box3 = Box1 + Box2;

    // Box3 的体积
    volume = Box3.getVolume();
    cout << "Volume of Box3 : " << volume <<endl;

    cout<<"Box4 等于box3的维度相反"<<endl;
    Box Box4= -Box3;
    double a,b,c;
    a = Box4.getBreadth();b=Box4.getHeight();c=Box4.getHeight();
    cout<<"Box4的尺寸分别为"<<a<<","<<b<<","<<c<<endl;

    cout<<"比较box1 和box2 大小"<<endl;
    cout<<(Box1<Box2)<<endl;

    cout<<"重载运算符 Box2[1]="<<Box2[1]<<endl;
//    double q,w;
//    cout<<"输入2个double:"<<endl;
//    cin>>q>>w;
//    cout<<"输入为:"<<q<<","<<w<<endl;

    return 0;
}
