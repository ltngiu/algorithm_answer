#ifndef string_sp
#define string_sp
#include<vector>
#include<cstdio>
#include<limits.h>
#include<algorithm>
#include<iostream>
#include<numeric>
std::vector<std::vector<std::vector<int>>> string_spl(std::vector<int> &str){
    int summ = std::accumulate(str.begin(), str.end(), 0);
    int n = str.size();
    std::vector<std::vector<int>> d(n, std::vector<int>(n, 0)), c(n-1, std::vector<int>(n-1, 0));
    for(int i = 1; i < n-1; ++i){
        d[i][i] = str[i+1] - str[i-1];
    }
    
        for(int l = 1; l < n - 1 ; ++l){
        for(int i = 1; i + l < n - 1; ++i){
            int j = i + l;
            d[i][j] = INT_MAX;
            for(int k = i; k <= j; ++k){
                int temp = str[j+1] - str[i-1] + d[i][k - 1] + d[k + 1][j];
                if(temp < d[i][j]){
                    d[i][j] = temp;
                    c[i][j] = k;
                }
            }
        }
    }
    std::vector<std::vector<std::vector<int>>> res;
    res.push_back(d);
    res.push_back(c);
    return res;
}
void print_res(std::vector<std::vector<int>> & c, int i, int j){
    //输出结果，首先输出第一个选择的切割点，然后输出该切割点左边的所有切割点的选择顺序，然后输出右边的
    if(i == j){std::cout << i << " ";}
    else if(i != 0 && j != 0){
        std::cout << c[i][j] << " ";
        if(c[i][j] - 1 >= i){
            print_res(c, i, c[i][j] - 1);
        }
        if(c[i][j] + 1 <= j){
            print_res(c, c[i][j] + 1, j);
        }
    }
}
#endif