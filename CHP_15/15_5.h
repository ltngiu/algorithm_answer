#ifndef alg15_5
#define alg15_5
#include<cstdio>
#include<iostream>
#include<limits.h>
#include<string>
#include<vector>
const int cpy = 1;   //复制的代价
const int rep = 2;   //替换的代价
const int del = 3;   //删除的代价
const int ins = 4;   //插入的代价
const int twd = 5;   //旋转的代价
const int kil = 6;   //终止的代价
                     //成本列表

std::vector<std::vector<std::vector<int>>> Edit_dist(std::string &s1, std::string &s2, std::vector<int> &cost){
    int m = s1.size(), n = s2.size();
    std::vector<std::vector<int>> d(m + 1, std::vector<int>(n + 1, INT_MAX));
    std::vector<std::vector<int>> option(m + 1, std::vector<int>(n + 1, 0));
    
    int p;
    //p代表了使用删除操作的位置
    d[0][0] = 0;
    option[0][0] = 0;
    //对于长度为0的两个字符串，设定编辑距离为0
    for(int j = 1; j <= n; ++j)  {d[0][j] = j * cost[4]; option[0][j] = 4;}
    //对于长度为0的原始字符(s1)和长度为n的目标字符(s2)，应当一直使用插入
    for(int i = 1; i <= m; ++i)  {
    //对于长度为0的目标字符(s2)，应当一直使用删除操作
        d[i][0] = i * cost[3]; 
        option[i][0] = 3;
        // if(n == 0 && cost[6] < d[i][0]) {
        // //当直接使用kill操作删除整个字符串的代价更小时，应当使用kill操作删除整个字符串
        // d[i][0] = cost[6];
        // option[i][0] = 6;
        // p = 0;
        // }
    }
    //dst表示在进行了某个操作后的总编辑距离
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            std::vector<int> dst(7, INT_MAX);
            if(s1[i - 1] == s2[j - 1]) {dst[1] = d[i-1][j-1] + cost[1];}   //使用复制操作后的代价
            else {dst[2] = cost[2] + d[i-1][j-1];} //使用替换操作后的代价
            dst[3] = cost[3] + d[i-1][j];        //使用删除操作的代价
            dst[4] = cost[4] + d[i][j-1];        //使用插入操作的代价
            if(i >= 2 && j >= 2 && s1[i-2] == s2[j-1] && s1[i-1] == s2[j-2]){
                dst[5] = cost[5] + d[i-2][j-2];  //使用旋转操作后的代价
            }
            
            d[i][j] = INT_MAX;                  //得到将s1[0:i-1]转换为s2[0:j-1]的代价
            for(int k = 1; k <= 6; ++k){
                if(dst[k] < d[i][j]){
                    // std::cout << k << std::endl;
                    d[i][j] = dst[k];
                    option[i][j] = k;
                }
            }
                
        }
        // std::cout << std::endl;
    }
    //使用删除操作后的代价，删除操作只有当i和j都达到了各自字符串的末尾时才会有效
    for(int i = 1; i < m; ++i){
        std::vector<int> dst(7, INT_MAX);
        dst[6] = d[i][n] + cost[6];
        if(dst[6] < d[m][n]){
            p = i;
            d[m][n] = dst[6];
            option[m][n] = 6;
            
        }
    }
    std::vector<std::vector<std::vector<int>>> res;
    d[0][0] = p;
    
    res.push_back(d);
    res.push_back(option);
    return res;//res[0][0][0]代表了删除操作的位置
}

int print_operator_chain(std::vector<std::vector<int>> &op, int p, int i, int j){
    if(op[i][j] == 0) return 0;
    else if(op[i][j] == 1){
        print_operator_chain(op, p, i - 1, j - 1);
        std::cout << i << "到" << j << "的复制操作" << std::endl;
    }
    else if(op[i][j] == 2){
        print_operator_chain(op, p, i - 1, j - 1);
        std::cout << i << "到" << j << "的替换操作，代价为：" << 2 << std::endl;
    }
    else if(op[i][j] == 3){
        print_operator_chain(op, p, i - 1, j);
        std::cout << "删除第" << i << "个元素，代价为" << 3 << std::endl;
    }
    else if(op[i][j] == 4){
        print_operator_chain(op, p, i, j - 1);
        std::cout << "插入目标字符串的第" << j << "个元素，代价为" << 4 << std::endl;
    }
    else if(op[i][j] == 5){
        print_operator_chain(op, p, i - 2, j - 2);
        std::cout << "在第" << i << "和第" << j << "个元素上进行旋转操作，代价为" << 5 << std::endl;
    }
    else{
        print_operator_chain(op, p, p, j);
        std::cout << "从" << p << "开始的删除操作，代价为" << 6 << std::endl;
    }
    return 0;
}

#endif