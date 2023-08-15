#ifndef Graph_A
#define Graph_A
#include<cstdio>
#include<iostream>
#include<map>
#include<deque>
#include<limits.h>
#include<vector>
enum colour{White, Black, Gray};
class Vertex{
    public:
        int key;
        int data;
        int distance = INT_MAX;
        int finished = INT_MAX;
        colour color_tag = colour::White;
        Vertex* Pre; //该节点的前驱
        std::vector<Vertex*> Adj;
        Vertex(int key_in, int data_in): key(key_in), data(data_in), 
                Pre(NULL){}
};
class Graph{
    public:
        int V;
        std::map<std::vector<int>, int> edge_set;
        std::vector<Vertex*> Vertexes;
        Graph():V(0){}
        Graph(int VE);
        void BFS(Vertex* s);
        void DFS(Vertex* s);
        void DFS_VISIT(Vertex* u, int& times);
};
#endif