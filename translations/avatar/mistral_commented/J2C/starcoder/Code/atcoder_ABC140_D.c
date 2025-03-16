
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int N, K;
    scanf("%d %d", &N, &K);
    char S[N];
    scanf("%s", S);

    char c1[N], c3[N];
    int flag1 = 0, count1 = 0;
    for (int i = 0; i < N; i++) {
        if (flag1 && S[i] == 'R') {
            flag1 = 0;
            count1++;
        }
        if (count1 == K) {
            break;
        }
        if (S[i] == 'L') {
            flag1 = 1;
        }
    }

    int flag3 = 0, count3 = 0;
    for (int i = 0; i < N; i++) {
        if (flag3 && S[i] == 'L') {
            flag3 = 0;
            count3++;
        }
        if (count3 == K) {
            break;
        }
        if (S[i] == 'R') {
            flag3 = 1;
        }
    }

    strcpy(c1, S);
    strcpy(c3, S);

    int count2 = 1, sum1 = 0, bef1 = c1[0];
    for (int i = 1; i < N; i++) {
        if (c1[i] == bef1) {
            count2++;
        } else {
            sum1 += count2 - 1;
            count2 = 1;
            bef1 = c1[i];
        }
    }
    sum1 += count2 - 1;

    int count4 = 1, sum3 = 0, bef3 = c3[0];
    for (int i = 1; i < N; i++) {
        if (c3[i] == bef3) {
            count4++;
        } else {
            sum3 += count4 - 1;
            count4 = 1;
            bef3 = c3[i];
        }
    }
    sum3 += count4 - 1;

    printf("%d\n", (sum1 > sum3)? sum1 : sum3);
    return 0;
}

