#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function to read an integer from input
int ri() {
    char line[MAX_LINE_LENGTH];
    fgets(line, sizeof(line), stdin);
    int n = 0;
    for (int i = 0; i < strlen(line); i++) {
        if (line[i] >= '0' && line[i] <= '9') {
            n = n * 10 + (line[i] - '0');
        }
    }
    return n;
}

// Function to calculate the average of an array of float numbers
float ave(float *s, int n) {
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += s[i];
    }
    return sum / n;
}

// Function to calculate the absolute difference between two float numbers
float diff(float a, float b) {
    if (a > b) {
        return a - b;
    }
    return b - a;
}

int main() {
    int n = ri();
    float a[n];
    for (int i = 0; i < n; i++) {
        a[i] = ri();
    }

    // Calculate the average of the numbers
    float ave_val = ave(a, n);

    // Initialize variables to track the minimum difference and the corresponding index
    float minDiff = 999999.9;
    int ansIndex = -1;
    for (int i = 0; i < n; i++) {
        float diff_val = diff(a[i], ave_val);
        if (diff_val < minDiff) {
            minDiff = diff_val;
            ansIndex = i;
        }
    }
    // Print the index of the value closest to the average
    printf("%d\n", ansIndex);
    return 0;
}
