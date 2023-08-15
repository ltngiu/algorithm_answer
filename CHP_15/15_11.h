#ifndef Rinky_Dink
#define Rinky_Dink
#include<iostream>
#include<cstdio>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<random>
int h(int j){
    int s = 10;
    return s * j;
}
std::vector<std::vector<int>> store_plan(std::vector<int> &D, int m, int c){
    int total_need = std::accumulate(D.begin()+1, D.end(), 0);
    std::vector<int> l(D.size());
    l[1] = D[1];
    for(int i = 2; i < D.size(); ++i){
        l[i] = l[i-1] + D[i];
    }
    std::vector<std::vector<int>> cost(D.size(), std::vector<int>(total_need+1 )), dp(D.size(), std::vector<int>(total_need+1 ));
    for(int i = 1; i < D.size(); ++i){
        for(int j = l[i]; j <= l[D.size() - 1]; ++j){
            if(i == 1){
                cost[i][j] = h(j - l[1]);
                if(j > m){
                    cost[i][j] = cost[i][j] + c*(j - m);
                }
            }
            else{
                cost[i][j] = INT_MAX;
                for(int k = 0; k <= j - l[i-1]; ++k){
                    int t = cost[i-1][j-k] + h(j-l[i]);
                    if(k > m){
                        t = t + c*(k-m);
                    }
                    if(t < cost[i][j]){
                        cost[i][j] = t;
                        dp[i][j] = k;
                    }
                }
            }
        }
    }
    return dp;
}
void print_res(std::vector<std::vector<int>> &dp, int i, int j){
    if(i > 0){
        print_res(dp, i-1, j-dp[i][j]);
        std::cout << dp[i][j] << " ";
    }
}
#endif