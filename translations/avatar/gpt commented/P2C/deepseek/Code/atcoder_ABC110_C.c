#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the frequency of each character in a string and return an array of frequencies
int* count_frequencies(const char* str) {
    int* freq = (int*)calloc(26, sizeof(int));  // Array to store frequencies of characters a-z
    for (int i = 0; str[i] != '\0'; i++) {
        freq[str[i] - 'a']++;
    }
    return freq;
}

// Function to compare two arrays of frequencies
int compare_arrays(const int* arr1, const int* arr2, int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return 0;  // Arrays are not equal
        }
    }
    return 1;  // Arrays are equal
}

// Function to run the comparison of character frequencies
const char* run(const char* s, const char* t) {
    int* ss = count_frequencies(s);
    int* tt = count_frequencies(t);
    
    // Sort the frequency arrays (in this case, they are already sorted since they are arrays of counts)
    
    // Compare the frequency arrays
    if (compare_arrays(ss, tt, 26)) {
        free(ss);
        free(tt);
        return "Yes";  // Return "Yes" if the frequency distributions are the same
    } else {
        free(ss);
        free(tt);
        return "No";   // Return "No" if the frequency distributions are different
    }
}

// Main function to read input and print the result
void main() {
    char s[1000], t[1000];  // Buffer to read input strings
    
    // Read input strings s and t from the user
    scanf("%s", s);
    scanf("%s", t);
    
    // Print the result of the run function which checks the character frequency
    printf("%s\n", run(s, t));
}

