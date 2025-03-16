
#include <stdio.h>
#include <string.h>

int find(char *s, char ch) {
    // This function returns the number of occurrences of the character 'ch' in the string's'.
    int count = 0;
    for (int i = 0; s[i]!= '\0'; i++) {
        if (s[i] == ch) {
            count++;
        }
    }
    return count;
}

int main() {
    // Read an integer input 'n' which represents the length of the string.
    int n;
    scanf("%d", &n);
    
    // Read the string input's'.
    char s[n];
    scanf("%s", s);
    
    // Check if the string's' contains the character '0'.
    if (strchr(s, '0') == NULL) {
        // If '0' is not present, the output is n - 1.
        printf("%d\n", n - 1);
    } else {
        // Find all indices of '0' in the string's'.
        int indices[n];
        int count = 0;
        for (int i = 0; s[i]!= '\0'; i++) {
            if (s[i] == '0') {
                indices[count] = i;
                count++;
            }
        }
        
        // If there is only one '0', output the length of the string 'n'.
        if (count == 1) {
            printf("%d\n", n);
        } else {
            // Initialize a variable to keep track of the maximum value found.
            int maximum = 0;
            
            // Generate all combinations of indices of '0' taken 2 at a time.
            for (int i = 0; i < count; i++) {
                for (int j = i + 1; j < count; j++) {
                    // Calculate the maximum value based on the distance between the two indices.
                    int distance = abs(indices[i] - indices[j]);
                    maximum = max(maximum, 2 + 2 * (distance - 1) - (distance - 1));
                }
            }
            
            // Output the count of '1's in the string plus the maximum value calculated.
            printf("%d\n", find(s, '1') + maximum);
        }
    }
    
    return 0;
}
