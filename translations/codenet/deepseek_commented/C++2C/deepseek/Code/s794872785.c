#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <complex.h>
#include <assert.h>

// Function to solve the problem
int solve(){
    // Initialize variables to track the longest string and its count
    int maxsize=0;
    int maxcnt=0;
    int ans_num; // Index of the longest string
    int ans_num2; // Index of the most frequent string
    char **str_v; // Array to store input strings
    int str_v_size = 0; // Size of the array
    
    // Variable to read input strings
    char in[1000];
    str_v = (char **)malloc(1000 * sizeof(char *)); // Allocate memory for the array
    for(int i = 0; i < 1000; i++) {
        str_v[i] = (char *)malloc(1000 * sizeof(char)); // Allocate memory for each string
    }
    
    // Read input strings
    while(scanf("%s", in) != EOF){
        strcpy(str_v[str_v_size], in); // Store the input string in the array
        if(maxsize < strlen(in)){ // Check if the current string is the longest so far
            maxsize = strlen(in); // Update the length of the longest string
            ans_num = str_v_size; // Store the index of the longest string
        }
        str_v_size++; // Increment the size of the array
    }
    
    // Count occurrences of each string and find the most frequent string
    for(int i=0;i<str_v_size;i++){
        int cnt=0;
        for(int j=0;j<str_v_size;j++){
            if(strcmp(str_v[i], str_v[j]) == 0) cnt++; // Count occurrences of the current string
        }
        if(maxcnt < cnt){ // Check if the current string is the most frequent so far
            maxcnt = cnt; // Update the count of the most frequent string
            ans_num2 = i; // Store the index of the most frequent string
        }
    }
    
    // Output the most frequent and the longest string
    printf("%s %s\n", str_v[ans_num2], str_v[ans_num]);
    
    // Free allocated memory
    for(int i = 0; i < 1000; i++) {
        free(str_v[i]); // Free each string
    }
    free(str_v); // Free the array
    
    return 0; // Return 0 indicating success
}

// Main function to set precision and call the solve function
int main(){
    printf("%.10f\n", 0.0); // This line is just a placeholder to match the original C++ code
    solve();

    return 0;
}
