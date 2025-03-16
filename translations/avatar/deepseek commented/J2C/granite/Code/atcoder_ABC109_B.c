
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N); // Step 1: Read the input value N
    
    char** map = (char**)malloc(sizeof(char*) * N); // Step 2: Allocate memory for the array of strings
    for (int i = 0; i < N; i++) {
        map[i] = (char*)malloc(sizeof(char) * 101); // Step 3: Allocate memory for each string
        scanf("%s", map[i]);
    }
    
    int ans = 1; // Step 4: Initialize a variable 'ans'
    char** past = (char**)malloc(sizeof(char*) * N); // Step 5: Allocate memory for the 'past' array
    char* next = (char*)malloc(sizeof(char) * 2); // Step 6: Allocate memory for the 'next' string
    
    for (int i = 0; i < N; i++) { // Step 7: Loop through the strings
        int found = 0;
        for (int j = 0; j < i; j++) { // Step 8: Check if the current string has been seen before
            if (strcmp(map[i], past[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (found) { // Step 9: Check if the current string has been seen before
            ans = 0;
            break;
        }
        past[i] = (char*)malloc(sizeof(char) * 101);
        strcpy(past[i], map[i]); // Step 10: Store the current string in the 'past' array
        
        if (i!= 0) { // Step 11: Check if it's not the first string
            if (map[i][0]!= next[0]) { // Check if the starting character matches
                ans = 0;
                break;
            }
        }
        next[0] = map[i][strlen(map[i]) - 1]; // Step 12: Update 'next'
        next[1] = '\0';
    }
    
    if (ans) { // Step 13: Check the value of 'ans'
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    for (int i = 0; i < N; i++) { // Step 14: Free the memory allocated for the strings and arrays
        free(map[i]);
        free(past[i]);
    }
    free(map);
    free(past);
    free(next);
    
    return 0;
}
