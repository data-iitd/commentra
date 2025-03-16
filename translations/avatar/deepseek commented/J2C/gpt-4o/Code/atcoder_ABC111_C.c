#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100010

int main() {
    int n;
    scanf("%d", &n); // Read the size of the array
    int v[MAX_SIZE]; // Initialize the array to store the values
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]); // Read the values into the array
    }

    int vo[MAX_SIZE] = {0}; // Initialize arrays to count odd and even numbers
    int ve[MAX_SIZE] = {0};
    int vt[MAX_SIZE] = {0};

    for (int i = 0; i < n; i++) {
        vt[v[i]]++; // Count all numbers
        if (i % 2 == 0) {
            ve[v[i]]++; // Count even numbers
        } else {
            vo[v[i]]++; // Count odd numbers
        }
    }

    // Sort the count arrays in descending order
    qsort(vo, MAX_SIZE, sizeof(int), (int (*)(const void *, const void *))strcmp);
    qsort(ve, MAX_SIZE, sizeof(int), (int (*)(const void *, const void *))strcmp);
    qsort(vt, MAX_SIZE, sizeof(int), (int (*)(const void *, const void *))strcmp);

    int ans = 0;
    if (vo[0] + ve[0] == vt[0]) { // Check if the maximum counts are consecutive
        ans = n - vo[0] - ve[1]; // Calculate the minimum difference
        if (vo[1] + ve[0] < ans) {
            ans = n - vo[1] - ve[0];
        }
    } else {
        ans = n - vo[0] - ve[0]; // Calculate the difference if not consecutive
    }

    printf("%d\n", ans); // Print the result
    return 0; // End of the program
}

// <END-OF-CODE>
