#include <iostream>
#include "dynamicProgramming/MatrixChain.h"
#include "dynamicProgramming/LCS.h"


int main() {
    /**
     * 矩阵连乘测试
     */
//    int p[7] = {30, 35, 15, 5, 10, 20, 25};
//    int **m = (int **)malloc(sizeof(int *) * 7); // 分配所有行的首地址
//    int **s = (int **)malloc(sizeof(int *) * 7);
//    for (int i = 0; i < 7; i ++) { // 按行分配每一列
//        m[i] = (int *)malloc(sizeof(int) * 7);
//        s[i] = (int *)malloc(sizeof(int) * 7);
//    }
//    for (int i = 0; i < 7; ++i)
//        for (int j = 0; j < 7; ++j) {
//            m[i][j] = 0;
//            s[i][j] = 0;
//        }
//    //MatrixChain(p, 6, m, s);
//    MemorizedMatrixChain(p, 6, m, s);
//    Traceback(1, 6, s);

    /**
     * 最长公共子序列
     */
    int m = 7, n = 6;
    char x[m] = {'A', 'B', 'C', 'B', 'D', 'A', 'B'};
    char y[n] = {'B', 'D', 'C', 'A', 'B', 'A'};
    int **c = (int **)malloc(sizeof(int *) * (m + 1));
    int **b = (int **)malloc(sizeof(int *) * (m + 1));
    for (int i = 0; i < (m + 1); i ++) {
        c[i] = (int *)malloc(sizeof(int) * (n + 1));
        b[i] = (int *)malloc(sizeof(int) * (n + 1));
    }
    LSCLength(m, n, x, y, c, b);
    PrintLCS(m, n, x, b);
    return 0;
}