#include<stdio.h>
#include<vector>
#include<iostream>
#include<limits.h>
void Merge(std::vector<int>::iterator pa, std::size_t p, std::size_t q, std::size_t n);
void Merge_sort(std::vector<int>::iterator pa, std::size_t p, std::size_t n);
int main()
{
    std::cout << "请输入一系列待排序的整数，以ctr+z结束："<< std::endl;
    std::vector<int> arra;
    int a;
    while(std::cin>>a)
    {
        arra.push_back(a);
    }
    auto n = arra.end() - arra.begin();
    for(auto key: arra)
    {std::cout << key << " ";}
    std::cout << std::endl;
    Merge_sort(arra.begin(), 0, n);
    for(auto key : arra)
    {std::cout << key << " ";}
    std::cout << std::endl;
    return 0;
}
void Merge(std::vector<int>::iterator pa, std::size_t p, std::size_t q, std::size_t n)
{
    std::vector<int> L;
    std::vector<int> R;
    for(auto pb = pa + p; pb != pa + q; pb++)
    {
        L.push_back(*pb);
    }
    L.push_back(INT_MAX);
    for(auto pb = pa + q; pb != pa + n; pb++)
    {
        R.push_back(*pb);
    }
    R.push_back(INT_MAX);
    int i = 0, j = 0;
    for(auto pb = pa + p; pb != pa + n; pb++)
    {
        if(L[i] <= R[j])
        {
            *pb = L[i];
            i++;
        }
        else
        {
            *pb = R[j];
            j++;
        }
    }
}
void Merge_sort(std::vector<int>::iterator pa, std::size_t p, std::size_t n)
{
    std::size_t m = std::size_t((n + p) / 2);
    if(p < m)
    //在C++的实现中，如果使用p < n的说明，会导致中间出现漏洞，如果使用m + 1，会出现死循环。
    {
    Merge_sort(pa, p, m);
    Merge_sort(pa, m, n);
    Merge(pa, p, m, n);
    }
}




