// smrtptrs.cpp -- using three kinds of smart pointers
#include <iostream>
#include <string>
#include <memory>
#include "algorithm"
class Report
{
private:
    std::string str;
public:
    Report(const std::string s) : str(s) { std::cout << "Object created!\n"; }
    ~Report() { std::cout << "Object deleted!\n"; }
    void comment() const { std::cout << str << "\n"; }
};

int main(){
//    {
//        std::auto_ptr<Report> ps (new Report("using auto_ptr"));
//        ps->comment();   // use -> to invoke a member function
//    }
// auto_ptr当这个智能指针指向同一对象，会造成这个对象被删除2次。c++17后被弃用
    {
        std::shared_ptr<Report> ps (new Report("using shared_ptr"));  // 常规使用这个指针
        ps->comment();
    }
    {
        std::unique_ptr<Report> ps (new Report("using unique_ptr"));
        ps->comment();
    } // unique_ptr当这个智能指针指向同一对象，会造成这个对象被删除2次。同样有问题，但这种情况 unique_ptr 会报错，不允许


    return 0;
}
