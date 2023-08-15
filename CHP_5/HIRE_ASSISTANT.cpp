#include<cstdio>
#include<iostream>
#include<vector>
//这是第65页的HIRE_ASSISTANT伪代码的C++实现
int main()
{
    int best = INT_MIN; 
    int cost = 0;
    int temp;
    std::vector<int> cand;
    std::cout << "请输入每个候选人的分数：" << std::endl;
    while(std::cin >> temp)
    {
        cand.push_back(temp);
    }
    for(auto key = cand.begin(); key != cand.end(); ++key)
    {
        if( *key > best)
        {
            best = *key;
            ++cost;
        }
        else 
            continue;
    }
    std::cout << "选出最好的候选人花费的成本是：" << cost << "。他的分数是：" << best;
    return 0;
}