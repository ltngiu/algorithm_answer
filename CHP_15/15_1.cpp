#include"15_1.c"
int main(){
    // std::cout << "请输入节点的个数" << std::endl;
    int n = 5;
    std::vector<std::vector<double>> gp(n, std::vector<double>(n, INT_MAX));
    gp[1][0] = 1.5;
    gp[0][4] = -2.3;
    gp[3][4] = 3.7;
    gp[0][2] = 5.4;
    gp[1][3] = -1.1;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)
            std::cout << gp[i][j] << " ";
        std::cout << std::endl;    
    }
    int sour, term;
    sour = 0;
    term = 1;
    
    return 0;

}