
#include <stdio.h>
#include <string.h>

int main() {
    // Declare variables to hold the integer input and the string input
    int n;
    char s[100];
    
    // Read an integer from standard input
    scanf("%d", &n);
    
    // Read a string from standard input
    scanf("%s", s);
    
    // Count the occurrences of the substring "ABC" in the input string
    // and print the result
    printf("%d\n", strlen(s) - strlen(strstr(s, "ABC")));
    
    return 0;
}
