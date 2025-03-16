
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a HashMap entry
typedef struct {
    int key; // The key of the HashMap entry
    int value; // The value of the HashMap entry
} HashMapEntry;

// Define a structure for a HashMap
typedef struct {
    HashMapEntry *entries; // The array of HashMap entries
    int size; // The size of the HashMap
    int capacity; // The capacity of the HashMap
} HashMap;

// Initialize a HashMap with the given capacity
HashMap *initHashMap(int capacity) {
    HashMap *map = (HashMap *) malloc(sizeof(HashMap)); // Allocate memory for the HashMap
    map->entries = (HashMapEntry *) malloc(sizeof(HashMapEntry) * capacity); // Allocate memory for the HashMap entries
    map->size = 0; // Initialize the size of the HashMap to 0
    map->capacity = capacity; // Initialize the capacity of the HashMap
    return map; // Return the HashMap
}

// Add an entry to the HashMap
void addEntry(HashMap *map, int key, int value) {
    HashMapEntry *entry = (HashMapEntry *) malloc(sizeof(HashMapEntry)); // Allocate memory for the HashMap entry
    entry->key = key; // Set the key of the HashMap entry
    entry->value = value; // Set the value of the HashMap entry
    map->entries[map->size] = *entry; // Add the HashMap entry to the HashMap
    map->size++; // Increment the size of the HashMap
}

// Get the value of the entry with the given key from the HashMap
int getValue(HashMap *map, int key) {
    for (int i = 0; i < map->size; i++) { // Iterate through the HashMap entries
        if (map->entries[i].key == key) { // Check if the current entry's key is equal to the given key
            return map->entries[i].value; // Return the value of the current entry
        }
    }
    return -1; // Return -1 if the given key is not found in the HashMap
}

// Get the maximum value of the HashMap
int getMaxValue(HashMap *map) {
    int max = -1; // Initialize the maximum value to -1
    for (int i = 0; i < map->size; i++) { // Iterate through the HashMap entries
        max = max > map->entries[i].value? max : map->entries[i].value; // Update the maximum value if the current entry's value is greater than the maximum value
    }
    return max; // Return the maximum value
}

// Get the size of the HashMap
int getSize(HashMap *map) {
    return map->size; // Return the size of the HashMap
}

// Get the capacity of the HashMap
int getCapacity(HashMap *map) {
    return map->capacity; // Return the capacity of the HashMap
}

// Resize the HashMap to the given capacity
void resizeHashMap(HashMap *map, int capacity) {
    HashMapEntry *entries = (HashMapEntry *) malloc(sizeof(HashMapEntry) * capacity); // Allocate memory for the HashMap entries
    for (int i = 0; i < map->size; i++) { // Iterate through the HashMap entries
        entries[i] = map->entries[i]; // Add the current entry to the HashMap entries
    }
    free(map->entries); // Free the memory of the HashMap entries
    map->entries = entries; // Set the HashMap entries to the new HashMap entries
    map->capacity = capacity; // Set the capacity of the HashMap to the given capacity
}

// Main function
int main() {
    int n; // Number of integers
    scanf("%d", &n); // Read the number of integers from the standard input

    HashMap *map = initHashMap(n); // Initialize a HashMap with the given capacity

    // Iterate through the given number of integers and add each integer to the HashMap with its count
    for (int i = 0; i < n; i++) {
        int val; // Current integer
        scanf("%d", &val); // Read the next integer from the standard input
        int count = getValue(map, val); // Get the count of the current integer from the HashMap
        if (count == -1) { // Check if the current integer is the first occurrence
            addEntry(map, val, 1); // Add the current integer to the HashMap with its count
        } else {
            addEntry(map, val, count + 1); // Add the current integer to the HashMap with its count
        }
    }

    // Print the maximum value and the size of the HashMap
    printf("%d %d\n", getMaxValue(map), getSize(map));

    free(map->entries); // Free the memory of the HashMap entries
    free(map); // Free the memory of the HashMap
    return 0;
}

