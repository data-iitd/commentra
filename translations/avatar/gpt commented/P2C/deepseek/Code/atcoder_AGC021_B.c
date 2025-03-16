#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    int N, i, j;
    scanf("%d", &N);
    
    double XY[N][2];
    for (i = 0; i < N; i++) {
        scanf("%lf %lf", &XY[i][0], &XY[i][1]);
    }
    
    for (i = 0; i < N; i++) {
        double angles[N - 1];
        int index = 0;
        
        for (j = 0; j < N; j++) {
            if (i != j) {
                angles[index] = atan2(XY[j][0] - XY[i][0], XY[j][1] - XY[i][1]);
                index++;
            }
        }
        
        // Sort the angles
        qsort(angles, N - 1, sizeof(double), (int (*)(const void *, const void *))compare);
        
        // Append the angle that wraps around (2*pi) to handle circularity
        double D[N];
        for (j = 0; j < N - 1; j++) {
            D[j] = angles[j];
        }
        D[N - 1] = angles[0] + 2 * PI;
        
        // Initialize the answer for the current point
        double ans = 0;
        
        // Calculate the gaps between consecutive angles
        for (j = 0; j < N; j++) {
            double a = D[j];
            double b = D[j + 1];
            // Check if the gap is greater than or equal to pi
            if (b - a >= PI) {
                // Update the answer with the size of the gap minus pi
                if ((b - a) - PI > ans) {
                    ans = (b - a) - PI;
                }
            }
        }
        
        // Print the normalized answer (as a fraction of 2*pi)
        printf("%f\n", ans / (2 * PI));
    }
    
    return 0;
}

int compare(const void *a, const void *b) {
    double diff = (*(double *)a - *(double *)b);
    return (diff > 0) - (diff < 0);
}
