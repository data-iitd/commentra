#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

int gi() {
    int num;
    scanf("%d", &num);
    return num;
}

char* gw() {
    static char buffer[100];
    scanf("%s", buffer);
    return buffer;
}

int main() {
    int N = gi();
    int K = gi();
    char* S = gw();
    
    int seg_cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        if (S[i] != S[i + 1]) {
            seg_cnt++;
        }
    }
    
    int cur_happy = N - 1 - seg_cnt;
    int ans;
    if (2 * K >= seg_cnt) {
        ans = N - 1;
    } else {
        ans = cur_happy + 2 * K;
    }
    
    printf("%d\n", ans);
    return 0;
}

// <END-OF-CODE>
