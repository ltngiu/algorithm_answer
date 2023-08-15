#include"BFS.h"
void BFS(Graphical *source, std::vector<Graphical>& vertex){
    source->color_tag = colour::Gray;
    source->distance = 0;
    source->Pre = NULL;
    std::deque<Graphical*> que;
    que.push_back(source);
    while(que.size() > 0){
        auto u = que[0];
        que.pop_front();
        for(auto key: u->Adj){
            if(vertex[key - 1].color_tag == colour::White){
                vertex[key - 1].color_tag = colour::Gray;
                vertex[key - 1].distance = u->distance + 1;
                vertex[key - 1].Pre = u;
                que.push_back(&vertex[key - 1]);
            }
        u->color_tag = colour::Black;
        }
    }
    for(auto key = vertex.begin(); key != vertex.end(); ++key){
        std::cout <<"节点" << key->data << "到源节点" << source->data << "的距离为：" << key->distance << "；";
        if(key->Pre != NULL){
            std::cout << "它的前驱为：" << key->Pre->data << "。" << std::endl;
        }
        else std::cout << "这个节点就是源节点，它没有前驱。" << std::endl;
    }
}