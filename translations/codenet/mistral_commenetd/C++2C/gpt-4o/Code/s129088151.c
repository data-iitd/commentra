#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STR_LEN 10
#define MAX_COM_LEN 13
#define MAX_ENTRIES 1000

// Declare variables
int n;
char str[MAX_STR_LEN], com[MAX_COM_LEN];
char map_keys[MAX_ENTRIES][MAX_STR_LEN];
bool map_values[MAX_ENTRIES];
int map_size = 0; // To keep track of the number of entries in the map

// Function to check if a string exists in the map
bool exists_in_map(const char *key) {
    for (int i = 0; i < map_size; i++) {
        if (strcmp(map_keys[i], key) == 0) {
            return true;
        }
    }
    return false;
}

// Function to add a string to the map
void add_to_map(const char *key) {
    if (map_size < MAX_ENTRIES) {
        strcpy(map_keys[map_size], key);
        map_values[map_size] = true; // Set the value to true
        map_size++;
    }
}

int main() {
    // Read the number of input pairs from the standard input
    scanf("%d", &n);

    // Iterate through each input pair
    for (int i = 0; i < n; i++) {
        // Read the command and the string from the standard input
        scanf("%s %s", com, str);

        // If the command is 'i', add the string to the map
        if (com[0] == 'i') {
            add_to_map(str); // Add the string to the map
        }
        // If the command is not 'i', check if the string is present in the map
        else {
            if (exists_in_map(str)) { // Check if the string is present in the map
                printf("yes\n"); // If present, print 'yes'
            } else {
                printf("no\n"); // If not present, print 'no'
            }
        }
    }
    // Return 0 to indicate successful execution of the program
    return 0;
}

// <END-OF-CODE>
