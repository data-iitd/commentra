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

    int count = 0;
    int flag = 0;

    // First pass: Change 'L' to 'R' up to K times
    for (int i = 0; i < N; i++) {
        if (flag && c1[i] == 'R') {
            flag = 0;
            count++;
        }
        if (count == K) {
            break;
        }
        if (c1[i] == 'L') {
            flag = 1;
            c1[i] = 'R';
        }
    }

    count = 0;
    flag = 0;

    // Second pass: Change 'R' to 'L' up to K times
    for (int i = 0; i < N; i++) {
        if (flag && c3[i] == 'L') {
            flag = 0;
            count++;
        }
        if (count == K) {
            break;
        }
        if (c3[i] == 'R') {
            flag = 1;
            c3[i] = 'L';
        }
    }

    int sum1 = 0;
    int count1 = 1;
    char bef1 = c1[0];

    // Count the number of consecutive characters in S1
    for (int i = 1; i < N; i++) {
        if (c1[i] == bef1) {
            count1++;
            if (i == N - 1) {
                sum1 += count1 - 1;
            }
        } else {
            bef1 = c1[i];
            sum1 += count1 - 1;
            count1 = 1;
        }
    }

    int sum3 = 0;
    int count3 = 1;
    char bef3 = c3[0];

    // Count the number of consecutive characters in S3
    for (int i = 1; i < N; i++) {
        if (c3[i] == bef3) {
            count3++;
            if (i == N - 1) {
                sum3 += count3 - 1;
            }
        } else {
            bef3 = c3[i];
            sum3 += count3 - 1;
            count3 = 1;
        }
    }

    // Output the maximum of the two sums calculated from S1 and S3
    printf("%d\n", sum1 > sum3 ? sum1 : sum3);

    return 0;
}
