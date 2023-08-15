#ifndef MIN_HEAPIFY
#define MIN_HEAPIFY
#include<cstdio>
#include<vector>    
#include<iostream>
void Min_Heap(std::vector<int> &A, int i, int &num);
void ex_num(int &a, int &b);
int Left(int i);
int Right(int i);
void Heap_sort(std::vector<int> &A, int &num);
void Build_Min_Heap(std::vector<int> &A);
#endif

