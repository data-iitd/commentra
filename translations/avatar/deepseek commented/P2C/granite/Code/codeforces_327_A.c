
#include <stdio.h>
#include <string.h>

// Function to find indices of a character in a string
int find(char *s, char ch) {
    int i;
    for (i = 0; s[i]!= '\0'; i++) {
        if (s[i] == ch) {
            return i;
        }
    }
    return -1;
}

// Main block of the code
int main() {
    // Read the integer input
    int n;
    scanf("%d", &n);
    
    // Read the string input and remove spaces
    char s[n];
    fgets(s, n, stdin);
    s[strcspn(s, " \n")] = '\0';
    
    // If the string does not contain '0', print n - 1
    if (strchr(s, '0') == NULL) {
        printf("%d\n", n - 1);
    } else {
        // Find all indices of '0' in the string
        int indices[n];
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                indices[count++] = i;
            }
        }
        
        // If there is only one '0', print n
        if (count == 1) {
            printf("%d\n", n);
        } else {
            // Initialize maximum to 0
            int maximum = 0;
            // Generate all combinations of two indices of '0'
            for (int i = 0; i < count; i++) {
                for (int j = i + 1; j < count; j++) {
                    int distance = 2 + 2 * (abs(indices[i] - indices[j]) - 1) - (abs(i - j) - 1);
                    if (distance > maximum) {
                        maximum = distance;
                    }
                }
            }
            
            // Print the count of '1's plus the maximum distance
            printf("%d\n", s[strcspn(s, "0")] - '0' + maximum);
        }
    }
    
    return 0;
}
