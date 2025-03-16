#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

// Structure to hold the frequency of each integer
typedef struct {
    int key;
    int value;
} HashMapEntry;

HashMapEntry map[MAX_SIZE];
int size = 0;

// Function to find the frequency of a number in the hashmap
int getFrequency(int key) {
    for (int i = 0; i < size; i++) {
        if (map[i].key == key) {
            return map[i].value;
        }
    }
    return 0;
}

// Function to add or update the frequency of a number in the hashmap
void put(int key) {
    for (int i = 0; i < size; i++) {
        if (map[i].key == key) {
            map[i].value++;
            return;
        }
    }
    // If key not found, add a new entry
    map[size].key = key;
    map[size].value = 1;
    size++;
}

int main() {
    int n;
    scanf("%d", &n); // Read the number of integers

    // Read n integers and update their counts in the hash map
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        put(val);
    }

    // Initialize max to the smallest possible integer value
    int max = 0;

    // Iterate through the hash map to find the maximum count
    for (int i = 0; i < size; i++) {
        if (map[i].value > max) {
            max = map[i].value;
        }
    }

    // Print the maximum count and the size of the hash map
    printf("%d %d\n", max, size);

    return 0;
}

// <END-OF-CODE>
