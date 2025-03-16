#include <stdio.h>
#include <math.h>

double dist(int *x, int *y, int d) {
    double tmp = 0.0;
    for (int i = 0; i < d; i++) {
        tmp += (x[i] - y[i]) * (x[i] - y[i]);
    }
    return sqrt(tmp);
}

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
            if (dist(points[i], points[j], d) == (int)dist(points[i], points[j], d)) {
                count++;
            }
        }
    }

    printf("%d\n", count);
    return 0;
}

// <END-OF-CODE>
