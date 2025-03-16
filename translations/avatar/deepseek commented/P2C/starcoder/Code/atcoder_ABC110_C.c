
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the run function that takes two arguments, s and t
bool run(char *s, char *t) {
    // Create a Counter object for s, sort its values, and store them in ss
    int *ss = (int *)malloc(sizeof(int) * strlen(s));
    // Create a Counter object for t, sort its values, and store them in tt
    int *tt = (int *)malloc(sizeof(int) * strlen(t));
    // Create a Counter object for t, sort its values, and store them in tt
    for (int i = 0; i < strlen(s); i++) {
        // Iterate over the length of s
        ss[i] = 0;
        // Set the value of ss to 0
        for (int j = 0; j < strlen(s); j++) {
            // Iterate over the length of s
            if (s[i] == s[j]) {
                // Check if the current character of s is equal to the current character of s
                ss[i]++;
                // If so, increment the value of ss by 1
            }
        }
    }
    for (int i = 0; i < strlen(t); i++) {
        // Iterate over the length of t
        tt[i] = 0;
        // Set the value of tt to 0
        for (int j = 0; j < strlen(t); j++) {
            // Iterate over the length of t
            if (t[i] == t[j]) {
                // Check if the current character of t is equal to the current character of t
                tt[i]++;
                // If so, increment the value of tt by 1
            }
        }
    }
    for (int i = 0; i < strlen(s); i++) {
        // Iterate over the length of s
        if (ss[i]!= tt[i]) {
            // Check if the current value of ss is not equal to the current value of tt
            free(ss);
            free(tt);
            // Free the memory allocated to ss and tt
            return false;
            // Return false
        }
    }
    free(ss);
    free(tt);
    // Free the memory allocated to ss and tt
    return true;
    // Return true
}

// Define the main function to get input and print the result
int main() {
    // Get input for s from the user
    char *s = (char *)malloc(sizeof(char) * 1000);
    scanf("%s", s);
    // Get input for t from the user
    char *t = (char *)malloc(sizeof(char) * 1000);
    scanf("%s", t);
    // Call the run function with s and t as arguments and print the result
    printf("%s\n", run(s, t)? "Yes" : "No");
    // Free the memory allocated to s and t
    free(s);
    free(t);
    // Free the memory allocated to s and t
    return 0;
    // Return 0
}

// 