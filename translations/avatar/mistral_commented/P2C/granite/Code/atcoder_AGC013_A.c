
#include <stdio.h>

int main() {
    int N, A[100000], ans = 0, i = 1;
    scanf("%d", &N);
    for (int j = 0; j < N; j++) scanf("%d", &A[j]);
    while (i < N - 1) {
        if ((A[i - 1] < A[i] && A[i] > A[i + 1]) || (A[i - 1] > A[i] && A[i] < A[i + 1])) {
            ans++;
            i++;
        }
        i++;
    }
    printf("%d\n", ans + 1);
    return 0;
}
