#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int find(char *s, char ch) {
    // This function returns a list of indices where the character 'ch' appears in the string 's'.
    int i, j, k;
    int *indices = (int *)malloc(sizeof(int) * strlen(s));
    k = 0;
    for (i = 0; i < strlen(s); i++) {
        if (s[i] == ch) {
            indices[k] = i;
            k++;
        }
    }
    return indices;
}

int main() {
    // Read an integer input 'n' which represents the length of the string.
    int n;
    scanf("%d", &n);
    
    // Read the string input 's' and replace any empty string occurrences (this line seems to be incorrect).
    char s[n];
    scanf("%s", s);
    
    // Check if the string 's' contains the character '0'.
    if (strchr(s, '0') == NULL) {
        // If '0' is not present, the output is n - 1.
        printf("%d\n", n - 1);
    } else {
        // Find all indices of '0' in the string 's'.
        int *indices = find(s, '0');
        
        // If there is only one '0', output the length of the string 'n'.
        if (strchr(s, '0') == strrchr(s, '0')) {
            printf("%d\n", n);
        } else {
            // Initialize a variable to keep track of the maximum value found.
            int maximum = 0;
            
            // Generate all combinations of indices of '0' taken 2 at a time.
            int i, j, k;
            for (i = 0; i < strlen(s); i++) {
                for (j = i + 1; j < strlen(s); j++) {
                    // Calculate the maximum value based on the distance between the two indices.
                    maximum = max(maximum, 2 + 2 * (abs(indices[i] - indices[j]) - 1) - (abs(i - j) - 1));
                }
            }
            
            // Output the count of '1's in the string plus the maximum value calculated.
            printf("%d\n", strlen(s) - strlen(strchr(s, '1')) + maximum);
        }
    }
    return 0;
}

