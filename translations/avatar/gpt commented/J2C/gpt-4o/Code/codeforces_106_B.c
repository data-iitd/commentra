#include <stdio.h>

int main() {
    // Read the number of entries
    int n;
    scanf("%d", &n);
    
    // Initialize a 2D array to store the input values
    int vec[n][4];
    
    // Read input values into the 2D array
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &vec[i][0], &vec[i][1], &vec[i][2], &vec[i][3]); // Read values
    }
    
    // Initialize variables to track the best option
    int ans = 500; // Default answer if no valid option is found
    int ansprice = 20000; // Set a high initial price
    
    // Iterate through each entry to find the best option
    for (int i = 0; i < n; i++) {
        int fl = 1; // Flag to check if the current entry is not dominated
        
        // Check if the current entry is dominated by any other entry
        for (int j = 0; j < n; j++) {
            if (vec[i][0] < vec[j][0] && vec[i][1] < vec[j][1] && vec[i][2] < vec[j][2]) {
                fl = 0; // Set flag to 0 if dominated
                break; // No need to check further if dominated
            }
        }
        
        // If the current entry is not dominated, check its price
        if (fl == 1) {
            if (vec[i][3] < ansprice) {
                ansprice = vec[i][3]; // Update the best price found
                ans = i + 1; // Update the answer with the current index (1-based)
            }
        }
    }
    
    // Output the result
    printf("%d\n", ans);
    
    return 0; // End of the program
}

// <END-OF-CODE>
