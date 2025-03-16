
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Function to solve the problem
bool solve(){
    // Initialize variables to track the longest string and its count
    int maxsize=0;
    int maxcnt=0;
    int ans_num; // Index of the longest string
    int ans_num2; // Index of the most frequent string
    char** str_v; // Array to store input strings
    int str_v_size = 0; // Size of the input string array
    
    // Variable to read input strings
    char in[100];
    while(scanf("%s", in)){
        str_v = (char**)realloc(str_v, sizeof(char*) * (str_v_size + 1)); // Allocate memory for the input string array
        str_v[str_v_size] = (char*)malloc(strlen(in) + 1); // Allocate memory for the current input string
        strcpy(str_v[str_v_size], in); // Copy the input string to the array
        str_v_size++; // Increment the size of the input string array
        if(maxsize < strlen(in)){ // Check if the current string is the longest so far
            maxsize = strlen(in); // Update the length of the longest string
            ans_num = str_v_size-1; // Store the index of the longest string
        }
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
    
    // Free memory allocated for the input string array
    for(int i=0;i<str_v_size;i++){
        free(str_v[i]);
    }
    free(str_v);
    
    return true; // Return true indicating success
}

// Main function to set precision and call the solve function
int main(){
    printf("%.10f\n", 1.0);
    solve();

    return 0;
}

