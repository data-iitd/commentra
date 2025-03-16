#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVEMENTS 1000
#define MAX_ACTIONS 2000

typedef struct {
    int start;
    int end;
} Movement;

int main() {
    // Read the first line of input
    char input[100];
    fgets(input, sizeof(input), stdin);
    
    // Parse the number of movements (m), start position (s), and final position (f)
    int m, s, f;
    sscanf(input, "%*s %d %d %d", &m, &s, &f);
    
    // Initialize maxT to keep track of the maximum time step
    int maxT = -1;
    
    // Create an array to store the movements at each time step
    Movement movements[MAX_MOVEMENTS] = {0};
    
    // Read the movements for each time step
    while (m > 0) {
        // Read the movement data for the current time step
        char mth[100];
        fgets(mth, sizeof(mth), stdin);
        
        int k, start, end;
        sscanf(mth, "%d %d %d", &k, &start, &end);
        
        // Store the movement range
        movements[k].start = start;
        movements[k].end = end;
        
        // Update maxT to the highest time step encountered
        if (k > maxT) {
            maxT = k;
        }
        m--;
    }
    
    // Prepare a buffer to store the actions taken
    char actions[MAX_ACTIONS];
    int actionIndex = 0;
    
    // Determine the direction of movement based on start and final positions
    char M = (s < f) ? 'R' : 'L';
    int d = (s < f) ? 1 : -1;
    
    // Initialize current position to start position
    int cur = s;
    
    // Iterate through each time step from 1 to maxT
    for (int t = 1; t <= maxT; t++) {
        int a = movements[t].start;
        int b = movements[t].end;
        
        // Check if the current position or the next position is within the movement range
        if ((cur >= a && cur <= b) || (cur + d >= a && cur + d <= b)) {
            actions[actionIndex++] = 'X'; // Append 'X' if within the range
        } else {
            actions[actionIndex++] = M; // Append the movement direction
            cur += d; // Update the current position
        }
        
        // Break the loop if the current position reaches the final position
        if (cur == f) break;
    }
    
    // Continue moving until the current position reaches the final position
    while (cur != f) {
        actions[actionIndex++] = M; // Append the movement direction
        cur += d; // Update the current position
    }
    
    // Null-terminate the actions string
    actions[actionIndex] = '\0';
    
    // Output the sequence of actions taken
    printf("%s\n", actions);
    
    return 0;
}

// <END-OF-CODE>
