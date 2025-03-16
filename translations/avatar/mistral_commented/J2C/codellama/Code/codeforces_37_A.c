
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT 1000000

// Structure for storing the input integers
typedef struct {
    int val;
    int count;
} IntCount;

// Structure for storing the input integers and their counts
typedef struct {
    IntCount *arr;
    int size;
} IntCountArray;

// Function to read the input integers and their counts
IntCountArray readInput() {
    int n;
    scanf("%d", &n);

    IntCountArray arr = {(IntCount *)malloc(n * sizeof(IntCount)), n};

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr.arr[i].val);
        arr.arr[i].count = 1;
    }

    return arr;
}

// Function to find the maximum value and the size of the HashMap
void findMaxAndSize(IntCountArray arr, int *max, int *size) {
    *max = INT_MIN;
    *size = 0;

    for (int i = 0; i < arr.size; i++) {
        if (arr.arr[i].count > *max) {
            *max = arr.arr[i].count;
        }
        *size += 1;
    }
}

// Function to print the maximum value and the size of the HashMap
void printOutput(int max, int size) {
    printf("%d %d\n", max, size);
}

int main() {
    IntCountArray arr = readInput();

    int max, size;
    findMaxAndSize(arr, &max, &size);
    printOutput(max, size);

    return 0;
}

