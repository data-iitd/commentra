#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
    int x, y;
} Point;

double calculate_distance(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

double calculate_total_distance(int N, Point points[], int permutation[]) {
    double total_distance = 0.0;
    for (int i = 0; i < N - 1; i++) {
        int f = permutation[i];
        int t = permutation[i + 1];
        total_distance += calculate_distance(points[f], points[t]);
    }
    return total_distance;
}

void solve(int N, Point points[]) {
    int indices[N];
    for (int i = 0; i < N; i++) {
        indices[i] = i;
    }

    double distances[N * N];
    int count = 0;

    do {
        distances[count++] = calculate_total_distance(N, points, indices);
    } while (next_permutation(indices, indices + N));

    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += distances[i];
    }

    double result = sum / count;
    printf("%.10f\n", result);
}

bool next_permutation(int *array, int size) {
    int i = size - 2;
    while (i >= 0 && array[i] >= array[i + 1]) {
        i--;
    }
    if (i < 0) {
        return false;
    }

    int j = size - 1;
    while (array[j] <= array[i]) {
        j--;
    }

    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;

    int left = i + 1;
    int right = size - 1;
    while (left < right) {
        temp = array[left];
        array[left] = array[right];
        array[right] = temp;
        left++;
        right--;
    }

    return true;
}

void main() {
    int N;
    scanf("%d", &N);
    Point points[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }
    solve(N, points);
}

