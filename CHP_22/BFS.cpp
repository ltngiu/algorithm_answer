#include<vector>
#include<deque>
#include<cstdio>
#include<iostream>
#include"BFS.c"
int main(){
    std::vector<Graphical> vertex({1, 2, 3, 4, 5});
    vertex[0].Adj = {2, 5};
    vertex[1].Adj = {1, 5, 3, 4};
    vertex[2].Adj = {2, 4};
    vertex[3].Adj = {2, 5, 3};
    vertex[4].Adj = {4, 1, 2};
    for(int i = 0; i < vertex.size(); ++i){
        std::cout << "以节点" << i+1 << "为源节点的广度优先搜索：" << std::endl;
        BFS(&vertex[i], vertex);
        for(auto &key: vertex){
            key.color_tag = colour::White;
            key.distance = INT_MAX;
        }
    }
    
    return 0;
}