//第四章分治策略P41-最大子数组问题
//原数组13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7
#include<tuple>
#include<stdio.h>
#include<iostream>
#include<limits.h>

std::tuple<int, int, int> find_max_crossing_subarray(int c[], int low, int mid, int high);
//寻找最大的交叉字数组
std::tuple<int, int, int> find_max_subarray(int* c, int low, int high);
//寻找最大的字数组
int main()
{
    int a[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    auto rest = find_max_subarray(a, 0, (sizeof(a))/sizeof(a[0]));
    std::cout << std::get<0>(rest) + 1 << " " << std::get<1>(rest) + 1 << " " << std::get<2>(rest) << std::endl;
    return 0;
}
std::tuple<int, int, int> find_max_crossing_subarray(int c[], int low, int mid, int high)
{
    int left_sum = INT_MIN;
    int sum = 0, max_left;
    if(high == low + 1) return std::make_tuple(low, high, c[low]);
    else if(high == low + 2) return std::make_tuple(low, high, c[low] + c[high - 1]);
    else{
    for(int i = mid; i >= low; i--)
    {
        sum += c[i];
        if(sum > left_sum) {left_sum = sum; max_left = i;}
        
    }
    int right_sum = INT_MIN;
    sum = 0;
    int max_right;
    for(int i = mid + 1; i < high; i++)
    {
        sum = sum + c[i];
        if(sum > right_sum) {right_sum = sum; max_right = i;}
    }
    auto ret = std::make_tuple(max_left, max_right, left_sum + right_sum);
    return ret;
    }
}
std::tuple<int, int, int> find_max_subarray(int* c, int low, int high)
{
    int mid = (low + high) / 2;
    if(low == mid) return std::make_tuple(low, high, c[low]);
    else 
    {
        
        std::tuple<int, int, int> left = find_max_subarray(c, low, mid);
        std::tuple<int, int, int> right = find_max_subarray(c, mid, high);
        std::tuple<int, int, int> cross = find_max_crossing_subarray(c, low, mid, high);
        if(std::get<2>(left) >= std::get<2>(right) && std::get<2>(left) >= std::get<2>(cross))
        return left;
        else if(std::get<2>(right) >= std::get<2>(left) && std::get<2>(right) >= std::get<2>(cross))
        return right;
        else
        return cross;
    }
}