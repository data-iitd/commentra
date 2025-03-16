#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    char S[N];
    scanf("%s", S);
    
    int flag = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (flag && S[i] == 'R') {
            flag = 0;
            count++;
        }
        if (count == K) {
            break;
        }
        if (S[i] == 'L') {
            flag = 1;
            S[i] = 'R';
        }
    }
    
    flag = 0;
    count = 0;
    for (int i = 0; i < N; i++) {
        if (flag && S[i] == 'L') {
            flag = 0;
            count++;
        }
        if (count == K) {
            break;
        }
        if (S[i] == 'R') {
            flag = 1;
            S[i] = 'L';
        }
    }
    
    int sum1 = 0;
    int sum3 = 0;
    int count = 1;
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
    bef = S[0];
    for (int i = 1; i < N; i++) {
        if (S[i] == bef) {
            count++;
            if (i == N - 1) {
                sum3 += count - 1;
            }
        } else {
            bef = S[i];
            sum3 += count - 1;
            count = 1;
        }
    }
    
    printf("%d\n", max(sum1, sum3));
    return 0;
}

