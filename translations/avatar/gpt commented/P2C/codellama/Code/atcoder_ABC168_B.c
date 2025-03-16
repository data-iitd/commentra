#include <stdio.h>
#include <string.h>

// Function to truncate a string
char *truncate(char *str, int k) {
    // Check if the length of the string is less than or equal to k
    if (strlen(str) <= k) {
        // If true, return the original string
        return str;
    }
    
    // If the length of the string is greater than k, return the first k characters followed by '...'
    char *result = (char *)malloc(k + 4);
    strncpy(result, str, k);
    strcpy(result + k, "...");
    return result;
}

// Main function
int main() {
    // Read an integer input K from the user
    int k;
    scanf("%d", &k);
    
    // Read a string input S from the user
    char s[100];
    scanf("%s", s);
    
    // Call the truncate function and print its result
    printf("%s\n", truncate(s, k));
    
    // Return 0 to indicate success
    return 0;
}

// End of code
