#ifndef Graph_Algorithm
#define Graph_Algorithm
#include<cstdio>
#include<vector>
#include<limits.h>
enum colour{White, Black, Gray};

class Graphical{
    public:
    
        int data;
        int distance;
        std::vector<int> Adj;
        Graphical* Pre;
        colour color_tag = colour::White;
        Graphical(int data_in): data(data_in), distance(INT_MAX), Pre(NULL){}
};

void BFS(Graphical *source, std::vector<Graphical>& vertex);
#endif