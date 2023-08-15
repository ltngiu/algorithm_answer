#ifndef event_dp
#define event_dp
#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
std::vector<std::vector<std::vector<int>>> event_dynamic_program(std::vector<int> &s, std::vector<int> &f){
    // std::vector<std::vector<int>> d(s.size(), std::vector<int>(*(std::max_element(f.begin(), f.end()))));
    // std::vector<std::vector<int>> c(s.size(), std::vector<int>(*(std::max_element(f.begin(), f.end()))));
    std::vector<std::vector<int>> d(s.size(), std::vector<int>(s.size()));
    std::vector<std::vector<int>> c(s.size(), std::vector<int>(s.size()));
    for(int i = 0; i < s.size()-1 ; ++i){
        c[i][i+1] = 0;
        d[i][i+1] = -1;
    }
    for(int l = 2; l < s.size(); ++l){
        for(int i = 0; i + l < s.size(); ++i){
            int j = i + l;
            d[i][j] = -1;
            c[i][j] = 0;
            if(f[i] < s[j]){
                for(int k = i + 1; k < j; ++k){
                    if(s[k] >= f[i] && f[k] <= s[j]){
                        int temp = c[i][k] + c[k][j] + 1;
                        if(temp > c[i][j]){
                            c[i][j] = temp;
                            d[i][j] = k;
                        }
                    }
                }
            }
        }
    }
    
    std::vector<std::vector<std::vector<int>>> res;
    res.push_back(c);
    res.push_back(d);
    return res;
}
void print_res(std::vector<std::vector<int>> &d, int i, int j){
    if(d[i][j] == -1) return;
    if(d[i][j] != i) print_res(d, i, d[i][j]);
    std::cout << d[i][j] << " ";
    
    if(d[i][j] != j) print_res(d, d[i][j], j);

}
#endif