#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int find(char *s, char ch) {
    // This function returns a list of indices where the character 'ch' appears in the string 's'.
    int indices[1000]; // Assuming the maximum length of the string is 1000
    int count = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == ch) {
            indices[count++] = i;
        }
    }
    return count;
}

int main() {
    // Read an integer input 'n' which represents the length of the string.
    int n;
    scanf("%d", &n);
    
    // Read the string input 's' and replace any empty string occurrences (this line seems to be incorrect).
    char s[1001]; // Assuming the maximum length of the string is 1000
    scanf("%s", s);
    
    // Check if the string 's' contains the character '0'.
    if (strchr(s, '0') == NULL) {
        // If '0' is not present, the output is n - 1.
        printf("%d\n", n - 1);
    } else {
        // Find all indices of '0' in the string 's'.
        int indices[1000];
        int count = find(s, '0', indices);
        
        // If there is only one '0', output the length of the string 'n'.
        if (count == 1) {
            printf("%d\n", n);
        } else {
            // Initialize a variable to keep track of the maximum value found.
            int maximum = 0;
            
            // Generate all combinations of indices of '0' taken 2 at a time.
            for (int i = 0; i < count - 1; i++) {
                for (int j = i + 1; j < count; j++) {
                    // Calculate the maximum value based on the distance between the two indices.
                    int distance = 2 + 2 * (abs(i - j) - 1) - (abs(indices[i] - indices[j]) - 1);
                    if (distance > maximum) {
                        maximum = distance;
                    }
                }
            }
            
            // Output the count of '1's in the string plus the maximum value calculated.
            printf("%d\n", (int)strlen(s) - count + maximum);
        }
    }
    
    return 0;
}
