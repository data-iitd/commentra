#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

int main() { 
    // Set up input and output streams
    FILE *inputStream = stdin; 
    FILE *outputStream = stdout; 
    char buffer[1000000]; 
    char *token; 
    int a, b, c, d; 
    
    // Read four integers from input
    fgets(buffer, 1000000, inputStream); 
    token = strtok(buffer, " "); 
    a = atoi(token); 
    token = strtok(NULL, " "); 
    b = atoi(token); 
    token = strtok(NULL, " "); 
    c = atoi(token); 
    token = strtok(NULL, " "); 
    d = atoi(token); 
    
    // Check conditions to determine the output
    if (c > b) { 
        // If c is greater than b, output 0
        fprintf(outputStream, "0\n"); 
    } else if (a > d) { 
        // If a is greater than d, output 0
        fprintf(outputStream, "0\n"); 
    } else if (a < c) { 
        // If a is less than c, calculate and output the difference
        fprintf(outputStream, "%d\n", (int)min(b, d) - c); 
    } else { 
        // Create a list to hold the four integers
        int l[4]; 
        l[0] = a; 
        l[1] = b; 
        l[2] = c; 
        l[3] = d; 
        
        // Sort the list to find the second largest and third largest values
        qsort(l, 4, sizeof(int), compare); 
        
        // Output the difference between the second largest and third largest values
        fprintf(outputStream, "%d\n", l[2] - l[1]); 
    } 
    
    return 0; 
} 

// Function to compare two integers
int compare(const void *a, const void *b) { 
    return (*(int *)a - *(int *)b); 
} 

// Function to find the minimum of two integers
int min(int a, int b) { 
    return (a < b) ? a : b; 
} 

// End of code
