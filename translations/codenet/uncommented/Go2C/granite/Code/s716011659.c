
#include <stdio.h>
#include <math.h>

const double inf = 10000000000.0;

int main() {
    int n;
    scanf("%d", &n);

    int arrA[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arrA[i]);
    }

    int cumSumA[n+1];
    cumSumA[0] = 0;
    for (int i = 0; i < n; i++) {
        cumSumA[i+1] = cumSumA[i] + arrA[i];
    }

    double ans = inf;
    for (int i = 1; i < n; i++) {
        double diff = fabs(cumSumA[n] - cumSumA[i]*2);
        if (diff < ans) {
            ans = diff;
        }
    }

    printf("%d\n", (int)ans);

    return 0;
}
