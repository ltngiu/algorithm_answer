#include<string>
#include<cstdio>
#include<iostream>
#include<algorithm>
int main(){
    std::cout<< "请输入需要测试的字符串：" << std::endl;
    std::string words;
    std::cin >> words;
    int A[words.size()][words.size()];
    for(int i = 0; i < words.size() - 1; ++i){
        A[i][i] = 1;
        if(words[i] == words[i + 1]) A[i][i+1] = 2;
        else A[i][i+1] = 1;
    }
    A[words.size() - 1][words.size() - 1] = 1;
    int counter, beg, ed;
    counter = 0;
    beg = 0;
    ed = 0;
    for(int j = 2; j < words.size(); ++j)
        for(int i = 0; i + j < words.size(); ++i)     
        {
            if(words[i + j] == words[i] && A[i+1][i + j-1] == j-1) A[i][i+j] = 2 + A[i+1][i+j-1];
            else A[i][i + j] = std::max(A[i+1][i+j], A[i][i+j-1]);
            if(A[i][i+j] > counter){
                counter = A[i][i+j];
                beg = i;
                ed = j + i;
            }
        }
    std::cout << "最长回文子串的长度为:" << A[0][words.size() - 1] << std::endl;
    std::cout << beg << " " << ed << std::endl;
    for(int j = beg; j <= ed; ++j)
        std::cout << words[j]; 
    return 0;
}