#include"15_9.h"
int main(){
    std::vector<int> st = {0, 2, 8, 10, 15, 22, 27, 33, 47, 50, 53, 66, 79, 100};
    // std::cout << std::accumulate(st.begin(), st.end(), 0);
    auto res = string_spl(st);
    std::cout << res[0][1][st.size()- 2] << std::endl;
    // for(int i = 1; i < st.size() - 1; ++i){
    //     for(int j = 1; j < st.size() - 1; ++j){
    //         std::cout << res[0][i][j] << " " ;
    //     }
    //     std::cout << std::endl;
    // }
    
    print_res(res[1], 1, st.size()-2);
    return 0;

}