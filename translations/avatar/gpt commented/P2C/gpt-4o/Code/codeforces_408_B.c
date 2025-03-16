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
    char bought[1001], made[1001];
    int bought_count[MAX_COLORS] = {0};
    int made_count[MAX_COLORS] = {0};
    int res = 0;

    // Read the first line of input which represents the colors bought
    fgets(bought, sizeof(bought), stdin);
    bought[strcspn(bought, "\n")] = 0; // Remove newline character
    count_colors(bought, bought_count);

    // Read the second line of input which represents the colors made
    fgets(made, sizeof(made), stdin);
    made[strcspn(made, "\n")] = 0; // Remove newline character
    count_colors(made, made_count);

    // Iterate through each color in made_count
    for (int i = 0; i < MAX_COLORS; i++) {
        if (made_count[i] > 0) {
            // If a color made is not found in the bought colors, return -1
            if (bought_count[i] == 0) {
                return -1;
            }
            // Add the minimum of the bought and made counts for each color to the result
            res += (bought_count[i] < made_count[i]) ? bought_count[i] : made_count[i];
        }
    }

    // Print the total count of matched colors
    printf("%d\n", res);
    return 0;
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

// <END-OF-CODE>
