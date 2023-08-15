#ifndef LCS
#define LCS
#include<iostream>
#include<cstdio>
#include<vector>
std::vector<std::vector<std::vector<int>>> LCS_LENGTH(std::vector<int> &X, std::vector<int> &Y);
void print_LCS(std::vector<std::vector<int>> &b, std::vector<int> &X, int i , int j);
#endif