#include"Quik_sort.c"
int main(){
    std::vector<int> A = {13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11};
    for(auto key = A.begin(); key != A.end(); ++key){
        std::cout << *key << " ";
    }
    std::cout << std::endl;
    QuikSort(A, 0, A.size() - 1);
    for(auto key = A.begin(); key != A.end(); ++key){
        std::cout << *key << " ";
    }
    return 0;
}