#include"MIN_HEAPIFY.h"
void Min_Heap(std::vector<int> &A, int i, int &num){
    int l = Left(i);
    int r = Right(i);
    int minnum;
    if(l < num && A[l] < A[i]){
        minnum = l;
    }
    else minnum = i;
    if(r < num && A[r] < A[minnum]){
        minnum = r;
    }
    if(minnum != i){
        ex_num(A[i], A[minnum]);
        Min_Heap(A, minnum, num);
    }
}

void Build_Min_Heap(std::vector<int> &A){
    int n = A.size();
    for(int i = n/2 - 1; i >= 0; --i)
        Min_Heap(A, i, n);
}
void Heap_sort(std::vector<int> &A, int &num){
    for(int i = A.size() - 1; i >= 1; --i){
        ex_num(A[0], A[i]);
        --num;
        Min_Heap(A, 0, num);
    }
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