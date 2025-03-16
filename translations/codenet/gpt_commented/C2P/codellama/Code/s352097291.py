#include <stdio.h>
#include <string.h>

int main() {
    # Declare a character array 'c' to store the input string and 'ans' to store the result
    c = []
    ans = []
    
    # Read a string input from the user
    c = input()
    
    # Iterate through each character of the input string until the null terminator is encountered
    for i in range(len(c)):
        # If the current character is not 'B', append it to the 'ans' string
        if c[i] != 'B':
            ans.append(c[i])
        # If the current character is 'B', remove the last character from 'ans' (if it exists)
        else:
            ans.pop()
    
    # Print the resulting string after processing the input
    print("".join(ans))
}

