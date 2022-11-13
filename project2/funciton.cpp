//
// Created by top on 2022-11-12.
//
#include "iostream"
#include "funciton.h"
#include <iomanip>
#include <tuple>
#include<cstring>
using namespace std;
using std::setw;

void funnums(){
    //setw字段宽度设置,setw( 7 ) 表示占7个位置
    int n[ 10 ]; // n 是一个包含 10 个整数的数组
    // 初始化数组元素
    for ( int i = 0; i < 5; i++ ){
        n[ i ] = i + 100; // 设置元素 i 为 i + 100
    }

    cout << "Element" << setw( 7 ) << "Value" << endl;

    // 输出数组中每个元素的值
    for ( int j = 0; j < 5; j++ ){
        cout << setw( 7 )<< j << setw( 7 ) << n[ j ] << endl;
    }
}

void funnums2(){
    int a [][4] = {
            {0, 1, 2, 3} ,   /*  初始化索引号为 0 的行 */
            {4, 5, 6, 7} ,   /*  初始化索引号为 1 的行 */
            {8, 9, 10, 11}   /*  初始化索引号为 2 的行 */
    };
    int b [][4] = {0,1,2,3,4,5,6,7,8,9,10,11};

    cout<<"size:"<< sizeof(a)/4<<endl;
}

void funpointer(){
    int  var;
    cout << "var1 变量的地址： ";
    cout << &var << endl;

    //定义一个指针变量、把变量地址赋值给指针、访问指针变量中可用地址的值。指针保存变量的地址
    var = 20;   // 实际变量的声明
    int  *ip = nullptr;        // 指针变量的声明
    ip = &var;       // 在指针变量中存储 var 的地址
    cout << "var 地址: ";
    cout << &var << endl;
    // 输出在指针变量中存储的地址
    cout << "指针变量中存储的地址: ";
    cout << ip << endl;
    // 访问指针中地址的值
    cout << "所指向数据的数值: ";
    cout << *ip << endl;
    cout << "这个指针的地址: ";
    cout << &ip << endl;
}

void funpointer_nums(){
    // 带有 5 个元素的整型数组
    cout << "-----------------------------数组指针---------------------------------- " << endl;
    double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
    double *p = balance;

    // 输出数组中每个元素的值
    cout << "使用指针的数组值 " << endl;
    for ( int i = 0; i < 5; i++ )
    {
        cout << "*(p + " << i << ") : ";
        cout << *(p + i) << endl;
    }

    cout << "使用 balance 作为地址的数组值,balance 为首位地址 " << endl;
    for ( int i = 0; i < 5; i++ )
    {
        cout << "*(balance + " << i << ") : ";
        cout << *(balance + i) << endl;
    }
    cout << "**(&balance)=" << **(&balance) << endl;
    cout <<"balance="<< balance << endl;
}

double getAverage(const int *arr, int size){
    //const int *arr, int *arr是一个常量，不可改变，但指针可以移动
    // const int *arr 可以改写 int arr[], int arr[5]
    //C++ 不允许向函数传递一个完整的数组作为参数，
    //但是，您可以通过指定不带索引的数组名来传递一个指向数组的指针。
    int i, sum = 0;
    double avg;

    for (i = 0; i < size; ++i)
    {
        sum += *(arr+i);
    }

    avg = double(sum) / size;

    return avg;
}

int* funnums_return(){
    int nums[5] = {1,2,3,5,6};
    int *p;
    p = nums;
    return p;
}

tuple<int *, int, bool> return_Random( ){
    //C++ 不允许返回一个完整的数组作为函数的参数。
    //但是，您可以通过指定不带索引的数组名来返回一个指向数组的指针。
    // 同时，可以用元组的方式，返回多个值
    // 要生成和返回随机数的函数 (1-100)
    static int  r[5];
    srand( 1); // 设置种子
    for (int i = 0; i < 5; ++i)
    {
        r[i] = rand()%100 + 1;
    }

    tuple<int *, int, int> re;
    re = make_tuple(r, 5, true);

    return re;
}

void fun_str(){
    // 有两种 str 求字符串长度
    string str1 = "Hello";
    char append_str1[100] =" abc";
    str1.append(append_str1);
    cout << str1 << endl;
    for ( int i=0;i< str1.size();i++){
        cout<<str1[i]<<endl;
    }
    char str2[100] = "world";
    cout << str2 << endl;
    for ( int i=0;i< strlen(str2);i++){
        cout<<str2[i]<<endl;
    }
    /* 导入 #include<cstring> 库
    1	strcpy(s1, s2);
    复制字符串 s2 到字符串 s1。
    2	strcat(s1, s2);
    连接字符串 s2 到字符串 s1 的末尾。
    3	strlen(s1);
    返回字符串 s1 的长度。
    4	strcmp(s1, s2);
    如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回小于 0；如果 s1>s2 则返回大于 0。
    5	strchr(s1, ch);
    返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。
    6	strstr(s1, s2);
    返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的位置。*/
    cout<<"strcmp="<<strcmp("hello","hello");
    cout<<endl;
    cout<<"strchr="<<strchr("hello",'l');
    cout<<endl;
    cout<<"strchr="<<strstr("hello","ell");

}

