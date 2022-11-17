#include <iostream>
#include "funicton.h"
using namespace std;

inline double remax(double m1,double m2){
    return (m1>m2)?m1:m2;
}

int main() {

    int *re= nullptr;
    re = funnums();
    cout<<*(re+1)<<endl;

    Box box1;
    box1.setinf(2.3,2.1,4.5);
    box1.setname("name--box1");
    box1.setyear(12);
    // box1.name;  不可访问。
    cout<<box1.getvol()<<endl;
    cout << "内联函数，Max,得定义在main函数中 " << remax(2.3,4.3) << endl;

    //protected 保护成员变量或函数与私有成员十分相似，但有一点不同，保护成员在派生类（即子类）中是可访问的。
    //如果基类成员不想在派生类外直接被访问，但需要在派生类中访问，就定义为protected。可以看出保护成员限定符是因继承才出现的。
    SmallBox smallbox1("mysmallbox");
    smallbox1.setinf(1.3,2.5,3.3);
    smallbox1.setname("name--small-box1");
    smallbox1.setyear(13); //可以设置 但因为父类是私有类，无法得到这个值

    cout<<"smallbox1地址:"<<&smallbox1<<endl;
    cout<<"smallbox1:"<<smallbox1.getmin_length()<<endl;
    cout<<"smallbox1:"<<smallbox1.getname()<<endl;
    cout<<"smallbox1:"<<smallbox1.getyear()<<endl;

    cout<<"拷贝"<<endl;
    SmallBox smallbox2 = smallbox1; //地址会改变，这创建了一个新的对象
    smallbox2.setname("smallbox2");
    cout<<"拷贝后的smallbox2地址:"<<&smallbox2<<endl;
    cout<<"拷贝后的smallbox2:"<<smallbox2.getmin_length()<<endl;
    cout<<"拷贝后的smallbox2:"<<smallbox2.getname()<<endl;
    cout<<"拷贝后的smallbox2:"<<smallbox2.getyear()<<endl;
    cout<<"smallbox1地址:"<<&smallbox1<<endl;
    cout<<"smallbox1:"<<smallbox1.getmin_length()<<endl;
    cout<<"smallbox1:"<<smallbox1.getname()<<endl;
    cout<<"smallbox1:"<<smallbox1.getyear()<<endl;

    cout<<"拷贝2"<<endl;
    SmallBox* smallbox3 = new SmallBox("name--small-box1");
    smallbox3 = &smallbox1; // 这是拷贝了smallbox1，改数据就是改了smallbox1的数据
    cout<<smallbox3<<endl;
    cout<<"拷贝后的smallbox3"<<(*smallbox3).getmin_length()<<endl;
    cout<<"拷贝后的smallbox3"<<smallbox3->getname()<<endl;
    cout<<"拷贝后的smallbox3"<<smallbox3->getyear()<<endl;
    cout<<"smallbox3->getyear() 等价 (*smallbox3).getyear()"<<endl;

    double temp;
    temp = box1.boxintface(smallbox1);
    cout<<temp<<endl;

    int testint1 = 10;
    int testint2 = 110;
    int testint3 = 12;
    int testint4 = 31;
    // const 默认作用与左边，否则就作用于右边。先看const的左边，在看右边。（左边看类型或者是地址不能改变，右边则相反）
    int const a=0; //a不可以改变
    int * const p1 = &testint1; //p1不可改变，即指针指向的地址不能改变，该地址存储的数据可以改变。
    // p1 = &testint2 //报错
    //    *p1 = 20; //不报错
    int const* p2 = &testint2; //数据不可以改变，指针指向可以改变
    //    p2 = &testint1; //不报错
    //    *p2 = 30 ;//报错
    const int* const p3 =&testint3; //第一个const作用于int ，第二个作用于*;所以，指针指向，数据都不能改变
    //    *p3 =22; //报错
    //    p3 = &testint1; //报错
    int const * const p4 = &testint4; //同理，第一个const作用于int ，第二个作用于*;所以，指针指向，数据都不能改变
//    *p4 =22; //报错
//    p4 = &testint1; //报错

    cout<<"p1:"<<*p1<<endl;

    return 0;
}
