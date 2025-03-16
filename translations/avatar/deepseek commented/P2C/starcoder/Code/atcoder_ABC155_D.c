#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int A[N];
    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int ll = -1000000000, rr = 1000000000;
    while(ll + 1 < rr) {
        int x = (ll + rr) / 2;
        int tot = 0;
        for(int i = 0; i < N; i++) {
            if(A[i] < 0) {
                int l = -1, r = N;
                while(l + 1 < r) {
                    int c = (l + r) / 2;
                    if(A[i] * A[c] < x) {
                        r = c;
                    } else {
                        l = c;
                    }
                }
                tot += N - r;
            } else {
                int l = -1, r = N;
                while(l + 1 < r) {
                    int c = (l + r) / 2;
                    if(A[i] * A[c] < x) {
                        l = c;
                    } else {
                        r = c;
                    }
                }
                tot += r;
            }
            if(A[i] * A[i] < x) {
                tot -= 1;
            }
        }
        tot /= 2;
        if(tot < K) {
            ll = x;
        } else {
            rr = x;
        }
    }
    printf("%d\n", ll);
    return 0;
}

