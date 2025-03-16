#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char s[1000];
    
    // Read an integer `n` and a string `s` from the standard input.
    scanf("%d %s", &n, s);
    
    // Initialize a counter to keep track of the occurrences of the substring "ABC".
    int count = 0;
    
    // Iterate through the string `s` to find occurrences of the substring "ABC".
    for (int i = 0; i <= strlen(s) - 3; i++) {
        if (s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') {
            count++;
            i += 2; // Skip the next two characters since they are part of the found substring.
        }
    }
    
    // Print the number of occurrences of the substring "ABC" in the string `s`.
    printf("%d\n", count);
    
    return 0;
}
