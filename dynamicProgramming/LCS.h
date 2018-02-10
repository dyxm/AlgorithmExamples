//
// 最长公共子序列
// Created by Administrator on 2018/2/4.
//

#include <iostream>

#ifndef ALGORITHMEXAMPLES_LCS_H
#define ALGORITHMEXAMPLES_LCS_H

#endif //ALGORITHMEXAMPLES_LCS_H

/**
 * 求解最长公共子序列
 * @param m 字符串x的长度
 * @param n 字符串y的长度
 * @param x 字符串x
 * @param y 字符串y
 * @param c 长度记录矩阵
 * @param b 子问题类别记录矩阵
 */
void LSCLength(int m, int n, char *x, char *y, int **c, int **b) {
    int i, j;
    for (i = 0; i <= m; ++i)
        for (int j = 0; j <= n; ++j)
            c[i][j] = 0;
    for (i = 1; i <= m; ++i) {
        for (j = 1; j <= n; ++j) {
            if (x[i - 1] == y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 1;
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = 2;
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = 3;
            }
        }
    }
}

/**
 * 打印最长子序列
 * @param i
 * @param j
 * @param x
 * @param b 子问题类别记录矩阵
 */
void PrintLCS(int i, int j, char *x, int **b) {
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == 1) {
        PrintLCS(i - 1, j - 1, x, b);
        std::cout << x[i-1];
    } else if (b[i][j] == 2)
        PrintLCS(i - 1, j, x, b);
    else
        PrintLCS(i, j - 1, x, b);
}