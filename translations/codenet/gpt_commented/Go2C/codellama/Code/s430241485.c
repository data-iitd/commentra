#include <stdio.h>

int main() {
    // Declare two string variables to hold input values
    char s[100], t[100];
    
    // Read two strings from standard input
    scanf("%s %s", s, t);
    
    // Print the concatenation of the second string followed by the first string
    printf("%s%s\n", t, s);
    
    // End of code
    return 0;
}
