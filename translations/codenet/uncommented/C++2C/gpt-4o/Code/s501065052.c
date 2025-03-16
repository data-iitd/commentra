#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);
    int mem[N + 1];
<<<<<<< HEAD
    
=======
>>>>>>> 98c87cb78a (data updated)
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
            if (maxcnt < cnt) {
                maxcnt = cnt;
            }
            cnt = 1;
        }
        if (i == N - 1) {
            if (maxcnt < cnt) {
                maxcnt = cnt;
            }
        }
    }

    printf("%d\n", N - maxcnt);
    return 0;
}
// <END-OF-CODE>
