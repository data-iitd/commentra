#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main() { 
    // Initialize variables
    int m, s, f, k, a, b, cur, d; 
    char M; 
    char *input, *mth; 
    char *actions; 
    int maxT = -1; 
    int t; 
    int i; 
    int *movements; 
    int *movement; 
    
    // Read the first line of input and split it into an array
    input = (char *) malloc(100 * sizeof(char)); 
    scanf("%s", input); 
    m = atoi(strtok(input, " ")); 
    s = atoi(strtok(NULL, " ")); 
    f = atoi(strtok(NULL, " ")); 
    
    // Create a HashMap to store the movements at each time step
    movements = (int *) malloc(m * 2 * sizeof(int)); 
    
    // Read the movements for each time step
    for (i = 0; i < m; i++) { 
        // Read the movement data for the current time step
        mth = (char *) malloc(100 * sizeof(char)); 
        scanf("%s", mth); 
        k = atoi(strtok(mth, " ")); 
        movement = movements + (i * 2); 
        movement[0] = atoi(strtok(NULL, " ")); 
        movement[1] = atoi(strtok(NULL, " ")); 
        
        // Update maxT to the highest time step encountered
        maxT = (maxT > k) ? maxT : k; 
    } 
    
    // Prepare a StringBuilder to store the actions taken
    actions = (char *) malloc(100 * sizeof(char)); 
    
    // Determine the direction of movement based on start and final positions
    M = (s < f) ? 'R' : 'L'; 
    d = (s < f) ? +1 : -1; 
    
    // Initialize current position to start position
    cur = s; 
    
    // Iterate through each time step from 1 to maxT
    for (t = 1; t <= maxT; t++) { 
        // Check if there are movements defined for the current time step
        if (movements[t * 2] != 0) { 
            a = movements[t * 2]; // Get the start of the movement range
            b = movements[t * 2 + 1]; // Get the end of the movement range
        } 
        
        // Check if the current position or the next position is within the movement range
        if (movements[t * 2] != 0 && ((cur >= a && cur <= b) || (cur + d >= a && cur + d <= b))) { 
            strcat(actions, "X"); // Append 'X' if within the range
        } else { 
            strcat(actions, &M); // Append the movement direction
            cur += d; // Update the current position
        } 
        
        // Break the loop if the current position reaches the final position
        if (cur == f) break; 
    } 
    
    // Continue moving until the current position reaches the final position
    while (cur != f) { 
        strcat(actions, &M); // Append the movement direction
        cur += d; // Update the current position
    } 
    
    // Output the sequence of actions taken
    printf("%s\n", actions); 
    
    // Free memory
    free(input); 
    free(mth); 
    free(actions); 
    free(movements); 
    
    return 0; 
}

