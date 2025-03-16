#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// Function to read a specified number of lines from input
char** read(int len) { 
    char** strList = (char**)malloc(len * sizeof(char*)); 
    for (int i = 0; i < len; i++) { 
        strList[i] = (char*)malloc(100 * sizeof(char)); 
        scanf("%s", strList[i]); 
    } 
    return strList; 
} 

// Function to close the BufferedReader
void close() { 
    // Do nothing
} 

int main() { 
    // Read the first input as an integer
    int n; 
    scanf("%d", &n); 
    
    // Check if the input is 1
    if (n == 1) { 
        // If the input is 1, print "Hello World"
        printf("Hello World\n"); 
    } else { 
        // If the input is not 1, read two more strings
        char** strs = read(2); 
        // Parse the two strings as integers and print their sum
        printf("%d\n", atoi(strs[0]) + atoi(strs[1])); 
    } 
    // Close the BufferedReader
    close(); 
    return 0; 
} 

