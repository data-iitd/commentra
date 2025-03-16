#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double ave(double *s, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += s[i];
    }
    return sum / n;
}

double diff(double a, double b) {
    return fabs(a - b);
}

int main() {
    int n;
    scanf("%d", &n); // Reads the number of elements.
    
    double *a = (double *)malloc(n * sizeof(double)); // Allocates memory for n doubles.
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp); // Reads n integers.
        a[i] = (double)temp; // Stores them as doubles.
    }

    double average = ave(a, n); // Calculates the average of the array.

    double minDiff = 999999.9;
    int ansIndex = -1;
    for (int i = 0; i < n; i++) {
        double difference = diff(a[i], average); // Calculates the absolute difference.
        if (difference < minDiff) {
            minDiff = difference;
            ansIndex = i;
        }
    }
    
    printf("%d\n", ansIndex); // Outputs the index with the smallest difference.

    free(a); // Frees the allocated memory.
    return 0;
}

// <END-OF-CODE>
