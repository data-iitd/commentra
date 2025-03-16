#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find indices of a character in a string
int* find(char* s, char ch) {
    int* indices = (int*)malloc(sizeof(int) * strlen(s));
    int i = 0;
    for (int j = 0; j < strlen(s); j++) {
        if (s[j] == ch) {
            indices[i] = j;
            i++;
        }
    }
    return indices;
}

// Main block of the code
int main() {
    // Read the integer input
    int n;
    scanf("%d", &n);
    // Read the string input and remove spaces
    char* s = (char*)malloc(sizeof(char) * 100000);
    scanf("%s", s);
    s = strtok(s, " ");
    
    // If the string does not contain '0', print n - 1
    if (strchr(s, '0') == NULL) {
        printf("%d\n", n - 1);
    } else {
        // Find all indices of '0' in the string
        int* indices = find(s, '0');
        
        // If there is only one '0', print n
        if (strchr(s, '0') == strrchr(s, '0')) {
            printf("%d\n", n);
        } else {
            // Initialize maximum to 0
            int maximum = 0;
            // Generate all combinations of two indices of '0'
            int* combs = (int*)malloc(sizeof(int) * (strlen(s) * (strlen(s) - 1) / 2));
            int i = 0;
            for (int j = 0; j < strlen(s) - 1; j++) {
                for (int k = j + 1; k < strlen(s); k++) {
                    if (indices[j] < indices[k]) {
                        combs[i] = j;
                        i++;
                        combs[i] = k;
                        i++;
                    }
                }
            }
            
            // Iterate over each combination and calculate the maximum distance
            for (int j = 0; j < i; j += 2) {
                maximum = max(maximum, 2 + 2 * (abs(indices[combs[j]] - indices[combs[j + 1]]) - 1) - (abs(combs[j] - combs[j + 1]) - 1));
            }
            
            // Print the count of '1's plus the maximum distance
            printf("%d\n", strlen(s) - strlen(strtok(s, "1")) + maximum);
        }
    }
    return 0;
}

