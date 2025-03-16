#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main() { 
    // Create a Scanner object to read input from the user
    int N; 
    scanf("%d", &N); 
    
    // Initialize arrays to store the x and y coordinates of the points
    int x[N]; 
    int y[N]; 
    
    // Read the coordinates of the points from user input
    for (int i = 0; i < N; ++i) { 
        scanf("%d %d", &x[i], &y[i]); 
    } 
    
    // Iterate over each point to calculate the angles with respect to other points
    for (int i = 0; i < N; ++i) { 
        // Create a list to store the angles (thetas) for the current point
        double thetas[N]; 
        
        // Calculate the angle between the current point and all other points
        for (int j = 0; j < N; ++j) { 
            // Skip the current point itself
            if (i == j) continue; 
            
            // Calculate the angle using atan2 and add it to the list
            thetas[j] = atan2(y[j] - y[i], x[j] - x[i]); 
        } 
        
        // Sort the angles in ascending order
        qsort(thetas, N, sizeof(double), compare); 
        
        // Add the angle that wraps around (2 * PI) to handle circularity
        thetas[N] = thetas[0] + 2 * M_PI; 
        
        // Initialize a variable to find the maximum angle difference
        double ans = 0; 
        
        // Calculate the maximum angle difference between consecutive angles
        for (int k = 0; k < N - 1; ++k) 
            ans = fmax(ans, thetas[k + 1] - thetas[k] - M_PI); 
        
        // Output the result as a fraction of the full circle (2 * PI)
        printf("%.10lf\n", ans / (M_PI * 2)); 
    } 
    
    return 0; 
} 

int compare(const void *a, const void *b) { 
    return (*(double *)a - *(double *)b); 
} 

