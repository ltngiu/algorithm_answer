#include <stdio.h>
#include <vector>
#include <iostream>
int main()
{
    std::vector<int> arra;
    int arg;
    std::cout << "请输入若干个待排序数字："<< std::endl;
    while(std::cin >> arg)
    {
        arra.push_back(arg);
    }
    for(std::size_t j = 1; j != arra.size(); j++)
    {
        int key = arra[j];
        int i = j - 1;
        while(i >= 0 && arra[i] > key)
        {
            arra[i + 1] = arra[i];
            i--;
        }
        arra[i + 1] = key;
    }
    for(auto et: arra)
    {
        std::cout << et << " " ;
    }
    std::cout << std::endl;
    return 0;

}