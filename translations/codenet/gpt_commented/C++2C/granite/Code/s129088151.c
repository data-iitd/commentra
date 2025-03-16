
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int main() {
    // Declare variables for input and a map to store string entries
    int n; // Number of commands to process
    char str[10], com[13]; // Arrays to hold command and string inputs
    bool *T; // Pointer to an array to track the presence of strings (true if present)

    // Read the number of commands from input
    scanf("%d", &n);
    
    // Allocate memory for the boolean array
    T = (bool*)malloc(n * sizeof(bool));
    
    // Loop through each command
    for (int i = 0; i < n; i++) {
        // Read the command and the associated string
        scanf("%s%s", com, str);
        
        // Check if the command is 'insert' (indicated by the first character being 'i')
        if (com[0] == 'i') {
            // Insert the string into the map with a value of true
            T[i] = true;
        } else {
            // If the command is not 'insert', check if the string exists in the map
            if (T[i]) {
                // If the string exists, print "yes"
                printf("yes\n");
            } else {
                // If the string does not exist, print "no"
                printf("no\n");
            }
        }
    }
    
    // Free the allocated memory
    free(T);
    
    // Return 0 to indicate successful execution
    return 0;
}
