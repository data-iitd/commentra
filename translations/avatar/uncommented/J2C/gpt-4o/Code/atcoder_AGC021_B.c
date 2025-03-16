#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    return (*(double *)a > *(double *)b) - (*(double *)a < *(double *)b);
}

int main() {
    int N;
    scanf("%d", &N);
    
    int *x = (int *)malloc(N * sizeof(int));
    int *y = (int *)malloc(N * sizeof(int));
    
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &x[i], &y[i]);
    }
    
    for (int i = 0; i < N; ++i) {
        double *thetas = (double *)malloc((N - 1) * sizeof(double));
        int count = 0;
        
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            thetas[count++] = atan2(y[j] - y[i], x[j] - x[i]);
        }
        
        qsort(thetas, count, sizeof(double), compare);
        thetas[count] = thetas[0] + 2 * M_PI; // Add the wrap-around angle
        
        double ans = 0;
        for (int k = 0; k < count - 1; ++k) {
            ans = fmax(ans, thetas[k + 1] - thetas[k] - M_PI);
        }
        
        printf("%lf\n", ans / (M_PI * 2));
        free(thetas);
    }
    
    free(x);
    free(y);
    
    return 0;
}
