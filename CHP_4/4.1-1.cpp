#include<stdio.h>
#include<iostream>
#include<tuple>
#include<limits.h>
using std::tuple;
tuple<int, int, int> search(int a[], int low, int high);
int main()
{
    int a[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    auto ret = search(a, 0, sizeof(a)/sizeof(a[0]));
    std::cout << std::get<0>(ret)<< " " << std::get<1>(ret) << " " << std::get<2>(ret) << std::endl;
    return 0;
}
tuple<int, int, int> search(int a[], int low, int high)
{
    int max_left = 0, max_right = 0, sum_max = INT_MIN;
    for(int i = low; i != high; i++)
    {
        int sum = 0;
        for(int j = i; j != high; j++)
        {
            sum += a[j];
            if(sum >= sum_max)
            {
                max_left = i;
                max_right = j;
                sum_max = sum;
            }
        }
    }
    return std::make_tuple(max_left, max_right, sum_max);
}