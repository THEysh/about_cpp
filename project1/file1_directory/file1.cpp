//
// Created by top on 2022-11-12.
//
#include<ctime>
#include <iostream>
using namespace std;


int minfun(int num1, int num2){
    // 局部变量声明
    int result;
    if (num1 < num2)
        result = num1;
    else
        result = num2;
    return result;
}
int maxfun(int num1, int num2){
    // 局部变量声明
    int result;
    if (num1 > num2)
        result = num1;
    else
        result = num2;
    return result;
}

void fun3(){

    cout << "Size of char : " << sizeof(char) << endl;
    cout << "Size of int : " << sizeof(int) << endl;
    cout << "Size of short int : " << sizeof(short int) << endl;
    cout << "Size of long int : " << sizeof(long int) << endl;
    cout << "Size of float : " << sizeof(float) << endl;
    cout << "Size of double : " << sizeof(double) << endl;
    cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;

    bool bool_test = true;
    int int_test = 1034;
    double double_test = -6;
    cout << "下面是对cout的使用,默认情况下：" <<endl;
    cout << "booltest: " << bool_test << endl
         << "int_test: " << int_test << endl
         << "double_test: " << double_test <<endl << endl;

    cout << "设置 ios_base::boolalpha：" << endl;
    cout.setf(ios_base::boolalpha);
    cout << "booltest: " << bool_test << endl << endl;

    char d = 'd';
    enum color { red, green, blue } a,b,c;
    a = red;
    c = blue;
    // \b 退格
    cout<<"这里是头文件fun3,输出一个字符："<<d<<endl;
    cout<<"这里是头文件fun3,enum："<<a<<endl;
    cout<<"这是一个退格符号\b："<<endl;

}

void fun4time(){

    clock_t startTime,endTime;
    startTime = clock();//计时开始
    auto i = 1;

    /* 编程时常常需要把表达式的值赋给变量，这就要求声明变量时清楚的知道表达式的类型。
     * 然而有些情况是声明的变量的类型我们并不知道，比如在模板编程时。为了解决这个问题，C++11引入了auto类型说明符
     * 1.auto声明的变量必须要初始化，否则编译器不能判断变量的类型。这类似于const关键字。
       2.auto不能被声明为返回值，auto不能作为形参，auto不能被修饰为模板参数。*/

    for (i = 0; i < 100000000; i++){

    }

    endTime = clock();//计时结束
    //系统定义一个符号常量----CLOCKS_PER_SEC，该常量等于每秒钟包含的系统时间单位数。
    cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}

void funstatic(){
    //static 存储类指示编译器在程序的生命周期内保持局部变量的存在，而不需要在每次它进入和离开作用域时进行创建和销毁。
    // 因此，使用 static 修饰局部变量可以在函数调用之间保持局部变量的值。
    static int i =0;
    i++;
    cout<<"static i:"<<i<<endl;
}

void funoperators(){
    int a = 5;
    int b = 20;
    int c ;
    if ( a && b )
    {
        cout << "Line 1 - 条件为真"<< endl ;
    }
    if ( a || b )
    {
        cout << "Line 2 - 条件为真"<< endl ;
    }    /* 改变 a 和 b 的值 */
    a = 0;
    b = 10;
    if ( a && b )
    {
        cout << "Line 3 - 条件为真"<< endl ;
    }else{
        cout << "Line 4 - 条件为假"<< endl ;
    }
    if ( !(a && b) ){
        cout << "Line 5 - 条件为真"<< endl ;
    }

    a = 1;     // ^ 运算符，(1,0)=1,(0,1)=1,其他等于0
    b = 0;    //
    c = a ^ b;             //
    cout << "1^0,的值是 " << c << endl ;
    // 运算符
    //左移一位都相当于乘以2的1次方，左移n位就相当于乘以2的n次方
    //右移一位都相当于除以2的1次方，左移n位就相当于除以2的n次方
    a = 32;
    cout << "32<<2 等于32*(2的2次方) " << (a<<2) << endl ;
    cout << "32>>3 等于32/(2的3次方) " << (32>>3) << endl ;
}
void swap(int x, int y)
{
    int temp;
    temp = x; /* 保存 x 的值 */
    x = y;    /* 把 y 赋值给 x */
    y = temp; /* 把 x 赋值给 y */
}
void randnumber(){
    int i; int j;
    srand(2); //随机数种子
    for( i = 0; i < 5; i++ ){
        // 生成实际10内的随机数
        j= rand() % 10 + 1;
        cout <<"随机数： " << j << endl;
    }
}
