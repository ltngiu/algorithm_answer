#include "counting_sort.h"

void counting_sort(std::vector<int> &A, std::vector<int> &B, int k){
    std::vector<int> C(k + 1, 0);
    for(j = 0; j < A.size(); ++j){
        C[A[j]] += 1;
    }
    for(i = 1; i <= k; ++i){
        C[i] = C[i] + C[i - 1];
    }
    for(j = A.size() - 1; j >= 0; --j){
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
}