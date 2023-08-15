#include"15_12.h"
int main(){
    std::default_random_engine e(5);
    std::uniform_int_distribution<int> u(1000, 10000);
    std::uniform_int_distribution<int> f(80, 150);
    std::vector<std::vector<int>> price(6, std::vector<int>(51)), score(6, std::vector<int>(51));
    int yusuan = 50000;
    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < 51; ++j){
            price[i][j] = u(e);
            score[i][j] = f(e);
        }
    }
    auto res = dpgram(price,score, yusuan);
    return 0;

}