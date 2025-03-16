#include <stdio.h>
#include <string.h>

def main():
    # Declare a character array 'c' to store the input string and 'ans' to store the result
    c = [None] * 11
    ans = ['\0'] * 11
    
    # Read a string input from the user
    scanf("%s", c)
    
    # Iterate through each character of the input string until the null terminator is encountered
    for i in range(0, len(c)):
        # If the current character is not 'B', append it to the 'ans' string
        if c[i]!= 'B':
            ans[len(ans) - 1] = c[i]
        # If the current character is 'B', remove the last character from 'ans' (if it exists)
        else:
            ans[len(ans) - 1] = '\0'
    
    # Print the resulting string after processing the input
    printf("%s\n", ans)

# 