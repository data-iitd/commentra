#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 256

// Function to count occurrences of each character in a string
void count_colors(const char *line, int *count) {
    while (*line) {
        count[(unsigned char)(*line)]++;
        line++;
    }
}

int solution() {
    // Read the first line of input and create a count array for the bought colors
    char bought_line[1001];
    fgets(bought_line, sizeof(bought_line), stdin);
    int bought_count[MAX_COLORS] = {0};
    count_colors(bought_line, bought_count);
    
    // Read the second line of input and create a count array for the colors to be made
    char made_line[1001];
    fgets(made_line, sizeof(made_line), stdin);
    int made_count[MAX_COLORS] = {0};
    count_colors(made_line, made_count);
    
    // Initialize the result variable to store the total number of colors that can be made
    int res = 0;
    
    // Iterate over each color in the 'made_count' array
    for (int i = 0; i < MAX_COLORS; i++) {
        if (made_count[i] > 0) {
            // Check if the color is not in the 'bought_count' array
            if (bought_count[i] == 0) {
                // If a color is not bought, print -1 and exit
                return -1;
            }
            // Calculate the minimum of the counts of the current color in both 'bought_count' and 'made_count'
            // and add this to the result
            res += (bought_count[i] < made_count[i]) ? bought_count[i] : made_count[i];
        }
    }
    
    // Print the final result
    printf("%d\n", res);
    return 0;
}

int main() {
    // Set the number of test cases to 1
    int t = 1;
    // Run the solution function for one test case
    for (int i = 0; i < t; i++) {
        if (solution() == -1) {
            printf("-1\n");
        }
    }
    return 0;
}

// <END-OF-CODE>
