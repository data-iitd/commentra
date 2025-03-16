
#include <stdio.h>
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
    
    bool flag = false;
    int count = 0;
    
    // Process c1 (Left to Right)
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
    
    // Process c3 (Right to Left)
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
    
    int sum1 = 0;
    char bef = c1[0];
    int count1 = 1;
    for (int i = 1; i < N; i++) {
        if (c1[i] == bef) {
            count1++;
            if (i == N - 1) {
                sum1 += count1 - 1;
            }
        } else {
            bef = c1[i];
            sum1 += count1 - 1;
            count1 = 1;
        }
    }
    
    int sum3 = 0;
    bef = c3[0];
    int count3 = 1;
    for (int i = 1; i < N; i++) {
        if (c3[i] == bef) {
            count3++;
            if (i == N - 1) {
                sum3 += count3 - 1;
            }
        } else {
            bef = c3[i];
            sum3 += count3 - 1;
            count3 = 1;
        }
    }
    
    printf("%d\n", sum1 > sum3? sum1 : sum3);
    
    return 0;
}
// END-OF-CODE