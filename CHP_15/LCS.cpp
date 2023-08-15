#include"LCS.c"
int main(){
    std::vector<int> X = {1, 0, 0, 1, 0, 1, 0, 1};
    std::vector<int> Y = {0, 1, 0, 1, 1, 0, 1, 1, 0};
    auto res = LCS_LENGTH(X, Y);
    auto b = res[1];
    auto c = res[0];
    print_LCS(b, X, X.size(), Y.size());
    return 0;
}