

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize variables to store the number of elements and the best index
    int n, ans = 500;
    
    // Read the number of elements from standard input
    scanf("%d", &n);
    
    // Initialize a 2D array to store the elements
    int vec[n][4];
    
    // Read the elements into the 2D array
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &vec[i][0], &vec[i][1], &vec[i][2], &vec[i][3]);
    }
    
    // Initialize variables to store the best index and its price
    int ansprice = 200000;
    
    // Loop through each element to find the best one
    for (int i = 0; i < n; i++) {
        int fl = 1; // Flag to check if the element is dominated
        
        // Compare the current element with every other element
        for (int j = 0; j < n; j++) {
            if (vec[i][0] < vec[j][0] && vec[i][1] < vec[j][1] && vec[i][2] < vec[j][2]) {
                fl = 0; // The element is dominated
            }
        }
        
        // If the element is not dominated, check its price
        if (fl == 1) {
            if (vec[i][3] < ansprice) {
                ansprice = vec[i][3]; // Update the minimum price
                ans = i + 1; // Update the best index
            }
        }
    }
    
    // Output the index of the best element
    printf("%d\n", ans);
    
    // End of code
    return 0;
}
