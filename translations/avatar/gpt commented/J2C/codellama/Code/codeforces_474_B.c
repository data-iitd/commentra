#include <stdio.h> 
#include <stdlib.h> 

int main() 
{ 
    // Create a Scanner object to read input from the console
    int n, m, i, j, k, md, res; 
    scanf("%d", &n); 
    
    // Read the number of elements in the array
    int arr[n]; 
    
    // Read the first element and assign it to the first index of the array
    scanf("%d", &arr[0]); 
    
    // Populate the array with cumulative sums
    for (i = 1; i < n; i++) { 
        // Read the next integer and add it to the previous cumulative sum
        int x; 
        scanf("%d", &x); 
        arr[i] = x + arr[i - 1]; 
    } 
    
    // Read the number of queries
    scanf("%d", &m); 
    
    // Initialize the array to store the queries
    int q[m]; 
    
    // Read each query into the array
    for (i = 0; i < m; i++) 
        scanf("%d", &q[i]); 
    
    // Process each query and print the result
    for (k = 0; k < m; k++) { 
        i = 0; 
        j = n; 
        
        // Perform binary search to find the appropriate index
        while (i <= j) { 
            md = i + (j - i) / 2; 
            
            // If the middle element is equal to the query, return the index
            if (arr[md] == q[k]) 
                break; 
            // If the middle element is greater than the query, adjust the search range
            else if (arr[md] > q[k]) { 
                res = md; 
                j = md - 1; 
            } else 
                i = md + 1; 
        } 
        
        // Return the last found index where the cumulative sum is less than the query
        printf("%d\n", res); 
    } 
    
    return 0; 
} 

