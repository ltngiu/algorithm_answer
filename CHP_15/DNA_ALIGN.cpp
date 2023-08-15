#include"DNA_ALIGN.h"
int main(){
    std::string s1 = "GATCGGCAT";
    std::string s2 = "CAATGTGAATC";
    std::vector<int> cost = {0, 1, -1, -2, -2};
    auto res = DNAALIGN(s1, s2, cost);
    print_first_chain(s1, res[1], s1.size(), s2.size());
    std::cout << std::endl;
    print_second_chain(s2, res[1], s1.size(), s2.size());
    std::cout << std::endl;
    std::cout << res[0][s1.size()][s2.size()];
    return 0;
}