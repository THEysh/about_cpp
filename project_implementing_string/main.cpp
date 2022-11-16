// sayings2.cpp -- using pointers to objects
// compile with string1.cpp
#include <iostream>
#include <cstdlib>      // (or stdlib.h) for rand(), srand()
#include <ctime>        // (or time.h) for time()
#include "String.h"
const int ArSize = 10;
const int MaxLen = 81;
int main()
{
    using namespace std;
    String name1="ABC";
    char chardata[3+1]="ysh";
    String name2 = chardata;
    name1 = name2;
    String name3 = "chardata";
    cout<<"name1:"<<name1<<endl;
    cout<<"how many:"<<name2.HowMany()<<endl;
    cout<<"name1[4]:"<<name1[4]<<endl;
    cout<<(name3<name2)<<endl;
    return 0;
}
