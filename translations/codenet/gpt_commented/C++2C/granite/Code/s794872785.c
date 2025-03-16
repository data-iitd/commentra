
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Function to solve the problem of finding the longest and most frequent string
bool solve(){
    // Initialize variables to track the maximum size of strings and their counts
    int maxsize = 0; // To store the length of the longest string
    int maxcnt = 0;  // To store the count of the most frequent string
    int ans_num;     // Index of the longest string
    int ans_num2;    // Index of the most frequent string
    char** str_v; // Array to store input strings
    
    char in[100]; // Variable to hold each input string
    // Read strings from standard input until EOF
    while(scanf("%s", in)!= EOF){
        str_v[i] = (char*)malloc(strlen(in)+1); // Allocate memory for the string and copy it
        strcpy(str_v[i], in); // Copy the input string to the allocated memory
        // Check if the current string is longer than the previously recorded maximum
        if(maxsize < strlen(in)){
            maxsize = strlen(in); // Update the maximum size
            ans_num = i; // Update index of the longest string
        }
    }
    
    // Loop through the array to find the most frequent string
    for(int i = 0; i < i; i++){
        int cnt = 0; // Counter for occurrences of the current string
        // Count how many times the current string appears in the array
        for(int j = 0; j < i; j++){
            if(strcmp(str_v[i], str_v[j]) == 0) cnt++; // Increment count if a match is found
        }
        // Check if the current count is greater than the previously recorded maximum count
        if(maxcnt < cnt){
            maxcnt = cnt; // Update the maximum count
            ans_num2 = i; // Update index of the most frequent string
        }
    }
    
    // Output the most frequent string and the longest string
    printf("%s %s\n", str_v[ans_num2], str_v[ans_num]);
    
    return true; // Indicate successful execution
}

int main(){
    // Set output format to fixed-point notation with 10 decimal places
    printf("%.10f\n", 3.1415926535);
    
    char** str_v = (char**)malloc(100*sizeof(char*)); // Allocate memory for the array of strings
    
    solve(); // Call the solve function to process input and output results
    
    return 0; // Indicate successful program termination
}

