#include <stdio.h>
#include <math.h>

// Function to calculate the Euclidean distance
double calculateDistance(int x, int y) {
    return sqrt(x * x + y * y);
}

// Function to read an integer array from the input
int* readIntArray(int* N, int* D) {
    scanf("%d %d", N, D);
    int* points = (int*)malloc(*N * 2 * sizeof(int));
    for (int i = 0; i < *N; i++) {
        scanf("%d %d", &points[i * 2], &points[i * 2 + 1]);
    }
    return points;
}

// Function to count the number of points within the square
int countPoints(int N, int D, int* points) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        double distance = calculateDistance(points[i * 2], points[i * 2 + 1]);
        if (distance <= D) {
            count++;
        }
    }
    free(points);
    return count;
}

int main() {
    int N, D;
    int* points = readIntArray(&N, &D);
    int result = countPoints(N, D, points);
    printf("%d\n", result);
    return 0;
}
