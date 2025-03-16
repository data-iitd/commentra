#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000 // Define a maximum size for the array

// Structure to hold the frequency of each integer
typedef struct {
    int value;
    int count;
} Frequency;

int main() {
    int n;
    scanf("%d", &n); // Reading the number of elements in the array

    int ara[MAX_SIZE]; // Creating an integer array of size n
    Frequency freq[MAX_SIZE]; // Array to hold unique elements and their frequencies
    int uniqueCount = 0; // Count of unique elements

    // Reading elements of the array and updating the frequency
    for (int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v); // Reading an integer from the input
        ara[i] = v; // Storing the integer in the array

        // Check if the integer is already present in the frequency array
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (freq[j].value == v) {
                freq[j].count++; // Increment frequency
                found = 1;
                break;
            }
        }
        if (!found) {
            freq[uniqueCount].value = v; // Add new unique element
            freq[uniqueCount].count = 1; // Initialize frequency to 1
            uniqueCount++;
        }
    }

    // Finding the maximum frequency
    int max = 0;
    for (int i = 0; i < uniqueCount; i++) {
        if (freq[i].count > max) {
            max = freq[i].count; // Update max with the maximum frequency found
        }
    }

    // Finding the element(s) with the maximum frequency
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < uniqueCount; j++) {
            if (ara[i] == freq[j].value && freq[j].count == max) {
                printf("%d\n", ara[i]); // Print the element with maximum frequency
                goto end; // Break out of the loop
            }
        }
    }

end:
    return 0; // End of the program
}

// <END-OF-CODE>
