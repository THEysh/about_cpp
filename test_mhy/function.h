//
// Created by top on 2022-12-06.
//

#ifndef MYPROJECT_MHY_FUNCTION_H

#include <vector>
#include "string"
using namespace std;
class Role{

public:
    string name;
    int start;
    Role(string name,int start);
    void show();
};

class MHY{

public:
    vector<Role> v5; //放5星
    vector<Role> v4; //放4星
    MHY();
    void add5(Role r);
    void add4(Role r);
    void show_v();
};

#endif //MYPROJECT_MHY_FUNCTION_H
