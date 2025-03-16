#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 256

// Function to count occurrences of each color
void count_colors(const char *line, int *count) {
    for (int i = 0; line[i] != '\0'; i++) {
        count[(unsigned char)line[i]]++;
    }
}

// Function to find the solution
void solution() {
    char bought_line[1001];
    char made_line[1001];
    
    // Read the first line and count the number of occurrences of each color
    fgets(bought_line, sizeof(bought_line), stdin);
    int bought_count[MAX_COLORS] = {0};
    count_colors(bought_line, bought_count);

    // Read the second line and count the number of occurrences of each color
    fgets(made_line, sizeof(made_line), stdin);
    int made_count[MAX_COLORS] = {0};
    count_colors(made_line, made_count);

    // Initialize result to 0
    int res = 0;

    // Iterate through each color in made_count
    for (int i = 0; i < MAX_COLORS; i++) {
        if (made_count[i] > 0) {
            // Check if the color is present in bought_count
            if (bought_count[i] == 0) {
                // If not, print -1 and exit the function
                printf("-1\n");
                return;
            }
            // Update the result by adding the minimum of bought and made counts
            res += (bought_count[i] < made_count[i]) ? bought_count[i] : made_count[i];
        }
    }

    // Print the result
    printf("%d\n", res);
}

// Main function to run the solution function for multiple test cases
int main() {
    // Read the number of test cases
    int t;
    scanf("%d\n", &t);

    // Run the solution function for each test case
    for (int i = 0; i < t; i++) {
        solution();
    }

    return 0;
}

// <END-OF-CODE>
