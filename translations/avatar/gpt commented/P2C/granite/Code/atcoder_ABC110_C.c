
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the frequency of each character in a string
int* count_frequency(char* str) {
    int* freq = (int*)malloc(256 * sizeof(int));
    memset(freq, 0, 256 * sizeof(int));
    
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        freq[str[i]]++;
    }
    
    return freq;
}

// Function to compare the frequency distributions of two strings
int compare_frequency(int* freq1, int* freq2) {
    for (int i = 0; i < 256; i++) {
        if (freq1[i]!= freq2[i]) {
            return 0;  // Return 0 if the frequency distributions are different
        }
    }
    
    return 1;  // Return 1 if the frequency distributions are the same
}

// Main function to read input strings and print the result
int main() {
    char s[1000];
    char t[1000];
    
    // Read input strings s and t from the user
    scanf("%s", s);
    scanf("%s", t);
    
    // Count the frequency of each character in strings s and t
    int* freq_s = count_frequency(s);
    int* freq_t = count_frequency(t);
    
    // Compare the frequency distributions of strings s and t
    int result = compare_frequency(freq_s, freq_t);
    
    // Print the result
    if (result == 1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    
    // Free the memory allocated for frequency arrays
    free(freq_s);
    free(freq_t);
    
    return 0;
}

