#include <iostream>
#include "vector"
using namespace std;
/*
 * 有 n 个城市通过一些航班连接。给你一个数组 flights ，其中 flights[i] = [fromi, toi, pricei] ，表示该航班都从城市 fromi 开始，以价格 pricei 抵达 toi。
现在给定所有的城市和航班，以及出发城市 src 和目的地 dst，你的任务是找到出一条最多经过 k 站中转的路线，使得从 src 到 dst 的 价格最便宜 ，并返回该价格。 如果不存在这样的路线，则输出 -1。

链接：https://leetcode.cn/problems/cheapest-flights-within-k-stops
*/
class Solution {
public:
    //图论中带边数限制的最短路 Bellman—Ford算法
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp(k+2,vector<int>(n,INT_MAX/2));
        //dp[t][j]表示遍历t条边到达目的地j的最短路径
        dp[0][src]=0;
        int res=INT_MAX/2;
        for(int t=1;t<=k+1;t++){
            for(auto& flight:flights){
                int i=flight[0];
                int j=flight[1];
                int dis=flight[2];
                dp[t][j]=min(dp[t][j],dp[t-1][i]+dis);
                if(j==dst)
                    res=min(res,dp[t][j]);
            }
        }
        return res==INT_MAX/2?-1:res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    int n = 3;
    vector<vector<int>> flights(n,vector<int>(3));
    vector<int> nums1;
    nums1.push_back(0);nums1.push_back(1);nums1.push_back(100);
    vector<int> nums2;
    nums2.push_back(1);nums2.push_back(2);nums2.push_back(100);
    vector<int> nums3;
    nums3.push_back(0);nums3.push_back(2);nums3.push_back(500);
    flights.push_back(nums1);flights.push_back(nums2);flights.push_back(nums3);
    for(auto j:flights){
        for(auto k : j){
            cout<<k<<endl;
        }
    }
    int src = 0;int dst = 2; int k=1;
    Solution a; int ans;
    ans = a.findCheapestPrice(n,flights,src,dst,k);
    cout<<ans<<endl;
    return 0;
}
