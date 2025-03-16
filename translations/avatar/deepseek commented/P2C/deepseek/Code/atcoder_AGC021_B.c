#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

int main() {
    int N;
    scanf("%d", &N);
    double XY[N][2];
    
    // Read coordinates
    for (int i = 0; i < N; i++) {
        scanf("%lf %lf", &XY[i][0], &XY[i][1]);
    }
    
    for (int i = 0; i < N; i++) {
        double x = XY[i][0];
        double y = XY[i][1];
        
        // Calculate the angles for each point relative to others
        double angles[N - 1];
        int index = 0;
        for (int j = 0; j < N; j++) {
            if (i != j) {
                angles[index++] = atan2(XY[j][0] - x, XY[j][1] - y);
            }
        }
        
        // Sort the angles
        qsort(angles, N - 1, sizeof(double), (int (*)(const void *, const void *))compare);
        
        // Handle circular angles
        double adjusted_angles[N];
        for (int j = 0; j < N - 1; j++) {
            adjusted_angles[j] = angles[j];
        }
        adjusted_angles[N - 1] = angles[0] + 2 * PI;
        
        // Find the maximum gap
        double max_gap = 0;
        for (int j = 0; j < N; j++) {
            double gap = adjusted_angles[j + 1] - adjusted_angles[j];
            if (gap >= PI) {
                if (gap - PI > max_gap) {
                    max_gap = gap - PI;
                }
            }
        }
        
        // Calculate the fraction
        double fraction = max_gap / (2 * PI);
        printf("%.10f\n", fraction);
    }
    
    return 0;
}

int compare(const void *a, const void *b) {
    double diff = (*(double *)a) - (*(double *)b);
    return (diff > 0) - (diff < 0);
}
