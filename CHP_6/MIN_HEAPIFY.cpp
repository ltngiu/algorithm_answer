#include"MIN_HEAPIFY.c"


int main(){
    std::vector<int> A = {5, 3, 2, 19, 7, 6, 8, 90, 33, 12, 20, 22, 20};
    int num = A.size();
    // std::cout << "原始数组是：" << std::endl;
    // for(int i = 0; i <A.size()6; ++i){
    //     std::cout << A[i] << " ";
    // }
    // std::cout << std::endl;
    Build_Min_Heap(A);
    // std::cout << "生成的最大堆是：" << std::endl;
    // for(int i = 0; i <A.size(); ++i){
    //     std::cout << A[i] << " ";
    // }
    // std::cout << std::endl;
    Heap_sort(A, num);
    std::cout << "堆排序的结果是：" << std::endl;
    for(int i = 0; i <A.size(); ++i){
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}