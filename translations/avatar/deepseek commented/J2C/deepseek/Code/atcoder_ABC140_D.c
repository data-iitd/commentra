#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, K;
    char S[100001];
    
    scanf("%d %d", &N, &K);
    scanf("%s", S);
    
    char c1[100001];
    char c3[100001];
    strcpy(c1, S);
    strcpy(c3, S);
    
    int count = 0;
    int flag = 0;
    
    // Process c1 (Left to Right)
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
    
    flag = 0;
    count = 0;
    
    // Process c3 (Right to Left)
    for (int i = N - 1; i >= 0; i--) {
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
    int sum3 = 0;
    int count_char = 1;
    char bef = c1[0];
    
    // Count consecutive characters in S1
    for (int i = 1; i < N; i++) {
        if (c1[i] == bef) {
            count_char++;
            if (i == N - 1) {
                sum1 += count_char - 1;
            }
        } else {
            bef = c1[i];
            sum1 += count_char - 1;
            count_char = 1;
        }
    }
    
    count_char = 1;
    bef = c3[0];
    
    // Count consecutive characters in S3
    for (int i = 1; i < N; i++) {
        if (c3[i] == bef) {
            count_char++;
            if (i == N - 1) {
                sum3 += count_char - 1;
            }
        } else {
            bef = c3[i];
            sum3 += count_char - 1;
            count_char = 1;
        }
    }
    
    // Print the maximum of the two sums
    printf("%d\n", sum1 > sum3 ? sum1 : sum3);
    
    return 0;
}
