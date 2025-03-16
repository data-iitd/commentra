#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read an integer
int readInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to read an array of integers
int* readArray(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

// Function to check if the number of days needed to cut the logs of given length is greater than or equal to k
int nei(int mid, int* logsLength, int k, int n) {
    int daysNeeded = 0;
    for (int i = 0; i < n; ++i) {
        daysNeeded += (logsLength[i] + mid - 1) / mid;
        k -= daysNeeded;
        if (k < 0)
            return 0;
    }
    return 1;
}

// Main function to start the program
int main() {
    int n = readInt();
    int k = readInt();

    int min = 1, max = 1e9 + 1000;

    while (min < max) {
        int mid = (min + max) / 2;
        if (nei(mid, readArray(n), k, n))
            max = mid;
        else
            min = mid + 1;
    }

    printf("%d\n", min);
    return 0;
}
