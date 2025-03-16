#include <stdio.h>
#include <math.h>

// Helper functions
int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x < y ? x : y;
}

int pow(int x, int y) {
    return (int)pow(x, y);
}

int abs(int x) {
    return x < 0 ? -x : x;
}

int floor(double x) {
    return (int)floor(x);
}

// Main function is the entry point of our program
int main() {
    // Declare and initialize variables
    int N, M, ans;

    // Read N and M from the standard input
    scanf("%d %d", &N, &M);

    // Check if N and M are equal to 1
    if (N == 1 && M == 1) {
        // If so, increment the ans variable
        ans = 1;
    } else if (N > 1 && M > 1) {
        // If N and M are greater than 1, calculate the area of the rectangle
        ans = (N - 2) * (M - 2);
    } else {
        // If N or M is equal to 1, calculate the number of points on the edge
        ans = (N * M) - 2;
    }

    // Print the value of ans to the standard output
    printf("%d\n", ans);

    return 0;
}

// Helper type and function for sorting a slice of integers based on their absolute values
typedef struct {
    int* arr;
    int len;
} SortBy;

int compare(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return abs(x) - abs(y);
}

void sortByAbs(SortBy* s) {
    qsort(s->arr, s->len, sizeof(int), compare);
}
