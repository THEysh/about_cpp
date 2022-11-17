#include <iostream>
#include <map>
using namespace std;
void printMap(map<int,int>&m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end();it++){
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
    cout << endl;
}
void test01()
{
    map<int,int>m; //默认构造
    m.insert(pair<int, int>(1, 121));
    m.insert(pair<int, int>(2, 23));
    m.insert(pair<int, int>(3, 31));
    printMap(m);
    map<int, int>m2(m); //拷贝构造
    printMap(m2);
    map<int, int>m3;
    m3 = m2; //赋值
    printMap(m3);
    //插入

    //第一种插入方式
    m.insert(pair<int, int>(11, 10));
    //第二种插入方式
    m.insert(make_pair(22, 20));
    //第三种插入方式
    m.insert(map<int, int>::value_type(33, 30));
    //第四种插入方式
    m[99] = 40;
    printMap(m);
    //删除
    m.erase(m.begin());
    printMap(m);
    m.erase(2);
    printMap(m);
    auto ite_99 = m.find(99);
    cout<<"value:"<<ite_99->second<<endl;
}
int main() {
    /*
     * map中所有元素都是pair
    pair中第一个元素为key（键值），起到索引作用，第二个元素为value（实值）
    所有元素都会根据元素的键值自动排序
    本质：
    map/multimap属于关联式容器，底层结构是用二叉树实现。
     map不允许容器中有重复key值元素
    multimap允许容器中有重复key值元素
     size(); //返回容器中元素的数目
    empty(); //判断容器是否为空
    swap(st); //交换两个集合容器
     insert(elem); //在容器中插入元素。
    clear(); //清除所有元素
    erase(pos); //删除pos迭代器所指的元素，返回下一个元素的迭代器。
     erase(beg, end); //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
    erase(key); //删除容器中值为key的元素。
     find(key); //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
    count(key); //统计key的元素个数*/
    test01();
    return 0;
}
