#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

// Function to count the frequency of characters in the string
void count_frequency(const char *s, int *freq) {
    for (int i = 0; s[i] != '\0'; i++) {
        freq[(unsigned char)s[i]]++;
    }
}

// Main function to solve the problem
int main() {
    // Read input string from the user
    char s[100001]; // Assuming the maximum length of the string is 100000
    scanf("%s", s);
    
    // Check if all characters in the string are the same
    if (strlen(s) == 1) {
        printf("0\n");
        return 0;
    }

    // Count the frequency of each character in the string
    int freq[MAX_CHAR] = {0};
    count_frequency(s, freq);
    
    // Find the minimum frequency of any character
    int min_freq = MAX_CHAR; // Initialize to a large value
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] > 0 && freq[i] < min_freq) {
            min_freq = freq[i];
        }
    }

    // Calculate the answer as twice the minimum frequency of any character
    int ans = min_freq * 2;

    // Print the answer and exit
    printf("%d\n", ans);
    
    return 0;
}

// <END-OF-CODE>
