
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Read the first line of input which represents the colors bought
    char bought[100001];
    fgets(bought, 100001, stdin);
    // Count the occurrences of each color bought using a hash table
    int bought_count[26] = {0};
    for (int i = 0; bought[i]!= '\0'; i++) {
        bought_count[bought[i] - 'A']++;
    }
    
    // Read the second line of input which represents the colors made
    char made[100001];
    fgets(made, 100001, stdin);
    // Count the occurrences of each color made using a hash table
    int made_count[26] = {0};
    for (int i = 0; made[i]!= '\0'; i++) {
        made_count[made[i] - 'A']++;
    }
    
    // Initialize the result variable to store the total count of matched colors
    int res = 0;
    
    // Iterate through each color in the made_count
    for (int i = 0; i < 26; i++) {
        // If a color made is not found in the bought colors, return -1
        if (made_count[i] > 0 && bought_count[i] == 0) {
            printf("-1\n");
            return 0;
        }
        // Add the minimum of the bought and made counts for each color to the result
        res += (bought_count[i] < made_count[i]? bought_count[i] : made_count[i]);
    }
    
    // Print the total count of matched colors
    printf("%d\n", res);
    
    return 0;
}

