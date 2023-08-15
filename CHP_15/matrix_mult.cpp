#include"matrix_mult.c"

int main(){
    std::vector<int> p = {5, 10, 3, 12, 5, 50, 6};
    auto res = matrix_chain(p);
    int n = p.size();
    auto m = res[0];
    std::cout << m[1][n-1];
    return 0;
}