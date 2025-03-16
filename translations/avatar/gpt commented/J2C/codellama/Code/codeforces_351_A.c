#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

// Main function definition
int main() { 
    // Initialize variables for input and output
    int n, i, non_int = 0; 
    double sum_before = 0, sum = 0, max_sum, min_sum, ans; 
    char *line = NULL; 
    size_t len = 0; 
    ssize_t read; 
    
    // Read the number of elements (n)
    read = getline(&line, &len, stdin); 
    n = atoi(line); 
    
    // Allocate memory for the array
    double *arr = (double *)malloc(2 * n * sizeof(double)); 
    
    // Read the input line containing the numbers
    read = getline(&line, &len, stdin); 
    
    // Tokenize the input line containing the numbers
    char *token = strtok(line, " "); 
    
    // Loop through the input numbers
    for (i = 0; i < 2 * n; i++) { 
        // Parse the next number from the input
        double num = atof(token); 
        
        // Accumulate the total sum of the numbers
        sum_before += num; 
        
        // Check if the number is non-integer and update the counter
        if (num != floor(num)) 
            non_int++; 
        
        // Accumulate the sum of the integer parts of the numbers
        sum += floor(num); 
        
        // Store the number in the array
        arr[i] = num; 
        
        // Get the next token
        token = strtok(NULL, " "); 
    } 
    
    // Calculate the maximum possible sum considering non-integer values
    max_sum = (n < non_int) ? sum + n - non_int : sum; 
    
    // Calculate the minimum possible sum considering non-integer values
    min_sum = (non_int < n) ? sum + non_int - n : sum; 
    
    // Determine the answer based on the calculated sums
    if (min_sum > sum_before) 
        ans = (min_sum - sum_before); // Case where min_sum is greater than the total sum
    else if (max_sum < sum_before) 
        ans = (sum_before - max_sum); // Case where max_sum is less than the total sum
    else { 
        // Case where the total sum is between min_sum and max_sum
        double x = sum_before - floor(sum_before); 
        ans = (x < 1 - x) ? x : 1 - x; // Calculate the minimum distance to the nearest integer
    } 
    
    // Print the final answer formatted to three decimal places
    printf("%.3f", ans); 
    
    // Free the allocated memory
    free(arr); 
    free(line); 
    
    return 0; 
} 

