#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* find(const char* s, char ch, int* count) {
    // This function returns an array of indices where the character 'ch' appears in the string 's'.
    int length = strlen(s);
    int* indices = (int*)malloc(length * sizeof(int));
    *count = 0;

    for (int i = 0; i < length; i++) {
        if (s[i] == ch) {
            indices[(*count)++] = i;
        }
    }
    return indices;
}

int main() {
    // Read an integer input 'n' which represents the length of the string.
    int n;
    scanf("%d", &n);
    
    // Read the string input 's'.
    char* s = (char*)malloc((n + 1) * sizeof(char));
    scanf("%s", s);
    
    // Check if the string 's' contains the character '0'.
    if (strchr(s, '0') == NULL) {
        // If '0' is not present, the output is n - 1.
        printf("%d\n", n - 1);
    } else {
        // Find all indices of '0' in the string 's'.
        int count = 0;
        int* indices = find(s, '0', &count);
        
        // If there is only one '0', output the length of the string 'n'.
        if (count == 1) {
            printf("%d\n", n);
        } else {
            // Initialize a variable to keep track of the maximum value found.
            int maximum = 0;

            // Iterate through each combination of indices.
            for (int i = 0; i < count; i++) {
                for (int j = i + 1; j < count; j++) {
                    // Calculate the maximum value based on the distance between the two indices.
                    int dist = abs(indices[i] - indices[j]);
                    maximum = (maximum > (2 + 2 * (j - i - 1) - (dist - 1))) ? maximum : (2 + 2 * (j - i - 1) - (dist - 1));
                }
            }
            
            // Output the count of '1's in the string plus the maximum value calculated.
            int count_of_ones = 0;
            for (int k = 0; k < n; k++) {
                if (s[k] == '1') {
                    count_of_ones++;
                }
            }
            printf("%d\n", count_of_ones + maximum);
            free(indices);
        }
    }
    
    free(s);
    return 0;
}

// <END-OF-CODE>
