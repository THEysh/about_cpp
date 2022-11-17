#include <list>
#include "iostream"
using namespace std;
void printList(const list<int>& L) {
    for (auto it = L.begin(); it !=L.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
void test01()
{
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    printList(L1);
    list<int>L2(L1.begin(),L1.end());
    printList(L2);
    list<int>L3(L2);
    printList(L3);
    list<int>L4(10, 1000);
    printList(L4);
    printf("------------------------------------------\n");
    if (L1.empty())
    {
        cout << "L1为空" << endl;
    }
    else
    {
        cout << "L1不为空" << endl;
        cout << "L1的大小为： " << L1.size() << endl;
    }
//重新指定大小
    L1.resize(10);
    printList(L1);
    L1.resize(3);
    printList(L1);
    //尾删
    L1.pop_back();
    printList(L1);
    //头删
    L1.pop_front();
    printList(L1);
    //插入
    auto it = L1.begin();
    L1.insert(++it, 1000);
    printList(L1);
    //删除
    it = L1.begin();
    L1.erase(++it);
    printList(L1);
    //移除
    L1.push_back(10000);
    L1.push_back(10000);
    L1.push_back(10000);
    printList(L1);
    L1.remove(10000);
    printList(L1);
    printf("======================================================\n");
    L1.push_back(120);
    L1.push_back(10);
    L1.push_back(240);
    L1.push_back(43);
    printf("原始数据：");
    printList(L1);
    L1.sort();
    printList(L1);
    L1.reverse();
    printList(L1);
    auto pt =L1.begin();
    cout <<*(++pt)<<endl; //只能 ++ 不能 + 1;
}
int main() {
    /*push_back(elem);//在容器尾部加入一个元素
    pop_back();//删除容器中最后一个元素
    push_front(elem);//在容器开头插入一个元素
    pop_front();//从容器开头移除第一个元素
    insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
    insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
    insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
    clear();//移除容器的所有数据
    erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
    erase(pos);//删除pos位置的数据，返回下一个数据的位置。
    remove(elem);//删除容器中所有与elem值匹配的元素。*/
    test01();
    return 0;
}