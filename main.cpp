#include <iostream>
using namespace std;
int main() {
    std::cout << "Hello" << std::endl;
    std::string abc = "abcdgf";
    std::string s2(abc);
    cout<<&abc<< endl;
    cout<<&s2<<endl;
    s2[0] = 'k';
    cout<<abc<< endl;
    cout<<s2<< endl;
    string s3 = abc+s2;
    cout<<s3<< endl;
    cout<<s3.replace(0,10,"mytest")<< endl;
    cout<<s3.insert(0,3,'n')<< endl;

    string str = "abcdefg";
    string subStr = str.substr(1, 4); //返回由pos开始的n个字符组成的字符串
    cout << "subStr = " << subStr << endl;
    cout<<"hello"<<endl;
    return 0;
}
