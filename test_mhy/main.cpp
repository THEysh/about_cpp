#include <vector>
#include "algorithm"
#include "iostream"
#include "function.h"
#include <regex>
#include <cstdlib>
using namespace std;
void printVector(vector<int>& v) {
    for (auto p : v){
        cout<<p<<" ";
    }
    cout << endl;
}
void test01()
{
    vector<int> v1; //无参构造
    for (int i = 0; i < 16; i++)
    {
        v1.push_back(i*i);
    }
    printVector(v1);
    vector<int> v2(v1.begin(), v1.end());
    printVector(v2);
    vector<int> v3(10, 100);
    printVector(v3);
    vector<int> v4(v3);
    printVector(v4);
    printf("---------------------------------\n");
//尾插
    v1.push_back(10);
    v1.push_back(20);
    printVector(v1);
//尾删
    v1.pop_back();
    printVector(v1);
//插入
    v1.insert(v1.begin(), 100);
    printVector(v1);
    v1.insert(v1.begin()+1, 2, 999);
    printVector(v1);
//删除
    v1.erase(v1.begin()+1);
    printVector(v1);
//清空
    v3.erase(v3.begin(), v3.end());
    v3.clear();
    printVector(v3);
    printf("===========================================\n");
    printVector(v1);
    printVector(v2);
    cout << "互换后" << endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);

}

Role luck_draw(MHY &all_role){

    if (probability(0.006)){
        return all_role.v5[rand()%all_role.v5.size()];
    }

    else if(probability(0.051)){
        return all_role.v4[rand()%all_role.v4.size()];
    }
    else{
        Role r("随机垃圾武器",3);
        return r;
    }

}
MHY begin(){
    MHY MHYtest;
    string name5 ="迪卢克,可莉,胡桃,宵宫,莫娜,达达利亚,珊瑚宫心海,神里绫人,夜兰,琴,温迪,枫原万叶,魈,雷电将军,八重神子,刻晴,"
                  "七七,神里绫华,申鹤,妮露,甘雨,优菈,埃洛伊,钟离,荒泷一斗,阿贝多,提纳里,赛诺,纳西妲,流浪者";
    string name4 ="安泊,丽莎,凯亚,芭芭拉,雷泽,班尼特,诺艾尔,谢菲尔,砂糖,迪奥娜,罗莎莉亚,北斗,凝光,香凝,行秋,重云,辛焱,烟绯,"
                  "云堇,早柚,九条裟罗,托马,五郎,九岐忍,鹿野院平藏,柯莱,多莉,坎蒂丝,莱伊拉,珐露珊,";
    regex reg(",");
    sregex_token_iterator iter1(name5.begin(), name5.end(), reg, -1); // 获取子字符串迭代器,若参数四改为0,则获取到与reg匹配的字符串迭代器,在本例中即为逗号
    decltype(iter1) end1;         // 这里不明白具体含义（看表达式为声明了一个与iter同样类型的变量end,但从上下文语意来看应当是为了获取子字符串尾后迭代器）
    sregex_token_iterator iter2(name4.begin(), name4.end(), reg, -1); // 获取子字符串迭代器,若参数四改为0,则获取到与reg匹配的字符串迭代器,在本例中即为逗号
    decltype(iter2) end2;
    for (; iter1 != end1; ++iter1)
    {
        Role temp_r(iter1->str(),5);
        MHYtest.add5(temp_r);
    }
    for (; iter2 != end2; ++iter2)
    {
        Role temp_r(iter2->str(),4);
        MHYtest.add4(temp_r);
    }

    return MHYtest;

}
void draw(int n){
    MHY all_role = begin();
    vector<Role> q5;
    vector<Role> q4;
    vector<Role> all_re;
    for(int i=0;i<n;i++){
        Role temp_role = luck_draw(all_role);

        if (q5.size()>=89){
            Role r5_90 = all_role.v5[rand()%all_role.v5.size()];
            all_re.push_back(r5_90);
            q5 = vector<Role>();
            q4 = vector<Role>();
            continue;
        }
        else if (q4.size()>=9){
            Role r4_10 = all_role.v4[rand()%all_role.v4.size()];
            all_re.push_back(all_role.v4[rand()%all_role.v4.size()]);
            q5.push_back(r4_10);
            q4 = vector<Role>();
            continue;
        }
        else{
            cout<<temp_role.start<<endl;
            if (temp_role.start==5){
                q5 = vector<Role>();
                all_re.push_back(temp_role);
            }
            else if (temp_role.start==4){
                q4 = vector<Role>();
                q5.push_back(temp_role);
                all_re.push_back(temp_role);
            }
            else{
                q4.push_back(temp_role);
                q5.push_back(temp_role);
                all_re.push_back(temp_role);
            }
        }


    }
    for(int i=0;i<n;i++){
        cout<<"次数:"<<i+1<<","<<all_re[i].name<<","<<all_re[i].start<<"星"<<endl;
    }
}
int main() {
    srand(time(nullptr));
    draw(100);

    return 0;
}
