//
// �����������⣨�������˳��
// Created by dyxm on 2018/2/4.
//

#ifndef ALGORITHMEXAMPLES_MATRIXCHAIN_H
#define ALGORITHMEXAMPLES_MATRIXCHAIN_H

#endif //ALGORITHMEXAMPLES_MATRIXCHAIN_H

/**
 * ���涯̬�滮�ⷨ
 * @param p ���󳤶ȼ�¼
 * @param n �������
 * @param m �ܴ�����¼����
 * @param s �ָ���¼����
 * @return
 */
void MatrixChain(int *p, int n, int **m, int **s) {
//    for (int i = 1; i <= n; ++i) m[i][i] = 0;
    for (int r = 1; r < n; ++r) {
        for (int i = 1; i < n - r + 1; ++i) {
            int j = i + r;
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
            s[i][j] = i;
            for (int k = i + 1; k < j; ++k) {
                int temp = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (temp < m[i][j]) {
                    m[i][j] = temp;
                    s[i][j] = k;
                }
            }
        }
    }
}


/**
 * ������¼����̬�滮�ⷨ�ĵݹ�����
 * @param i
 * @param j
 * @param p ���󳤶ȼ�¼
 * @param m �ܴ�����¼����
 * @param s �ָ���¼����
 * @return
 */
int LookupChain(int i, int j, int *p, int **m, int **s) {
    if (m[i][j] > 0)
        return m[i][j];
    if (i == j)
        return 0;
    int u = LookupChain(i, i, p, m, s) + LookupChain(i + 1, j, p, m, s) + p[i - 1] * p[i] * p[j];
    s[i][j] = i;
    for (int k = i + 1; k < j; ++k) {
        int t = LookupChain(i, k, p, m, s) + LookupChain(k + 1, j, p, m, s) + p[i - 1] * p[k] * p[j];
        if (t < u) {
            u = t;
            s[i][j] = k;
        }
    }
    m[i][j] = u;
    return u;
}


/**
 * ������¼����̬�滮�ⷨ
 * @param p ���󳤶ȼ�¼
 * @param n �������
 * @param m �ܴ�����¼����
 * @param s �ָ���¼����
 * @return
 */
int MemorizedMatrixChain(int *p, int n, int **m, int **s) {
    return LookupChain(1, n, p, m, s);
}


/**
 * ��ӡ�����Ž�ṹ
 * @param i
 * @param j
 * @param s �ָ���¼����
 * @return
 */
void Traceback(int i, int j, int **s) {
    if (i == j) {
        std::cout << "A" << i;
        return;
    }
    std::cout << "(";
    Traceback(i, s[i][j], s);
    Traceback(s[i][j] + 1, j, s);
    std::cout << ")";
}
