#include"DFS.h"

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
void Graph::BFS(Vertex* s){
    s->color_tag = colour::Gray;
    s->distance = 0;
    std::deque<Vertex*> dqe;
    dqe.push_back(s);
    while(dqe.size() > 0){
        auto u = dqe[0];
        dqe.pop_front();
        for(auto key: u->Adj){
            if(key->color_tag == colour::White){
                key->color_tag = colour::Gray;
                key->distance = u->distance + edge_set[{key->key, u->key}];
                key->Pre = u;
                dqe.push_back(key);
            }
            u->color_tag = colour::Black;
        }
    }
    for(auto key = Vertexes.begin(); key != Vertexes.end(); ++key){
        std::cout <<"节点" << (*key)->key << "到源节点" << s->key << "的距离为：" << (*key)->distance << "；";
        if((*key)->Pre != NULL){
            std::cout << "它的前驱为：" << (*key)->Pre->key << "。" << std::endl;
        }
        else std::cout << "这个节点就是源节点，它没有前驱。" << std::endl;
    }
}
void Graph::DFS(Vertex* s){
    int times = 0;
    //DFS_VISIT(s, times);
    for(auto u: Vertexes){
        if(u->color_tag == colour::White)
            DFS_VISIT(u, times);
    }
}
void Graph::DFS_VISIT(Vertex* u, int& times){
    times += 1;
    u->distance = times;
    u->color_tag = colour::Gray;
    for(auto key: u->Adj){
        if(key->color_tag == colour::White){
            key->Pre = u;
            DFS_VISIT(key, times);
        }
    }
    u->color_tag = colour::Black;
    times += 1;
    u->finished = times;
}