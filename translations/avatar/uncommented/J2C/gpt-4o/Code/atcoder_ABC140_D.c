#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    
    char S[N + 1];
    scanf("%s", S);
    
    char c1[N + 1];
    char c3[N + 1];
    strcpy(c1, S);
    strcpy(c3, S);
    
    int flag = 0;
    int count = 0;
    
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
    
    count = 1;
    int sum1 = 0;
    char bef = S[0];
    
    for (int i = 1; i < N; i++) {
        if (S[i] == bef) {
            count++;
            if (i == N - 1) {
                sum1 += count - 1;
            }
        } else {
            bef = S[i];
            sum1 += count - 1;
            count = 1;
        }
    }
    
    count = 1;
    int sum3 = 0;
    bef = S[0];
    
    for (int i = 1; i < N; i++) {
        if (c3[i] == bef) {
            count++;
            if (i == N - 1) {
                sum3 += count - 1;
            }
        } else {
            bef = c3[i];
            sum3 += count - 1;
            count = 1;
        }
    }
    
    printf("%d\n", sum1 > sum3 ? sum1 : sum3);
    
    return 0;
}

// <END-OF-CODE>
