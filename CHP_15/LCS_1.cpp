#include"LCS_1.c"
int main(){
    std::vector<int> X = {1, 0, 0, 1, 0, 1, 0, 1};
    std::vector<int> Y = {0, 1, 0, 1, 1, 0, 1, 1, 0};
    auto res = LCS_LENGTH(X, Y);
    int n = X.size() < Y.size() ? X.size(): Y.size();
    std::cout << res[0] << " " << std::endl;
    for(int i = res[1] - res[0]+1; i <= res[1]; ++i)
        std::cout << X[i] << " ";
    std::cout << std::endl;
    for(int i = res[2] - res[0]+1; i <= res[2]; ++i)
        std::cout << Y[i] << " ";
    return 0;
}