#include"15_11.h"
int main(){
    int n  = 12;  //未来需求的月份（默认为一年的需求）
    std::default_random_engine e(11);
    int m = 200;
    double c = 100;
    std::uniform_int_distribution<int> u(100, 2000);
    std::vector<int> D(n+1);
    for(int i = 1; i <= n; ++i){
        D[i] = u(e);
        std::cout << D[i] << " ";
    }std::cout << D[0];
    std::cout << std::endl;
    auto res = store_plan(D, m, c);
    int total_need = std::accumulate(D.begin()+1, D.end(), 0);
    print_res(res, D.size()-1, std::accumulate(D.begin() + 1, D.end(), 0));
    return 0;
}