#include"Quik_sort.h"

void QuikSort(std::vector<int> &A, int p, int r){
    if(p < r){
        int q = Partition(A, p, r);
        QuikSort(A, p, q - 1);
        QuikSort(A, q + 1, r);
    }
}

int Partition(std::vector<int> &A, int p, int r){
    if(r - p >= 1){
        int x = A[r];
        int i = p - 1;
        for(int j = p; j < r; ++j){
        if(A[j] < x){
            ++i;
            ex_num(A[i], A[j]);
        }
        }
        ex_num(A[i+1], A[r]);
        return i+1;
    }
    else{
        return p;
    }
}

void ex_num(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}