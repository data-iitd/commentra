#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int main() {
    // Declare pointers for storing team names and initialize scores
    char **t, **h;
    int n, taro = 0, hanako = 0, i;

    // Read the number of rounds (n) from input
    scanf("%d", &n);

    // Allocate memory for team names for both players
    t = malloc(n * sizeof(char *));
    h = malloc(n * sizeof(char *));
    
    // Loop through each round to read team names and calculate scores
    for (i = 0; i < n; i++) {
        // Allocate memory for each team name (up to 100 characters)
        t[i] = malloc(100 * sizeof(char));
        h[i] = malloc(100 * sizeof(char));
        
        // Read team names for both players
        scanf("%s", t[i]);
        scanf("%s", h[i]);
        
        // Compare team names and update scores based on the comparison
        if (strcmp(t[i], h[i]) < 0) {
            // If Hanako's team name is lexicographically smaller, she gets 3 points
            hanako += 3;
        }
        if (strcmp(t[i], h[i]) > 0) {
            // If Taro's team name is lexicographically larger, he gets 3 points
            taro += 3;
        }
        if (strcmp(t[i], h[i]) == 0) {
            // If both team names are the same, both players get 1 point
            taro += 1;
            hanako += 1;
        }
        
        // Free the allocated memory for team names after processing
        free(t[i]);
        free(h[i]);
    }
    
    // Output the final scores of Taro and Hanako
    printf("%d %d\n", taro, hanako);
    
    // Free the memory allocated for the pointers to team names
    free(t);
    free(h);
    
    return 0;
}
