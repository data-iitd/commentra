#include <stdio.h>

int main() {
    int N, ans, i, count;
    scanf("%d", &N);
    int A[N];
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    i = 0;
    ans = 0;
    count = 0;
    while (A[i + 1] != 0) {
        if (A[i] == A[i + 1]) {
            count++;
            if (count % 2 != 0)
                ans++;
        } else {
            count = 0;
        }
        i++;
    }

    printf("%d\n", ans);
    return 0;
}
