#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>

using namespace std;

int main() {
    // Declare pointers for storing team names and initialize scores
    char **t, **h;
    int n, taro = 0, hanako = 0, i;

    // Read the number of rounds (n) from input
    cin >> n;

    // Allocate memory for team names for both players
    t = (char **)malloc(n * sizeof(char *));
    h = (char **)malloc(n * sizeof(char *));
    
    // Loop through each round to read team names and calculate scores
    for (i = 0; i < n; i++) {
        // Allocate memory for each team name (up to 100 characters)
        t[i] = (char *)malloc(100 * sizeof(char));
        h[i] = (char *)malloc(100 * sizeof(char));
        
        // Read team names for both players
        cin >> t[i];
        cin >> h[i];
        
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
    cout << taro << " " << hanako << endl;
    
    // Free the memory allocated for the pointers to team names
    free(t);
    free(h);
    
    return 0;
}

