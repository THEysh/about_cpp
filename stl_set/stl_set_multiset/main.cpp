#include <iostream>
using namespace std;
#include "set"
void printSet(set<int> & s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
//构造和赋值
void test01() {
    set<int> s1;
    auto x1 = s1.insert(10);
    auto x2 = s1.insert(10);
    cout<<"x1 frist:"<<*x1.first<<" x1 second:"<<x1.second<<endl;
    cout<<"x2 frist:"<<*x2.first<<" x2 second:"<<x2.second<<endl; //插入失败
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);
    printSet(s1);
    //multiset
    printf("multiset------------------\n");
    multiset<int> ms;
    ms.insert(10);
    ms.insert(10);
    ms.insert(130);
    auto ite_me = ms.begin();
    for(int i = 0; i < ms.size(); i++){
        cout<<*ite_me++<<endl;
    }

//拷贝构造
    set<int> s2(s1);
    printSet(s2);
    s2.erase(++(s2.begin()));
    printSet(s2);

    auto ite = s2.find(30);
    cout<<*ite<<endl;
}
int main() {
    /*
     * set不允许容器中有重复的元素
        multiset允许容器中有重复的元素
        size(); //返回容器中元素的数目
        empty(); //判断容器是否为空
        swap(st); //交换两个集合容器
        insert(elem); //在容器中插入元素。
        clear(); //清除所有元素
        erase(pos); //删除pos迭代器所指的元素，返回下一个元素的迭代
        器。
        erase(beg, end); //删除区间[beg,end)的所有元素 ，返回下一个元素的迭
        代器。
        erase(elem); //删除容器中值为elem的元素。
        find(key); //查找key是否存在,若存在，返回该键的元素的迭代
        器；若不存在，返回set.end();
        count(key); //统计key的元素个数
        ====================================
        set不可以插入重复数据，而multiset可以
        set插入数据的同时会返回插入结果，表示插入是否成功
        multiset不会检测数据，因此可以插入重复数据
     */
    test01();
    return 0;
}
