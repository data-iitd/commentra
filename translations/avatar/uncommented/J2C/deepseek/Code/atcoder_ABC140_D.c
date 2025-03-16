#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    char S[N+1];
    scanf("%s", S);
    char c1[N], c3[N];
    strcpy(c1, S);
    strcpy(c3, S);
    bool flag = false;
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (flag && c1[i] == 'R') {
            flag = false;
            count++;
        }
        if (count == K) {
            break;
        }
        if (c1[i] == 'L') {
            flag = true;
            c1[i] = 'R';
        }
    }
    flag = false;
    count = 0;
    for (int i = 0; i < N; i++) {
        if (flag && c3[i] == 'L') {
            flag = false;
            count++;
        }
        if (count == K) {
            break;
        }
        if (c3[i] == 'R') {
            flag = true;
            c3[i] = 'L';
        }
    }
    char S1[N+1], S3[N+1];
    strcpy(S1, c1);
    strcpy(S3, c3);
    int count1 = 1, sum1 = 0;
    char bef = S1[0];
    for (int i = 1; i < N; i++) {
        if (S1[i] == bef) {
            count1++;
            if (i == N - 1) {
                sum1 += count1 - 1;
            }
        } else {
            bef = S1[i];
            sum1 += count1 - 1;
            count1 = 1;
        }
    }
    int count3 = 1, sum3 = 0;
    bef = S3[0];
    for (int i = 1; i < N; i++) {
        if (S3[i] == bef) {
            count3++;
            if (i == N - 1) {
                sum3 += count3 - 1;
            }
        } else {
            bef = S3[i];
            sum3 += count3 - 1;
            count3 = 1;
        }
    }
    printf("%d\n", sum1 > sum3 ? sum1 : sum3);
    return 0;
}
