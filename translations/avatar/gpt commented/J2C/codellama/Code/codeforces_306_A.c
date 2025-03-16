#include <stdio.h> 
#include <stdlib.h> 

int main() { 
    // Read two integers n and m from user input
    int n, m; 
    scanf("%d %d", &n, &m); 
    
    // Initialize an array of size m to hold the results
    int a[m]; 
    
    // Check if n is divisible by m
    if (n % m == 0) { 
        // If divisible, fill the array with equal parts
        for (int i = 0; i < m; i++) { 
            a[i] = n / m; 
        } 
    } else { 
        // If not divisible, calculate the base value for each part
        int sub = n / m; 
        for (int i = 0; i < m; i++) { 
            a[i] = sub; 
        } 
        
        // Calculate the remainder that needs to be distributed
        int test = n - (sub * m); 
        int count = 0; 
        
        // Distribute the remainder across the first few elements of the array
        for (int i = 0; i < test; i++) { 
            a[count] = a[count] + 1; 
            count++; 
            
            // Wrap around if count exceeds the array length
            if (count >= m) count = 0; 
        } 
    } 
    
    // Print the array in reverse order
    for (int i = (m - 1); i >= 0; i--) { 
        printf("%d ", a[i]); 
    } 
    
    return 0; 
} 
