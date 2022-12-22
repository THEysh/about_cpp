#include <iostream>
#include <regex>
#include <string>
using namespace std;
// https://blog.csdn.net/qq_34802416/article/details/79307102
//https://blog.csdn.net/weixin_39589699/article/details/125209486
//https://blog.csdn.net/ZL941208/article/details/125610194

void iphone_number(){
    // 实现电话号码 匹配
    string numbers="13385550742";
    int res;
    res = regex_match(numbers, regex("^1[0-9]{10}"));
    cout << res << endl;
    if (res == 0)
        {
            cout << "输入格式不正确" << endl;
        }
        else
        {
            cout <<"输入格式正确，str="<< numbers << endl;
        }

}
void ema(){
    // 邮箱匹配
    string ema="1338asdASD7ZS2@qq.com";
    int res;
    res = regex_match(ema, regex("[0-9,a-z,A-Z]{1,100}@{1}[0-9,a-z,A-Z]{1,100}(.com){1}"));
    cout << res << endl;
    if (res == 0)
    {
        cout << "输入格式不正确" << endl;
    }
    else
    {
        cout <<"输入格式正确，str="<< ema << endl;
    }

}
void is_number(){
    // 输入的是不是一个数字
    string number="2";
    int res;
    res = regex_match(number, regex("\\d{1}"));
    cout << res << endl;
    if (res == 0)
    {
        cout << "输入格式不正确" << endl;
    }
    else
    {
        cout <<"输入格式正确，str="<< number << endl;
    }

}
void ext(){
    // 提取信息
    string str = "hello201-12-12world!!20-2-2!2019-12-11!!";
    smatch match;
    regex pattern("(\\d{4})-(\\d{1,2})-(\\d{1,2})");

    if (regex_search(str,match,pattern))
    {
        for (size_t i = 1; i < match.size(); ++i)
        {
            cout << match[i] << endl;
        }
    }
}
void ext_inf(){
    string str = "2019-08a-07,af2019af-fdh08hfg-08,fas2019-08-09,hf2019cxb-12lkj-22";
    smatch matchresult;
    regex pattern("(\\d{4}-\\d{1,2}-\\d{1,2})");
    string::const_iterator iterStart = str.begin();
    string::const_iterator iterEnd = str.end();
    while (regex_search(iterStart, iterEnd, matchresult, pattern))
    {
        string temp = matchresult[0];
        cout << temp << " ";
        iterStart = matchresult[0].second;	//更新搜索起始位置,搜索剩下的字符串
    }
}
void rep1(){
    string str = "Hello_2022!";
    regex pattern("(Hello)");
    cout<<endl;
    cout << regex_replace(str, pattern, "") << endl;	//输出：_2022，将Hello替换为""
    cout << regex_replace(str, pattern, "Hi") << endl;	//输出：Hi_2018，将Hello替换为Hi

}
void rep2(){
    string str = "2022-08-07";
    regex pattern(R"((\d{4}-\d{1,2}-\d{1,2}))");
    cout<<endl;
    cout << regex_replace(str, regex("(\\d{4})-(\\d{1,2})-(\\d{1,2})"), "$2月$3日$1年") << endl;


}
int main()
{
/*
         * ^：限定开头的字符
        $：限定结尾的字符
         \d：匹配数字字符
        \D：匹配非数字字符
        \s：匹配空格
        \S：匹配非空格
        \w：匹配一般字符（字母，数字，下划线）
        \W：匹配除了字母/数字、下划线外的字符
        .：匹配任意单个字符
        *：*前的单个字符可以出现任意次（单个字符包括空格）
        +：+前的单个字符至少出现一次（单个字符不包括空格）
        ?：?前的单个字符最多出现一次
        ()分组:(123)，这样可以将匹配到的123取出来
        {}长度:{4,9}，这个表示前一个字符串的长度为4到9
        []范围:[a-z]，这个表示匹配所有的小写字母
        */
    iphone_number();
    ema();
    is_number();
    ext();
    ext_inf();
    rep1();
    rep2();
    return 0;
}
