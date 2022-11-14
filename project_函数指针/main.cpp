// arfupt.cpp -- an array of function pointers
#include <iostream>
// various notations, same signatures
const double * f1(const double ar[], int n);
const double * f2(const double [], int);
const double * f3(const double *, int);
void testpf_fun(int number,auto pf); // 函数指针传入函数
using namespace std;
int main()
{
    // 关键看auto的使用
    using namespace std;
    double av[3] = {1112.3, 1542.6, 2227.9};

    // pointer to a function
    const double *(*p1)(const double *, int) = f1;
    auto p2 = f2;  // C++0x automatic type deduction
    // pre-C++0x can use the following code instead
    // const double *(*p2)(const double *, int) = f2;
    cout << "Using pointers to functions:\n";
    cout << " Address  Value\n";
    cout <<  (*p1)(av,3) << ": " << *(*p1)(av,3) << endl;
    cout << p2(av,3) << ": " << *p2(av,3) << endl;

    const double *(*pa[3])(const double *, int) = {f1,f2,f3};
    auto pb = pa;
    cout << "\nUsing an array of pointers to functions:\n";
    cout << " Address  Value\n";
    for (int i = 0; i < 3; i++)
        cout << pa[i](av,3) << ": " << *pa[i](av,3) << endl;
    cout << "\nUsing a pointer to a pointer to a function:\n";
    cout << " Address  Value\n";
    for (int i = 0; i < 3; i++)
        cout << pb[i](av,3) << ": " << *pb[i](av,3) << endl;


    cout << "\nUsing pointers to an array of pointers:\n";
    cout << " Address  Value\n";
    // easy way to declare pc
    auto pc = &pa;
    cout << (*pc)[0](av,3) << ": " << *(*pc)[0](av,3) << endl;
    const double *(*(*pd)[3])(const double *, int) = &pa;
    const double * pdb = (*pd)[1](av,3);
    cout << pdb << ": " << *pdb << endl;
    cout << (*(*pd)[2])(av,3) << ": " << *(*(*pd)[2])(av,3) << endl;

    testpf_fun(30,p1);
    testpf_fun(30,p2);
    return 0;
}

// some rather dull functions

const double * f1(const double * ar, int n)
{
    return ar;
}
const double * f2(const double ar[], int n)
{
    return ar+1;
}
const double * f3(const double ar[], int n)
{
    return ar+2;
}
void testpf_fun(int number,auto pf){
    double av[3] = {1112.3, 1542.6, 2227.9};
    cout<<"将函数指针传入了函数"<<endl;
    cout<<"pf(av,3),*pf(av,3)="<<pf(av,3)<<","<<*pf(av,3)<< endl;
}