//
// ����Ӷκ�
// Created by Administrator on 2018/2/4.
//

#ifndef ALGORITHMEXAMPLES_MAXSUBSUM_H
#define ALGORITHMEXAMPLES_MAXSUBSUM_H

#endif //ALGORITHMEXAMPLES_MAXSUBSUM_H

/**
 * һ�㶯̬�滮�ⷨ
 * @param n �εĳ���
 * @param x �ε�����
 * @return ��������
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