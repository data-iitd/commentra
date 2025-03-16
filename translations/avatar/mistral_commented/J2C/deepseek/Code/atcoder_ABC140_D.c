#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, K;
    char S[100001];

    scanf("%d %d", &N, &K);
    scanf("%s", S);

    char c1[100001], c3[100001];
    strcpy(c1, S);
    strcpy(c3, S);

    int flag1 = 0, count1 = 0;
    for (int i = 0; i < N; i++) {
        if (flag1 && c1[i] == 'R') {
            flag1 = 0;
            count1++;
        }
        if (count1 == K) {
            break;
        }
        if (c1[i] == 'L') {
            flag1 = 1;
        }
    }

    int flag3 = 0, count3 = 0;
    for (int i = 0; i < N; i++) {
        if (flag3 && c3[i] == 'L') {
            flag3 = 0;
            count3++;
        }
        if (count3 == K) {
            break;
        }
        if (c3[i] == 'R') {
            flag3 = 1;
        }
    }

    char S1[100001], S3[100001];
    strcpy(S1, c1);
    strcpy(S3, c3);

    int count2 = 1, sum1 = 0;
    char bef1 = S1[0];
    for (int i = 1; i < N; i++) {
        if (S1[i] == bef1) {
            count2++;
        } else {
            sum1 += count2 - 1;
            count2 = 1;
            bef1 = S1[i];
        }
    }
    sum1 += count2 - 1;

    int count4 = 1, sum3 = 0;
    char bef3 = S3[0];
    for (int i = 1; i < N; i++) {
        if (S3[i] == bef3) {
            count4++;
        } else {
            sum3 += count4 - 1;
            count4 = 1;
            bef3 = S3[i];
        }
    }
    sum3 += count4 - 1;

    printf("%d\n", sum1 > sum3 ? sum1 : sum3);

    return 0;
}
