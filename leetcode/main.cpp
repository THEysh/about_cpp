#include <iostream>
#include "vector"
using namespace std;
int main() {
    vector<int> data;
    for (int i=0;i<5;i++){
        data.push_back(i+1);
    }
    for(int k :data){
        cout<<k<<endl;
    }
    vector<int> nums;
    for (int i=0;i<5;i++){
        nums.push_back(i+1);
    }
    for(int k :nums){
        cout<<k<<endl;
    }

    vector<vector<int>> data2(4,vector<int>(3,99));
    for (auto i : data2){
        for(int k :i){
            cout<<k<<endl;
        }
    }
    for (int i=0;i<4;i++){
        for(int k =0;k<3;k++){
            data2[i][k] = i*k+1;
        }
    }
    for (auto i : data2){
        for(int k :i){
            cout<<k<<endl;
        }
    }

    return 0;
}
