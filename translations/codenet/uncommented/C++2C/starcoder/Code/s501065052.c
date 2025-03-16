#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N;
    scanf("%d", &N);
    int mem[N + 1];
    for (int i = 1; i <= N; ++i) {
        int P;
        scanf("%d", &P);
        mem[P] = i;
    }

    int maxcnt = 1;
    int cnt = 1;
    for (int i = 1; i < N; ++i) {
        if (mem[i] < mem[i + 1]) {
            cnt++;
        } else {
            maxcnt = max(maxcnt, cnt);
            cnt = 1;
        }
        if (i == N - 1) {
            maxcnt = max(maxcnt, cnt);
        }
    }
//    cnt = 1;
//    for (int i = N; i > 1; --i) {
//        if(mem[i] > mem[i-1]){
//            cnt++;
//        }
//    }

    printf("%d\n", N - maxcnt);
    return 0;
}
