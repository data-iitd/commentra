#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main() {
    int n, d;
    scanf("%d %d", &n, &d);

    int points[n][d];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            scanf("%d", &points[i][j]);
        }
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double tmp = 0.0;
            for (int k = 0; k < d; k++) {
                tmp += pow(points[i][k] - points[j][k], 2);
            }
            if (sqrt(tmp) == (int)sqrt(tmp)) {
                count++;
            }
        }
    }

    printf("%d\n", count);
    return 0;
}
