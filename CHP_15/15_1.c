#include "15_1.h"
std::vector<std::vector<double>> GPT(int n){
    
    std::vector<std::vector<double>> GRAPHT(n, std::vector<double>(n, INT_MAX));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            GRAPHT[i][j] = 0;
        }
        
    }
    std::cout << "请按照“节点1、节点2、权重”的顺序，输入边及其权重" << std::endl;
    int v1, v2;
    double weight;
    while(std::cin >> v1 >> v2 >> weight){
        GRAPHT[v1][v2] = weight;
    }
    return GRAPHT;
}

std::vector<std::vector<double>> longest(std::vector<std::vector<double>> &A, std::vector<std::vector<double>> weight, int beg, int term){
    weight(n, std::vector<double>(n, INT_MIN));
    for(int i = 0; i < n; ++i)  weight[i][i] = 0;
    std::vector<std::vector<double>> p(n, std::vector<double>(n));
    for(int l)
    
}