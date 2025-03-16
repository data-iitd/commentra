

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int* C = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &C[i]);
    }

    int* P = (int*)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i <= n; i++) {
        P[i] = -1;
    }

    int* Answers = (int*)malloc(sizeof(int) * q);

    int k = 0;
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);

        for (int j = k; j < r; j++) {
            if (P[C[j]]!= -1) {
                // FenwickTree update
            }
            P[C[j]] = j;
            // FenwickTree update
        }

        for (int j = l - 1; j < r; j++) {
            // FenwickTree query
        }

        Answers[i] = result;
        k = r;
    }

    for (int i = 0; i < q; i++) {
        printf("%d\n", Answers[i]);
    }

    free(C);
    free(P);
    free(Answers);

    return 0;
}
