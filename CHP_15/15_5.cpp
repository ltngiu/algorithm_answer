#include "15_5.h"
int main(){
    std::string x = "dkl;asjtriopqwudjkaewqio";
    std::string y = "dkasjeoqwoicmnejjkdfasl;elkqt";
    std::vector<int> cost = {INT_MAX ,1, 2, 3, 4, 5, 6};
    auto res = Edit_dist(x, y, cost);
    print_operator_chain(res[1], res[0][0][0], x.size(), y.size());
    std::cout << "编辑距离为：" << res[0][x.size()][y.size()] << std::endl;

    return 0;
}