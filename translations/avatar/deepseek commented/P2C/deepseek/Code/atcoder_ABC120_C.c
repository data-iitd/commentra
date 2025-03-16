#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to count the frequency of each character in a string
void count_frequency(int *freq, const char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }
}

// Main function to solve the problem
void main() {
    char s[100001];
    int freq[26] = {0};
    
    // Read input string from the user
    scanf("%s", s);
    
    // Check if all characters in the string are the same
    int all_same = 1;
    for (int i = 1; s[i] != '\0'; i++) {
        if (s[i] != s[0]) {
            all_same = 0;
            break;
        }
    }
    if (all_same) {
        printf("0\n");
        return;
    }
    
    // Count the frequency of each character in the string
    count_frequency(freq, s);
    
    // Calculate the answer as twice the minimum frequency of any character
    int min_freq = freq[0];
    for (int i = 1; i < 26; i++) {
        if (freq[i] > 0 && freq[i] < min_freq) {
            min_freq = freq[i];
        }
    }
    int ans = min_freq * 2;
    
    // Print the answer and exit
    printf("%d\n", ans);
}
