#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>

int main() {
    int N;
    long K;
    scanf("%d %ld", &N, &K);
    int A[N];
    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        A[i]--;
    }
    int idx[N];
    int pos[N];
    int next = 0, cur = 0;
    while(1) {
        if(idx[next]!= -1) {
            break;
        }
        idx[next] = cur;
        pos[cur] = next;
        next = A[next];
        cur++;
    }
    long a = cur - idx[next];
    long b = idx[next];
    int ans = (int)((10000 * a + K - b) % a + b);
    if(b > K) {
        ans = (int)K;
    }
    printf("%d\n", pos[ans] + 1);
    return 0;
}
