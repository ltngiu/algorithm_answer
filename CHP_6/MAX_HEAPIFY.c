#include "MAX_HEAPIFY.h"
void Max_Heap(std::vector<int> &A, int i, int &num){
    //num代表数组的长度
    //std::cout << "当前的num值为:" << num << std::endl;
    // for(int j = 0; j < A.size(); j++)
    // {
    //     std::cout << A[j] << " ";
    // }
    // std::cout << std::endl;
    int l = Left(i);
    int r = Right(i);
    int largest;
    if(l < num && A[l] > A[i])
        largest = l;
    else largest = i;
    if(r < num && A[r] > A[largest])
        largest = r;
    if(largest != i){
        ex_num(A[i], A[largest]);
        Max_Heap(A, largest, num);
    }
}
void Build_Max_Heap(std::vector<int> &A){
    int n = A.size();
    for(int i = n/2 - 1; i >= 0; --i)
        Max_Heap(A, i, n);
}

int Left(int i){
    return 2 * i + 1;
}
int Right(int i){
    return 2 * i + 2;
}
void ex_num(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void Heap_sort(std::vector<int> &A, int &num){
    for(int i = A.size() - 1; i >= 1; --i){
        ex_num(A[0], A[i]);
        --num;
        Max_Heap(A, 0, num);
    }
}
