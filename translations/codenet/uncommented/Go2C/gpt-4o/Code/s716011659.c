#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 10000000000.0

int main() {
    int n;
    scanf("%d", &n);

    int *arrA = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arrA[i]);
    }

    int *cumSumA = (int *)malloc((n + 1) * sizeof(int));
    cumSumA[0] = 0;
    for (int i = 0; i < n; i++) {
        cumSumA[i + 1] = cumSumA[i] + arrA[i];
    }

    double ans = INF;
    for (int i = 1; i < n; i++) {
        double diff = fabs(cumSumA[n] - (cumSumA[i] * 2));
        if (diff < ans) {
            ans = diff;
        }
    }

    printf("%d\n", (int)ans);

    free(arrA);
    free(cumSumA);
    return 0;
}

// <END-OF-CODE>
