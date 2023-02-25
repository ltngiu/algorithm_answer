//冒泡排序
#include<stdio.h>
#include<vector>
#include<iostream>
void swap(int &a, int &b);
void bubble_sort(std::vector<int>::iterator pa, std::size_t n);
int main()
{
    std::vector<int> arra;
    std::cout << "请输入整数序列：" << std::endl;
    int a;
    while(std::cin >> a) arra.push_back(a);
    for(auto b:arra) std::cout << b << " ";
    std::cout << std::endl;
    auto n = arra.end() - arra.begin();
    bubble_sort(arra.begin(), n);
    for(auto e: arra) std::cout << e << " ";
    return 0;
    
}
void swap(int &a, int &b)
{
    int key = a;
    a = b;
    b = key;
}
void bubble_sort(std::vector<int>::iterator pa, std::size_t n)
{
    if(n > 1)
    {
        std::size_t i = 0;
        for( ; i != n; i++)
        {
            
            for(auto j = n - 1; j != i; j--)
                {
                    if(*(pa + j) < *(pa + j - 1) )
                    swap(*(pa + j), *(pa + j - 1));
                }
        }
    }
}