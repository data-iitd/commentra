
#include <stdio.h>
#include <math.h>

int main() {
    int n, d;
    scanf("%d %d", &n, &d);

    int points[n][d];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            scanf("%d", &points[i][j]);
        }
    }

    double dist(int *x, int *y) {
        double tmp = 0.0;
        for (int i = 0; i < d; i++) {
            tmp += pow(x[i] - y[i], 2);
        }
        return sqrt(tmp);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dist(points[i], points[j]) == (int)dist(points[i], points[j])) {
                count++;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}
