#include <stdio.h>  # Include stdio.h for input and output functions
#include <string.h> # Include string.h for string manipulation functions

def main():
    c = input() # Read input string into c
    ans = "" # Declare string ans

    # Process the input string
    for i in range(len(c)):
        if c[i] != "B":
            ans += c[i] # Append character to ans if not 'B'
        else:
            ans = ans[:-1] # Remove last character from ans if 'B'

    print(ans) # Output the result string ans

