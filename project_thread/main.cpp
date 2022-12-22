#include <iostream>
#include <thread>
#include <future>
#include <windows.h> //Sleep
// https://blog.csdn.net/qq_34213260/article/details/106445995
using namespace std;
int my_count = 0;
mutex m;
class Abc {
public:
    // 随意的一个类
    int something = 33;
    mutable int m_i; //mutable关键字，任何情况下都可以修改变量。即使实在const中也可以被修改
    Abc(int i) :m_i(i) {}
};

void t1()  //普通的函数，用来执行线程
{
    lock_guard<mutex> lock_guard(m);
    for (int i = 0; i < 10; ++i)
    {
        my_count ++;
        cout<<"t1:"<<my_count<<endl;
        Sleep(10); //1000 表示 1秒
    }
}
void t2()
{
    lock_guard<mutex> lock_guard(m);
    for (int i = 0; i < 20; ++i)
    {

        my_count ++;
        cout<<"t2:"<<my_count<<endl;
        Sleep(10);
    }
}

void t3(int a,char *b,vector<int> c,shared_ptr<char> d,const Abc& e){
    // 传参
    m.lock();
    cout<<"t3,c[0]:"<<c[0]<<endl;
    m.unlock();
}

void t4(const vector<double> test, std::promise<double> &promiseObj){
    m.lock();
    cout << this_thread::get_id() << ">: 子线程正在执行" << endl;
    cout << this_thread::get_id() << ">: 子线程开始睡眠" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout<< this_thread::get_id() << ">: 子线程睡眠了1秒" << endl;
    m.unlock();
    promiseObj.set_value(test[0]); //传值
}

int main()
{
    thread th1(t1);  //实例化一个线程对象th1，使用函数t1构造，然后该线程就开始执行了（t1()）
    thread th2(t2);
    // 多线程传参数
    int a = 999;
    char data[10] = "ABCDasd";
    vector<int> vec_data;
    vec_data.push_back(101);vec_data.push_back(102);
    shared_ptr<char> p(data);
    Abc testclass(10);
    thread th3(t3,a,data,vec_data,p,testclass);
    // -------------------多线程返回值 借用 future方法------------------------------
    vector<double> d_data;
    d_data.push_back(21.2);
    std::promise<double> promiseObj;
    //将future和promise关联
    std::future<double> futureObj = promiseObj.get_future();
    //模板传参的时候使用ref，否则传参失败
    thread th4(t4,d_data, ref(promiseObj));

    th1.join();
    th2.join();
    th3.join();
    th4.join();
    //获取值
    double t4_ans = futureObj.get();
    std::cout << "t4_ans=" << t4_ans << std::endl;
    cout << "here is main\n";

    return 0;
}