int* funppointer(){
    int  var;
    int &k = var;
    int  *ptr = nullptr;
    int  **pptr = nullptr;
    var = 3000;
    // 获取 var 的地址
    ptr = &var; // 等价 *ptr = var;
    // 使用运算符 & 获取 ptr 的地址
    pptr = &ptr;

    // 使用 pptr 获取值
    cout << "Value of var :" << var << endl;
    cout << "Value available at *ptr :" << *ptr << endl;
    cout << "Value available at **pptr :" << **pptr << endl;
    cout << "Value available at &k :" << &k << endl;
    cout << "Value available at k :" << k << endl;
    return ptr;
}

void about_time(){
    /*
     * time_t
    从1900年1月1日0点UTC时间开始的时间， 实际是一个long类型。单位秒。
     结构类型 tm 把日期和时间以 C 结构的形式保存，tm 结构的定义如下：
    struct tm {
    int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
    int tm_min;   // 分，范围从 0 到 59
    int tm_hour;  // 小时，范围从 0 到 23
    int tm_mday;  // 一月中的第几天，范围从 1 到 31
    int tm_mon;   // 月，范围从 0 到 11
    int tm_year;  // 自 1900 年起的年数
    int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起
    int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
    int tm_isdst; // 夏令时
    }
    asctime	tm 转 string
    ctime	time_t 转 string
    gmtime	UTC时间的time_t 转 tm
    localtime	本地时间的time_t 转 tm
    strftime	格式化为string
    mktime	tm 转time_t

    1	time_t time(time_t *time);
    该函数返回系统的当前日历时间，自 1970 年 1 月 1 日以来经过的秒数。如果系统没有时间，则返回 .1。
    2	char *ctime(const time_t *time);
    该返回一个表示当地时间的字符串指针，字符串形式 day month year hours:minutes:seconds year\n。
    3	struct tm *localtime(const time_t *time);
    该函数返回一个指向表示本地时间的 tm 结构的指针。
    4	clock_t clock(void);
    该函数返回程序执行起（一般为程序的开头），处理器时钟所使用的时间。如果时间不可用，则返回 .1。
    5	char * asctime ( const struct tm * time );
    该函数返回一个指向字符串的指针，字符串包含了 time 所指向结构中存储的信息，返回形式为：day month date hours:minutes:seconds year\n\0。
    6	struct tm *gmtime(const time_t *time);
    该函数返回一个指向 time 的指针，time 为 tm 结构，用协调世界时（UTC）也被称为格林尼治标准时间（GMT）表示。
    7	time_t mktime(struct tm *time);
    该函数返回日历时间，相当于 time 所指向结构中存储的时间。
    8	double difftime ( time_t time2, time_t time1 );
    该函数返回 time1 和 time2 之间相差的秒数。
    9	size_t strftime();
    该函数可用于格式化日期和时间为指定的格式。*/

    // 基于当前系统的当前日期/时间
    time_t now;
    time(&now);//获取现在的时间
    std::cout<<"当前时间: "<<now<<std::endl;//time_t转tm 从1990年经历了多少秒
    tm to_tm = *localtime(&now);//将刚刚获取的时间，转换为tm格式
    time_t to_time_t = mktime(&to_tm);//tm 转time_t;
    std::cout<<"to_time_t: "<<to_time_t<<std::endl;//time_t转tm 从1990年经历了多少秒
    std::cout <<"to_tm: "<<to_tm.tm_year<<std::endl;//从1990年经历了多少年
    std::cout <<"to_tm: "<<to_tm.tm_min<<std::endl; //这个小时过来几分钟？

    std::string thisTime = ctime(&to_time_t);//time_t转string,需要传地址
    std::cout<<thisTime<<std::endl;
    thisTime = asctime(&to_tm);//tm转string
    std::cout<<"tm转string="<<thisTime<<std::endl;

}

time_t StringToDatetime(const string &str)
{
    char *cha = (char*)str.data();             // 将string转换成char*。
    tm tm_;                                    // 定义tm结构体。
    int year, month, day, hour, minute, second;// 定义时间的各个int临时变量。
    sscanf(cha, "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);// 将string存储的日期时间，转换为int临时变量。
    tm_.tm_year = year - 1900;                 // 年，由于tm结构体存储的是从1900年开始的时间，所以tm_year为int临时变量减去1900。
    tm_.tm_mon = month - 1;                    // 月，由于tm结构体的月份存储范围为0-11，所以tm_mon为int临时变量减去1。
    tm_.tm_mday = day;                         // 日。
    tm_.tm_hour = hour;                        // 时。
    tm_.tm_min = minute;                       // 分。
    tm_.tm_sec = second;                       // 秒。
    tm_.tm_isdst = 0;                          // 非夏令时。
    time_t t_ = mktime(&tm_);                  // 将tm结构体转换成time_t格式。
    return t_;                                 // 返回值。
}

string funinput(){
    char name[50];
    cout << "请输入您的名称： ";
    cin >> name;
    cout << "您的名称是： " << name << endl;
    return name;
}