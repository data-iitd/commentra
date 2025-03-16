#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LEN 10
<<<<<<< HEAD
#define MAX_COMMAND_LEN 13
=======
#define MAX_CMD_LEN 13
>>>>>>> 98c87cb78a (data updated)
#define MAX_ENTRIES 1000

// Structure to represent a string entry in the map
typedef struct {
    char str[MAX_STR_LEN];
    int present; // 1 if present, 0 if not
} Entry;

<<<<<<< HEAD
int main() {
    // Declare variables for input and an array to store string entries
    int n; // Number of commands to process
    char str[MAX_STR_LEN], com[MAX_COMMAND_LEN]; // Arrays to hold command and string inputs
    Entry entries[MAX_ENTRIES]; // Array to track the presence of strings
    int entry_count = 0; // Count of current entries
=======
Entry map[MAX_ENTRIES];
int count = 0; // Number of entries in the map

// Function to check if a string exists in the map
int exists(const char *str) {
    for (int i = 0; i < count; i++) {
        if (strcmp(map[i].str, str) == 0) {
            return 1; // String exists
        }
    }
    return 0; // String does not exist
}

// Function to insert a string into the map
void insert(const char *str) {
    if (!exists(str)) {
        strcpy(map[count].str, str);
        map[count].present = 1; // Mark as present
        count++;
    }
}

int main() {
    int n; // Number of commands to process
    char str[MAX_STR_LEN], com[MAX_CMD_LEN]; // Arrays to hold command and string inputs
>>>>>>> 98c87cb78a (data updated)

    // Read the number of commands from input
    scanf("%d", &n);
    
    // Loop through each command
    for (int i = 0; i < n; i++) {
        // Read the command and the associated string
        scanf("%s %s", com, str);
        
        // Check if the command is 'insert' (indicated by the first character being 'i')
        if (com[0] == 'i') {
<<<<<<< HEAD
            // Insert the string into the entries array
            int found = 0;
            for (int j = 0; j < entry_count; j++) {
                if (strcmp(entries[j].str, str) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(entries[entry_count].str, str);
                entries[entry_count].present = 1;
                entry_count++;
            }
        } else {
            // If the command is not 'insert', check if the string exists in the entries
            int found = 0;
            for (int j = 0; j < entry_count; j++) {
                if (strcmp(entries[j].str, str) == 0 && entries[j].present) {
                    found = 1;
                    break;
                }
            }
            // Print "yes" or "no" based on the presence of the string
            if (found) {
                printf("yes\n");
            } else {
=======
            // Insert the string into the map
            insert(str);
        } else {
            // If the command is not 'insert', check if the string exists in the map
            if (exists(str)) {
                // If the string exists, print "yes"
                printf("yes\n");
            } else {
                // If the string does not exist, print "no"
>>>>>>> 98c87cb78a (data updated)
                printf("no\n");
            }
        }
    }
    
    // Return 0 to indicate successful execution
    return 0;
}

// <END-OF-CODE>
