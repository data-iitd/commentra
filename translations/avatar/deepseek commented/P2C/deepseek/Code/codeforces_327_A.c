#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to find indices of a character in a string
int* find(const char* s, char ch, int* len) {
    *len = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ch) {
            (*len)++;
        }
    }
    int* indices = (int*)malloc(*len * sizeof(int));
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ch) {
            indices[j++] = i;
        }
    }
    return indices;
}

int main() {
    int n;
    char s[100001];
    
    // Read the integer input
    scanf("%d", &n);
    // Read the string input and remove spaces
    scanf("%*c%[^\n]", s);
    
    // If the string does not contain '0', print n - 1
    if (strchr(s, '0') == NULL) {
        printf("%d\n", n - 1);
    } else {
        // Find all indices of '0' in the string
        int len;
        int* indices = find(s, '0', &len);
        
        // If there is only one '0', print n
        if (len == 1) {
            printf("%d\n", n);
        } else {
            // Initialize maximum to 0
            int maximum = 0;
            
            // Generate all combinations of two indices of '0'
            for (int i = 0; i < len; i++) {
                for (int j = i + 1; j < len; j++) {
                    int distance = 2 + 2 * (abs(i - j) - 1) - (abs(indices[i] - indices[j]) - 1);
                    if (distance > maximum) {
                        maximum = distance;
                    }
                }
            }
            
            // Print the count of '1's plus the maximum distance
            printf("%d\n", (int)strlen(s) - len + maximum);
            
            // Free the allocated memory
            free(indices);
        }
    }
    
    return 0;
}
