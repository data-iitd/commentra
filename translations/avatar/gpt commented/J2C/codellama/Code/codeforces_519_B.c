#include <stdio.h> 
#include <stdlib.h> 

int main() 
{ 
    // Create a Scanner object to read input from the console
    int n; 
    scanf("%d", &n); 
    
    // Read the number of elements to be processed
    int a = 0, b = 0, c = 0; 
    
    // Read n integers and calculate their sum (a)
    for (int i = 0; i < n; i++) 
        scanf("%d", &a); 
    
    // Read n-1 integers and calculate their sum (b)
    for (int i = 0; i < n - 1; i++) 
        scanf("%d", &b); 
    
    // Read n-2 integers and calculate their sum (c)
    for (int i = 0; i < n - 2; i++) 
        scanf("%d", &c); 
    
    // Calculate the difference between the sums: x = sum of first set - sum of second set
    int x = a - b; 
    
    // Calculate the difference between the sums: y = sum of second set - sum of third set
    int y = b - c; 
    
    // Print the results of the differences
    printf("%d\n", x); 
    printf("%d\n", y); 
    
    return 0; 
} 
