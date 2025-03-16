
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

int main() { 
    // Initialize variables and allocate memory for arrays
    int n; 
    double *arr; 
    char *line = NULL; 
    size_t len = 0; 
    int non_int = 0; 
    double sum_before = 0, sum = 0; 
    double ans; 
    
    // Read the number of elements (n) from standard input
    if (getline(&line, &len, stdin) == -1) 
        exit(1); 
    n = atoi(line); 
    
    // Allocate memory for the array of numbers
    arr = (double *)malloc(2 * n * sizeof(double)); 
    if (arr == NULL) 
        exit(1); 
    
    // Read the numbers from standard input and tokenize them
    if (getline(&line, &len, stdin) == -1) 
        exit(1); 
    char *token = strtok(line, " "); 
    for (int i = 0; i < 2 * n; i++) { 
        // Parse the next number from the input
        arr[i] = atof(token); 
        
        // Accumulate the total sum of the numbers
        sum_before += arr[i]; 
        
        // Check if the number is non-integer and update the counter
        if (arr[i]!= floor(arr[i])) 
            non_int++; 
        
        // Accumulate the sum of the integer parts of the numbers
        sum += floor(arr[i]); 
        
        // Move to the next token
        token = strtok(NULL, " "); 
    } 
    
    // Free the allocated memory for the input line
    free(line); 
    
    // Calculate the maximum possible sum considering non-integer values
    double max_sum = fmin(n, non_int) + sum; 
    
    // Calculate the minimum possible sum considering non-integer values
    double min_sum = fmax(0, non_int - n) + sum; 
    
    // Determine the answer based on the calculated sums
    if (min_sum > sum_before) 
        ans = (min_sum - sum_before); // Case where min_sum is greater than the total sum
    else if (max_sum < sum_before) 
        ans = (sum_before - max_sum); // Case where max_sum is less than the total sum
    else { 
        // Case where the total sum is between min_sum and max_sum
        double x = sum_before - floor(sum_before); 
        ans = fmin(1 - x, x); // Calculate the minimum distance to the nearest integer
    } 
    
    // Print the final answer formatted to three decimal places
    printf("%.3f", ans); 
    
    // Free the allocated memory for the array of numbers
    free(arr); 
    
    return 0; 
}
