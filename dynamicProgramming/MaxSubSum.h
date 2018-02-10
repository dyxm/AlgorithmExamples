//
// 最大子段和
// Created by Administrator on 2018/2/4.
//

#ifndef ALGORITHMEXAMPLES_MAXSUBSUM_H
#define ALGORITHMEXAMPLES_MAXSUBSUM_H

#endif //ALGORITHMEXAMPLES_MAXSUBSUM_H

/**
 * 一般动态规划解法
 * @param n 段的长度
 * @param x 段的内容
 * @return 返回最大和
 */
int MaxSubSum(int n, int *x, int *start, int *end){
    int sum = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        if (b > 0)
            b += x[i];
        else {
            b = x[i];
            *start = i;
            *end = i;
        }
        if (b > sum) {
            sum = b;
            *end = i;
        }
    }
    return sum;
}