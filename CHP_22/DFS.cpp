#include"DFS.c"
// 1 2 1
// 1 5 1
// 2 5 1 
// 2 4 1 
// 5 4 1 
// 2 3 1
// 3 4 1
int main(){
    Graph GGG(5);
    // for(int i = 0; i < GGG.Vertexes.size(); ++i){
    //     std::cout << "以节点" << i+1 << "为源节点的广度优先搜索：" << std::endl;
    //     GGG.BFS(GGG.Vertexes[i]);
    //     for(auto &key: GGG.Vertexes){
    //         key->color_tag = colour::White;
    //         key->distance = INT_MAX;
    //         key->Pre = NULL;
    //     }
    // }
    
   
        GGG.DFS(GGG.Vertexes[0]);
    std::cout << "从节点" << 1 << "开始执行深度优先搜索的顺序为：" << std::endl;
    for(int i = 0; i < GGG.Vertexes.size(); ++i){
        
        std::cout << "节点" << i + 1 << "被发现的时间为：" << (GGG.Vertexes[i])->distance << std::endl;
        std::cout << "节点" << i + 1 << "结束搜索的时间为：" << (GGG.Vertexes[i])->finished << std::endl;
        
       
    }
    return 0;
}