#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function to read an integer from input
int readInt() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to read a line of input and split it into integers
void readLine(int *x, int *y) {
    scanf("%d %d", x, y);
}

// Function to calculate the number of points within distance D from the origin
void countPoints(int N, int D) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        int x, y;
        readLine(&x, &y);
        double distance = sqrt(x * x + y * y);
        if (distance <= D) {
            count++;
        }
    }
    printf("%d\n", count);
}

// Main function
int main() {
    int N, D;
    // Read the first line of input containing N and D
    scanf("%d %d", &N, &D);
    // Count the points within distance D
    countPoints(N, D);
    return 0;
}

// <END-OF-CODE>
