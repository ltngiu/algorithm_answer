#ifndef DNA_ALIGN
#define DNA_ALIGN
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<limits.h>
//DNA对齐问题转化为编辑距离问题：
//如果x'[j] == y'[j]，复制操作，代价为1
//如果x'[j] != y'[j]且都不是空格, 替换操作，代价为-1
//如果x'[j] == 空格, 相当于插入操作，代价为-2
//如果y'[j] == 空格，相当于删除操作，代价为-2
std::vector<std::vector<std::vector<int>>> DNAALIGN(std::string& s1, std::string& s2, std::vector<int> & cost);
std::vector<std::vector<std::vector<int>>> DNAALIGN(std::string& s1, std::string& s2, std::vector<int> & cost){
    int m = s1.size(), n = s2.size();
    std::vector<std::vector<int>> d(m + 1, std::vector<int>(n+1));
    std::vector<std::vector<int>> op(m + 1, std::vector<int>(n+1));
    d[0][0] = 0;
    op[0][0] = 0;
    for(int j = 1; j <= m; ++j){
        d[j][0] = j * cost[4];
        op[j][0] = 4;
    }
    for(int i = 1; i <= n; ++i){
        d[0][i] = i * cost[3];
        op[0][i] = 3;
    }
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            std::vector<int> dst(5, INT_MIN);
            if(s1[i-1] == s2[j-1]){
                dst[1] = cost[1] + d[i-1][j-1];
            }
            else if(s1[i-1] != s2[j-1]){
                dst[2] = cost[2] + d[i-1][j-1];
            }
            dst[3] = cost[3] + d[i][j-1];
            dst[4] = cost[4] + d[i-1][j];
            d[i][j] = INT_MIN;
            for(int k = 1; k <= 4; ++k){
                if(dst[k] > d[i][j]){
                    d[i][j] = dst[k];
                    op[i][j] = k;
                }
            }
        }
    }
    std::vector<std::vector<std::vector<int>>> res;
    res.push_back(d);
    res.push_back(op);
    return res;
}
void print_first_chain(std::string &s1, std::vector<std::vector<int>> &op, int i, int j){
    if(op[i][j] != 0){
        if(op[i][j] == 1 || op[i][j] == 2){
            print_first_chain(s1, op, i - 1, j - 1);
            std::cout << s1[i-1];
        }
        else if(op[i][j] == 3){
            print_first_chain(s1, op, i, j-1);
            std::cout << " ";
        }
        else{
            print_first_chain(s1, op, i-1, j);
            std::cout << s1[i-1];
        }
    }
}
void print_second_chain(std::string &s2, std::vector<std::vector<int>> &op, int i, int j){
    if(op[i][j] != 0){
        if(op[i][j] == 1 || op[i][j] == 2){
            print_second_chain(s2, op, i - 1, j - 1);
            std::cout << s2[j-1];
        }
        else if(op[i][j] == 3){
            print_second_chain(s2, op, i, j-1);
            std::cout << s2[j-1];
        }
        else{
            print_second_chain(s2, op, i-1, j);
            std::cout << " "; 
        }
    }
}
#endif