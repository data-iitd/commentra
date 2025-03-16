
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Initialize variables to read input from the console
    char input[1000];
    fgets(input, 1000, stdin);
    
    // Parse the number of movements (m), start position (s), and final position (f)
    int m, s, f;
    sscanf(input, "%*d %d %d", &m, &s, &f);
    
    // Initialize maxT to keep track of the maximum time step
    int maxT = -1;
    
    // Create a HashMap to store the movements at each time step
    int **movements = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        movements[i] = (int *)malloc(2 * sizeof(int));
    }
    
    // Read the movements for each time step
    for (int i = 0; i < m; i++) {
        fgets(input, 1000, stdin);
        sscanf(input, "%d %d %d", &movements[i][0], &movements[i][1], &movements[i][2]);
        maxT = movements[i][0] > maxT? movements[i][0] : maxT;
    }
    
    // Prepare a StringBuilder to store the actions taken
    char *actions = (char *)malloc(maxT * sizeof(char));
    
    // Determine the direction of movement based on start and final positions
    char M = (s < f)? 'R' : 'L';
    int d = (s < f)? +1 : -1;
    
    // Initialize current position to start position
    int cur = s;
    int a, b;
    
    // Iterate through each time step from 1 to maxT
    for (int t = 1; t <= maxT; t++) {
        a = -1;
        b = -1;
        
        // Check if there are movements defined for the current time step
        for (int i = 0; i < m; i++) {
            if (movements[i][0] == t) {
                a = movements[i][1];
                b = movements[i][2];
            }
        }
        
        // Check if the current position or the next position is within the movement range
        if (a!= -1 && ((cur >= a && cur <= b) || (cur + d >= a && cur + d <= b))) {
            actions[t - 1] = 'X'; // Append 'X' if within the range
        } else {
            actions[t - 1] = M; // Append the movement direction
            cur += d; // Update the current position
        }
        
        // Break the loop if the current position reaches the final position
        if (cur == f) break;
    }
    
    // Continue moving until the current position reaches the final position
    while (cur!= f) {
        actions[t - 1] = M; // Append the movement direction
        cur += d; // Update the current position
    }
    
    // Output the sequence of actions taken
    printf("%s\n", actions);
    
    // Free memory
    for (int i = 0; i < m; i++) {
        free(movements[i]);
    }
    free(movements);
    free(actions);
    
    return 0;
}

