#include"CUT_ROD.c"
int main(){
    std::vector<int> pr = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    std::vector<int> leng = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int r = Memorized_Cut_Rod(pr.size(), pr);
    // for(auto key = pr.begin(); key != pr.end(); ++key){
    //     std::cout << *key << " ";
    // }
    // std::cout << std::endl;
    std::cout << r << std::endl;
    std::cout << bottom_up_cut_rod(pr, pr.size()) << std::endl;
    auto v = Extended_Bottom_Up_Cut_Rod(pr, pr.size());
    auto temp = v.begin();
    std::cout << (*temp).back() << std::endl;
    auto s = v.end() - 1;
    int n = pr.size();
    while(n > 0){
        std::cout << (*s)[n] << " ";
        n = n - (*s)[n];
    }
    return 0;
}

