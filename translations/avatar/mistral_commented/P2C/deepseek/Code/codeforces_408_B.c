#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 26

// Function to find the solution
void solution() {
    // Read the first line and count the number of occurrences of each color
    char line[1001];
    scanf("%s", line);
    int bought_count[MAX_COLORS] = {0};
    for (int i = 0; line[i] != '\0'; i++) {
        bought_count[line[i] - 'a']++;
    }

    // Read the second line and count the number of occurrences of each color
    scanf("%s", line);
    int made_count[MAX_COLORS] = {0};
    for (int i = 0; line[i] != '\0'; i++) {
        made_count[line[i] - 'a']++;
    }

    // Initialize result to 0
    int res = 0;

    // Iterate through each color in made_count
    for (int i = 0; i < MAX_COLORS; i++) {
        // Check if the color is present in bought_count
        if (made_count[i] > 0 && bought_count[i] == 0) {
            // If not, print -1 and exit the function
            printf("-1\n");
            return;
        }

        // Update the result by adding the minimum of bought and made counts
        if (bought_count[i] > 0 && made_count[i] > 0) {
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
    scanf("%d", &t);

    // Run the solution function for each test case
    for (int i = 0; i < t; i++) {
        solution();
    }

    return 0;
}
