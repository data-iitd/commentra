#include <stdio.h> // Include the standard C library for input/output operations
#include <string.h> // Include the string library for string manipulation
#include <stdlib.h> // Include the standard library for memory allocation
#include <stdbool.h> // Include the library for boolean type
<<<<<<< HEAD
#include <ctype.h> // Include the library for character handling

#define MAX_STR_LEN 10 // Define the maximum length for strings
#define MAX_CMD_LEN 13 // Define the maximum length for commands
#define MAX_ENTRIES 1000 // Define the maximum number of entries in the map

// Structure to represent a key-value pair in the map
typedef struct {
    char key[MAX_STR_LEN];
    bool value;
} Entry;

// Function to check if a string exists in the map
bool exists(Entry map[], int size, const char *str) {
    for (int i = 0; i < size; i++) {
        if (strcmp(map[i].key, str) == 0) {
            return true; // String found
        }
    }
    return false; // String not found
=======

#define MAX_STRINGS 10000 // Define a maximum number of strings
#define MAX_LENGTH 10 // Define the maximum length of each string

typedef struct {
    char strings[MAX_STRINGS][MAX_LENGTH]; // Array to store strings
    bool present[MAX_STRINGS]; // Array to track presence of strings
    int count; // Count of unique strings
} StringMap; // Define a structure to represent the map

void init(StringMap *map) {
    map->count = 0; // Initialize the count of strings to 0
    for (int i = 0; i < MAX_STRINGS; i++) {
        map->present[i] = false; // Initialize presence array to false
    }
}

int find(StringMap *map, const char *str) {
    for (int i = 0; i < map->count; i++) {
        if (strcmp(map->strings[i], str) == 0) {
            return i; // Return the index if the string is found
        }
    }
    return -1; // Return -1 if the string is not found
}

void insert(StringMap *map, const char *str) {
    if (find(map, str) == -1) { // If the string is not already present
        strcpy(map->strings[map->count], str); // Copy the string to the array
        map->present[map->count] = true; // Mark it as present
        map->count++; // Increment the count of strings
    }
>>>>>>> 98c87cb78a (data updated)
}

int main() {
    int n; // Declare an integer variable to store the number of operations
<<<<<<< HEAD
    char str[MAX_STR_LEN], com[MAX_CMD_LEN]; // Declare character arrays to store commands and strings
    Entry map[MAX_ENTRIES]; // Declare an array of entries to store the presence of strings
    int size = 0; // Variable to keep track of the number of entries in the map
=======
    char str[MAX_LENGTH], com[13]; // Declare character arrays to store commands and strings
    StringMap T; // Declare a StringMap to store the presence of strings

    init(&T); // Initialize the StringMap
>>>>>>> 98c87cb78a (data updated)

    scanf("%d", &n); // Read the number of operations from the user
    for (int i = 0; i < n; i++) { // Loop through each operation
        scanf("%s %s", com, str); // Read the command and the string
<<<<<<< HEAD
        if (com[0] == 'i') { // If the command is 'i'
            // Insert the string into the map if it doesn't already exist
            if (!exists(map, size, str)) {
                strcpy(map[size].key, str); // Copy the string into the map
                map[size].value = true; // Set the value to true
                size++; // Increment the size of the map
            }
        } else { // If the command is not 'i'
            if (exists(map, size, str)) // Check if the string is present in the map
                printf("yes\n"); // Print 'yes'
            else
                printf("no\n"); // Print 'no'
=======
        if (com[0] == 'i') {
            insert(&T, str); // If the command is 'i', insert the string into the map
        } else { // If the command is not 'i'
            if (find(&T, str) != -1) {
                printf("yes\n"); // Check if the string is present in the map and print 'yes'
            } else {
                printf("no\n"); // If the string is not present, print 'no'
            }
>>>>>>> 98c87cb78a (data updated)
        }
    }
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
