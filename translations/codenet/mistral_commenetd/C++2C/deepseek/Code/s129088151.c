#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare variables
int n;
char str[10], com[13];
typedef struct {
    char key[10];
    int value;
} Entry;

Entry* T[1000000]; // An array to store entries with string keys and boolean values
int size = 0;

// Function to find the index of a string in the array
int find(char* key) {
    for (int i = 0; i < size; i++) {
        if (strcmp(T[i]->key, key) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to add a string to the array
void insert(char* key) {
    Entry* newEntry = (Entry*)malloc(sizeof(Entry));
    strcpy(newEntry->key, key);
    newEntry->value = 1;
    T[size++] = newEntry;
}

int main() {
    // Read the number of input pairs from the standard input
    scanf("%d", &n);

    // Iterate through each input pair
    for (int i = 0; i < n; i++) {
        // Read the command and the string from the standard input
        scanf("%s%s", com, str);

        // If the command is 'i', add the string to the array
        if (com[0] == 'i') {
            if (find(str) == -1) { // Check if the string is not already present in the array
                insert(str); // If not present, add the string to the array
            }
        }
        // If the command is not 'i', check if the string is present in the array and print the result accordingly
        else {
            if (find(str) != -1) { // Check if the string is present in the array
                printf("yes\n"); // If present, print 'yes'
            }
            else {
                printf("no\n"); // If not present, print 'no'
            }
        }
    }
    // Return 0 to indicate successful execution of the program
    return 0;
}
