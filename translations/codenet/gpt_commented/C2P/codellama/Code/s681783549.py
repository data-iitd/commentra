#include <stdio.h>
#include <stdlib.h>

int main() {
    # Declare an integer variable for iteration and a character array to store input
    i = 0
    S = []

    # Read a string input from the user
    scanf("%s", S)

    # Iterate through each character in the string until the null terminator is reached
    for i in range(len(S)):
        # Check if the current character is 'A' and the next character is 'C'
        if S[i] == 'A' and S[i + 1] == 'C':
            # If the condition is met, print "Yes" and exit the program
            print("Yes")
            return 0

    # If the loop completes without finding "AC", print "No"
    print("No")
    return 0
}

