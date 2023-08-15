#ifndef sign_ball
#define sign_ball
#include<iostream>
#include<random>
#include<vector>
#include<limits.h>
std::vector<std::vector<std::vector<int>>> dpgram(std::vector<std::vector<int>> &price, std::vector<std::vector<int>> &score, int X){
    std::vector<std::vector<int>> d(price[0].size(), std::vector<int>(X+1)), p(price[0].size(), std::vector<int>(X+1));
    for(int i = 0; i < X+1; ++i){
        d[1][i] = 0; p[1][i] = 0;
        for(int j = 1; j < price.size(); ++j){
            if(price[j][1] <= X){
                if(score[j][1] > d[1][X]){
                    d[1][X] = score[j][1];
                    p[1][X] = j;
                }
            }
        }
    }
    for(int i = 2; i < price[0].size(); ++i){
        for(int j = 0; j < X+1; ++j){
            d[i][j] = d[i-1][j];
            p[i][j] = 0;
            for(int k = 1; k < price.size(); ++k){
                if(price[k][i] <= j){
                    int t = score[k][i] + d[i-1][j-price[k][i]];
                    if(t > d[i][j]){
                        d[i][j] = t;
                        p[i][j] = k;
                    }
                }
            }
        }
    }
    std::vector<std::vector<std::vector<int>>> res;
    res.push_back(d);
    res.push_back(p);
    return res;
}
#endif