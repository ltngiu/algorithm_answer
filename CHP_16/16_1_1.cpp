#include"16_1_1.h"
int main(){
    std::vector<int> s = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12, 16};
    std::vector<int> f = {0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16, 16};
    auto res = event_dynamic_program(s, f);
    print_res(res[1], 0, s.size()-1);
    std::cout << std::endl;
    for(int i = 0; i < 13; ++i){
        for(int j = 0; j < 13; ++j)
        std::cout << res[1][i][j] << " ";
        std::cout << std::endl;
    }
    return 0;
}