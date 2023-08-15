#include<iostream>
#include<cstdio>
#include<numeric>
#include<vector>
int GIVE_LINES(int p[], int j, std::vector<int> &A){
    int k, i = p[j];
    if(i == 1) k = 1;
    else k = GIVE_LINES(p, i - 1, A) + 1; 
    std::cout << "行号：" << k << " ";
    std::cout << std::endl;
    for(int t = i; t <= j; ++t)
        std::cout << A[t] << " ";
    std::cout << std::endl;
    return k;
}
int main(){
    int M = 50;
    std::vector<int> sequence = {0, 5, 10, 3, 7, 4, 8, 6, 12, 3, 2, 7, 5, 4, 4, 2, 3, 8, 9, 11};
    //代表输入单词的长度，为了计数方便，第一个单词设为0，实际的第一个单词长度为5
    // std::cout << sequence.size(); 样例序列的长度为19
    std::vector<std::vector<int>> e(sequence.size(), std::vector<int>(sequence.size()));
    std::vector<std::vector<int>> lc(sequence.size(), std::vector<int>(sequence.size()));
    for(int i = 1; i < sequence.size(); ++i){
        e[i][i] = M - sequence[i];

        for(int j = i + 1; j < sequence.size(); ++j){
            e[i][j] = e[i][j - 1] - sequence[j] - 1;
        }
    }
    for(int i = 1; i < sequence.size(); ++i){
        for(int j = i; j < sequence.size(); ++j){
            if(e[i][j] < 0) lc[i][j] = INT_MAX;
            else if(j == sequence.size() - 1 && e[i][j] >= 0)
                lc[i][j] = 0;
            else lc[i][j] = e[i][j] * e[i][j] * e[i][j];
        }
    }
    int c[sequence.size()];
    int p[sequence.size()];
    c[0] = 0;
    for(int j = 1; j < sequence.size(); ++j){
        c[j] = INT_MAX;
        for(int i = 1; i <= j; ++i){
            if(c[i - 1] != INT_MAX && lc[i][j] != INT_MAX && (c[i - 1] + lc[i][j] < c[j])){
                c[j] = c[i - 1] + lc[i][j];
                p[j] = i;
            }
        }
    }
    GIVE_LINES(p, sequence.size() - 1, sequence);


    return 0;
    
}