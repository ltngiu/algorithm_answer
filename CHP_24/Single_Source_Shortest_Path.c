#include"Single_Source_Shortest_Path.h"

Graph::Graph(int VE):V(VE){
    for(int i = 0; i < V; ++i){
        auto* temp_vex = new Vertex(i + 1, 0);
        Vertexes.push_back(temp_vex);
    }
    std::cout << "请按照节点、节点、权重的顺序输入边：" << std::endl;
    int temp;
    std::deque<int> temp_edge;
    while(std::cin >> temp){   
        temp_edge.push_back(temp);
    }
    while(temp_edge.size() >= 3){
        if(temp_edge[0] == temp_edge[1]) std::cout << "一条边的两个节点不能相等！" << std::endl;
        else{
            (Vertexes[temp_edge[0] - 1]->Adj).push_back(Vertexes[temp_edge[1] - 1]);
            (Vertexes[temp_edge[1] - 1]->Adj).push_back(Vertexes[temp_edge[0] - 1]);
            edge_set[std::vector<int>{temp_edge[0], temp_edge[1]}] = temp_edge[2];
            edge_set[std::vector<int>{temp_edge[1], temp_edge[0]}] = temp_edge[2];
        }
        for(int i = 0; i < 3; ++i)
            temp_edge.pop_front();
    }   
}
void Initialize_single_source(Graph& G, Vertex& source){
    for(auto key: G.Vertexes){
        key->distance = INT_MAX;
        key->Pre = NULL;
    }
    source.distance = 0;
}