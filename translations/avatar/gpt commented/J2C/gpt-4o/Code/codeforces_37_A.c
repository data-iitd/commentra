#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

// Structure to hold the frequency of each integer
typedef struct {
    int value;
    int count;
} Frequency;

Frequency freqMap[MAX_SIZE];
int uniqueCount = 0;

// Function to find the frequency of an integer
int findFrequency(int val) {
    for (int i = 0; i < uniqueCount; i++) {
        if (freqMap[i].value == val) {
            return i;
        }
    }
    return -1; // Not found
}

int main() {
    int n;
    scanf("%d", &n); // Read the number of integers

    // Read the integers and populate the frequency map
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val); // Read the integer

        int index = findFrequency(val);
        if (index != -1) {
            // If the integer is already in the map, increment its count
            freqMap[index].count++;
        } else {
            // If it's a new integer, add it to the map
            freqMap[uniqueCount].value = val;
            freqMap[uniqueCount].count = 1;
            uniqueCount++;
        }
    }

    // Find the maximum frequency
    int maxFrequency = 0;
    for (int i = 0; i < uniqueCount; i++) {
        if (freqMap[i].count > maxFrequency) {
            maxFrequency = freqMap[i].count;
        }
    }

    // Print the maximum frequency and the number of unique integers
    printf("%d%d\n", maxFrequency, uniqueCount);

    return 0;
}

// <END-OF-CODE>
