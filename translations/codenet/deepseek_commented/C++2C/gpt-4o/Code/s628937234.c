#include <stdio.h>
#include <string.h>

int main()
{
    // Declare two character arrays, s and t
    char s[100], t[100];
    
    // Read a string from the standard input and store it in s
    scanf("%s", s);
    
    // Get the length of the string s
    int len = strlen(s);
    
    // Assign the first character of s to t
    t[0] = s[0];
    
    // Append the size of s minus 2 to t
    sprintf(t + 1, "%d", len - 2);
    
    // Append the last character of s to t
    t[strlen(t)] = s[len - 1];
    
    // Null-terminate the string t
    t[strlen(t) + 1] = '\0';
    
    // Print the modified string t
    printf("%s\n", t);
    
    return 0;
}

// <END-OF-CODE>
