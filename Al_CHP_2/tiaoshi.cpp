#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<vector>
void Merge(std::vector<int>::iterator pa);
int main(){
    int n = 1;
    int m = n /2;
    std::cout << m;
    return 0;
    
}
void Merge(std::vector<int>::iterator pa)
{
    *pa = 0;
    *(pa+1) = 0;
    *(pa+2) = 0;
}