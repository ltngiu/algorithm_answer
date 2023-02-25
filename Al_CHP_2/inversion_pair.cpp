//算法导论中文版P24-2-4，逆序对问题。
#include<stdio.h>
#include<vector>
#include<iostream>
#include<limits.h>
int Merge(std::vector<int>::iterator pa, std::size_t p, std::size_t q, std::size_t n);
int Merge_sort(std::vector<int>::iterator pa, std::size_t p, std::size_t n);
int main()
{
    std::cout << "请输入一系列整数，以ctr+z结束："<< std::endl;
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
    int counter = Merge_sort(arra.begin(), 0, n);
    for(auto key : arra)
    {std::cout << key << " ";}
    std::cout << std::endl;
    std::cout << counter;
    return 0;
}
int Merge(std::vector<int>::iterator pa, std::size_t p, std::size_t q, std::size_t n)
{
    std::vector<int> L;
    std::vector<int> R;
    int count = 0;
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
            count += (L.end() - L.begin() - i - 1);
            j++;
        }
    }
    return count;
}
int Merge_sort(std::vector<int>::iterator pa, std::size_t p, std::size_t n)
{
    std::size_t m = std::size_t((n + p) / 2);
    std::size_t count = 0;
    if(p < m)
    {
    count = Merge_sort(pa, p, m) +  Merge_sort(pa, m, n) + Merge(pa, p, m, n);
    }
    return count;
}




