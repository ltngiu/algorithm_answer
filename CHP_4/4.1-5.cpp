#include<stdio.h>
#include<iostream>
#include<limits.h>
#include<tuple>
using std::tuple;
tuple<int, int, int> linear_search(int a[], int low, int high);
int main()
{
    int a[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    auto rest = linear_search(a, 0, sizeof(a)/sizeof(a[0]));
    std::cout << std::get<0>(rest) + 1 << " " << std::get<1>(rest) + 1 << " " 
    << std::get<2>(rest) << std::endl;
    return 0;

}

tuple<int, int, int> linear_search(int a[], int low, int high)
{
    int max_sum = a[low], max_left = low, max_right = low + 1;
    for(int i = low + 1; i < high; i++)
    {
        int sum_b = 0;
        for(int j = i; j > low; j--)
        {
            sum_b += a[j];
            
            if(sum_b > max_sum)
            {
                max_left = j;
                max_right = i;
                max_sum = sum_b;
            }
            
        }
    }
    return std::make_tuple(max_left, max_right, max_sum);
}
