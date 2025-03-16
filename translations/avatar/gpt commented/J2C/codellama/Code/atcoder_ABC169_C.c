#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main() 
{ 
    // Create a Scanner object to read input from the user
    Scanner sc = new Scanner(System.in); 
    
    // Read a long integer value from the user
    long a = sc.nextLong(); 
    
    // Read a string value from the user
    char b[100]; 
    scanf("%s", b); 
    
    // Convert the string to a character array for processing
    char bChar[100]; 
    strcpy(bChar, b); 
    
    // Get the length of the character array
    int length = strlen(bChar); 
    
    // Initialize an empty string to build the integer representation
    char bStr[100]; 
    strcpy(bStr, ""); 
    
    // Loop through each character in the character array
    for (int i = 0; i < length; i++) { 
        // If the character is not a '.', append it to bStr
        if (bChar[i] != '.') { 
            strcat(bStr, bChar[i]); 
        } 
    } 
    
    // Convert the built string (bStr) to an integer
    int bInt = atoi(bStr); 
    
    // Calculate the result by multiplying 'a' with 'bInt' and dividing by 100
    long result = (a * bInt) / 100; 
    
    // Print the result to the console
    printf("%ld", result); 
    
    return 0; 
} 

