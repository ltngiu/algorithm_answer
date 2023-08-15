#ifndef cutrod
#define cutrod
#include<vector>
#include<iostream>
#include <limits.h>
#include<algorithm>
#include<cstdio>
int Memorized_Cut_Rod(int n, std::vector<int> &p);
int Memorized_cut_rod_aux(std::vector<int> &p, int n, std::vector<int> &r);
int bottom_up_cut_rod(std::vector<int> &p, int n);
std::vector<std::vector<int>> Extended_Bottom_Up_Cut_Rod(std::vector<int> &p, int n);

#endif