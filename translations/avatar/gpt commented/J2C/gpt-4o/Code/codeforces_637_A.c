#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

// Structure to hold the frequency of elements
typedef struct {
    int value;
    int count;
} Element;

int main() {
    int n;
    scanf("%d", &n); // Read the number of elements

    int ara[MAX_SIZE]; // Array to store the elements
    Element freq[MAX_SIZE]; // Array to store unique elements and their frequencies
    int freq_count = 0; // Count of unique elements

    // Read elements and populate the frequency array
    for (int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v);
        ara[i] = v;

        // Check if the element is already in the frequency array
        int found = 0;
        for (int j = 0; j < freq_count; j++) {
            if (freq[j].value == v) {
                freq[j].count++;
                found = 1;
                break;
            }
        }
        // If not found, add it to the frequency array
        if (!found) {
            freq[freq_count].value = v;
            freq[freq_count].count = 1;
            freq_count++;
        }
    }

    // Find the maximum frequency
    int max = 0;
    for (int i = 0; i < freq_count; i++) {
        if (freq[i].count > max) {
            max = freq[i].count;
        }
    }

    // Iterate through the original array to find the first element with maximum frequency
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < freq_count; j++) {
            if (ara[i] == freq[j].value && freq[j].count == max) {
                printf("%d\n", ara[i]);
                return 0; // Exit after finding the first element with maximum frequency
            }
        }
    }

    return 0;
}

// <END-OF-CODE>
