#include <stdio.h>
#include <string.h>

int main() {
    // Declare variables to hold the integer input and the string input
    int n;
    char s[1000];
    
    // Read an integer from standard input
    scanf("%d", &n);
    
    // Read a string from standard input
    scanf("%s", s);
    
    // Count the occurrences of the substring "ABC" in the input string
    // and print the result
    int count = 0;
    char *ptr = s;
    while ((ptr = strstr(ptr, "ABC")) != NULL) {
        count++;
        ptr++; // Move to the next character to continue searching
    }
    printf("%d\n", count);
    
    return 0;
}
