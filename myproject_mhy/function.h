//
// Created by top on 2022-12-06.
//

#ifndef MYPROJECT_MHY_FUNCTION_H
#define MYPROJECT_MHY_FUNCTION_H
#include <vector>
#include "algorithm"
#include "string"
using namespace std;
class Role{
    string name;
    int start;
public:
    Role(string name,int start);
    void show();
};

class MHY{
    vector<Role> v; //无参构造
public:
    MHY();
    void add(Role r);
    void show_v();
};

#endif //MYPROJECT_MHY_FUNCTION_H
