#ifndef touzi
#define touzi 
#include<iostream>
#include<vector>
#include<random>
#include<algorithm>
#include<limits.h>
std::vector<std::vector<std::vector<double>>> touzi_guihua(std::vector<std::vector<double>> &reward, double benjin, std::vector<double> &chang){
    int n = reward[0].size(), m = reward.size();
    std::vector<std::vector<double>> d(m, std::vector<double>(n)), p(m, std::vector<double>(n, 0));
    for(int i = 1; i < n; ++i) d[1][i] = benjin * reward[1][i];
    for(int i = 2; i < m; ++i){
        for(int j = 1; j < n; ++j){
            d[i][j] = INT_MIN;
            for(int k = 1; k < n; ++k){
                double temp = d[i-1][k] * chang[bool(k-j)] * reward[i][j];
                if(temp > d[i][j]){
                    d[i][j] = temp;
                    p[i][j] = k;
                }
            }
        }
    }
    std::vector<std::vector<std::vector<double>>> res;
    d[0][0] = *(std::max_element(d[d.size()-1].begin()+1, d[d.size()-1].end()));
    p[0][0] = std::max_element(d[d.size()-1].begin()+1, d[d.size()-1].end()) - d[d.size()-1].begin();
    res.push_back(d);
    res.push_back(p);
    return res;
}
void print_res(std::vector<std::vector<double>> &d, std::vector<std::vector<double>> &p, int m, int n, int c){
    if(m - 2 > 0){
        print_res(d, p, m - 1, p[m-1][n], c);
    }
    std::cout << "第" << m - 1 << "年的投资方案为：" << n << "; 收益为：" << d[m-1][n] << std::endl;
}
#endif