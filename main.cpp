//
// �����㷨ѧϰ�ʼ�
// Created by dyxm on 2018/2/4.
//
#include <iostream>
#include "dynamicProgramming/MatrixChain.h"
#include "dynamicProgramming/LCS.h"
#include "dynamicProgramming/MaxSubSum.h"


int main() {
    /**
     * �������ˣ����ٳ˻����������У�
     */
//    int p[7] = {30, 35, 15, 5, 10, 20, 25};
//    int **m = (int **)malloc(sizeof(int *) * 7); // ���������е��׵�ַ
//    int **s = (int **)malloc(sizeof(int *) * 7);
//    for (int i = 0; i < 7; i ++) { // ���з���ÿһ��
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
     * �����������
     */
//    int m = 7, n = 6;
//    char x[m] = {'A', 'B', 'C', 'B', 'D', 'A', 'B'};
//    char y[n] = {'B', 'D', 'C', 'A', 'B', 'A'};
//    int **c = (int **)malloc(sizeof(int *) * (m + 1));
//    int **b = (int **)malloc(sizeof(int *) * (m + 1));
//    for (int i = 0; i < (m + 1); i ++) {
//        c[i] = (int *)malloc(sizeof(int) * (n + 1));
//        b[i] = (int *)malloc(sizeof(int) * (n + 1));
//    }
//    LSCLength(m, n, x, y, c, b);
//    PrintLCS(m, n, x, b);

    /**
     * ����Ӷκ�
     */
    int n = 6;
    int start = 0, end = 0;
    int x[6] = {-2, 11, -4, 13, -5, -2};
    int sum = MaxSubSum(n, x, &start, &end);
    std::cout << "����Ϊ��";
    for (int i = start; i <= end; ++i) {
        std::cout << x[i] << ",";
    }
    std::cout << "\n��Ϊ��" << sum;
    return 0;
}