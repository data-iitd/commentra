#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

int main() {
    int N, K;
    char S[100001];
    
    scanf("%d %d", &N, &K);
    scanf("%s", S);
    
    int seg_cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        if (S[i] != S[i + 1]) {
            seg_cnt++;
        }
    }
    
    int cur_happy = N - 1 - seg_cnt;
    
    if (2 * K >= seg_cnt) {
        printf("%d\n", N - 1);
    } else {
        printf("%d\n", cur_happy + 2 * K);
    }
    
    return 0;
}
