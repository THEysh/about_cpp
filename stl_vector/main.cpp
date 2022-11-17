#include <vector>
#include "algorithm"
#include "iostream"
using namespace std;

void printVector(vector<int>& v) {
    for(vector<int>::iterator ite = v.begin(); ite != v.end();
         ite++) {
        cout << *ite << " ";
    }
    cout << endl;
}
void showfun(int val){
    cout<<"for_each:"<<val<<endl;
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
    for_each(v1.begin(), v1.end(), showfun);
}
int main() {
    /*vector<T> v; //采用模板实现类实现，默认构造函数
    vector(v.begin(), v.end()); //将v[begin(), end())区间中的元素拷贝给本身。
    vector(n, elem); //构造函数将n个elem拷贝给本身。
    vector(const vector &vec); //拷贝构造函数。*/
    test01();
    return 0;
}