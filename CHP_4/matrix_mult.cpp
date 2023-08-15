#include<stdio.h>
#include<iostream>
void multp(int m, int n, int s, int *A, int *B, int *C);
int main()
{
    int m, n, p, s;
    std::cout << "请输入要相乘的两个矩阵的行列数：" << std::endl;
    std::cin >> m >> n >> p >> s;
    if(n != p) {std::cout << "第一个矩阵的列与第二个矩阵的行必须相等";}
    int A[m][n], B[p][s], C[m][s];
    std::cout << "请输入要相乘的两个矩阵的元素：" << std::endl;
    std::cout << "第一个矩阵：" << std::endl;
    for(int i = 0; i != m; i++)
    for(int j = 0; j != n; j++)
    std::cin >> A[i][j];
    std::cout << "第二个矩阵：" << std::endl;
    for(int i = 0; i != p; i++)
    for(int j = 0; j != s; j++)
    std::cin >> B[i][j];
    multp(m, n, s, &A[0][0], &B[0][0], &C[0][0]);
    for(int i = 0; i != m; i++)
    {
        for(int j = 0; j != s; j++)
            std::cout << C[i][j] << " ";
        std::cout << std::endl;
    }
    
    return 0;
}
void multp(int m, int n, int s, int *A, int *B, int *C)
{
    for(int i = 0; i != m; i++)
    {
        for(int j = 0; j != s; j++)
        {
            
            *(C + i * m + j) = 0;
            for(int k = 0; k != n; k++)
            {
                *(C + i * m + j) += *(A + i * m + k) * (*(B + k * n + j));
                
            }
        }
    }
    std::cout << std::endl;
}

