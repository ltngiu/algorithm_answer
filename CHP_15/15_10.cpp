#include"15_10.h"
int main(){
    std::default_random_engine e(10);
    std::uniform_real_distribution<double> u(0.05, 0.2);
    double benjin = 10000;
    std::vector<std::vector<double>> reward(11, std::vector<double>(21));
    std::vector<double> chang = {0.96, 0.92};
    //投资转移手续费，如果不转移投资，收取费用为0.04全部收入，否则为0.08全部收入
    for(int i = 1; i < 11; ++i){
        for(int j = 1; j < 21; ++j){
            reward[i][j] = u(e);
            reward[i][j] += 1;
            std::cout << reward[i][j] << " ";
        }
        std::cout << std::endl;
    }
    auto res = touzi_guihua(reward, benjin, chang);
    print_res(res[0], res[1], reward.size(), res[1][0][0], reward.size()-1);
    return 0;
}