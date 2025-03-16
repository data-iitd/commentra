#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 1000

int min(int a, int b) {
    return a < b ? a : b;
}

void solution() {
    // Read the first line of input which represents the colors bought
    char bought_colors[MAX_COLORS + 1];
    fgets(bought_colors, MAX_COLORS + 1, stdin);
    
    // Count the occurrences of each color bought using an array
    int bought_count[26] = {0};
    int len = strlen(bought_colors);
    for (int i = 0; i < len; i++) {
        if (bought_colors[i] != '\n') {
            bought_count[bought_colors[i] - 'a']++;
        }
    }
    
    // Read the second line of input which represents the colors made
    char made_colors[MAX_COLORS + 1];
    fgets(made_colors, MAX_COLORS + 1, stdin);
    
    // Count the occurrences of each color made using an array
    int made_count[26] = {0};
    len = strlen(made_colors);
    for (int i = 0; i < len; i++) {
        if (made_colors[i] != '\n') {
            made_count[made_colors[i] - 'a']++;
        }
    }
    
    // Initialize the result variable to store the total count of matched colors
    int res = 0;
    
    // Iterate through each color in the made_count
    for (int i = 0; i < 26; i++) {
        // If a color made is not found in the bought colors, return -1
        if (made_count[i] > 0 && bought_count[i] == 0) {
            printf("-1\n");
            return;
        }
        // Add the minimum of the bought and made counts for each color to the result
        if (made_count[i] > 0 && bought_count[i] > 0) {
            res += min(bought_count[i], made_count[i]);
        }
    }
    
    // Print the total count of matched colors
    printf("%d\n", res);
}

int main() {
    // Set the number of test cases (currently set to 1)
    int t = 1;
    // Loop through each test case
    for (int i = 0; i < t; i++) {
        solution();
    }
    return 0;
}
