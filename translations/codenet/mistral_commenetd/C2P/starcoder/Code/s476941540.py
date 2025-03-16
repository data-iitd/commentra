#include <stdio.h>
#include <ctype.h>

#define SIZE 26

// The main function is the starting point of the program
def main():
    alpha = [0] * SIZE;
    ch = 'a';

    # Start an infinite loop
    while(1):
        ch = getchar();

        # If the character read is End-Of-File (EOF), break the loop
        if(ch == EOF):
            break;

        # If the character is an alphabetic character
        if(isalpha(ch)):
            # If the character is an uppercase letter, increment the corresponding element in the array 'alpha'
            if(isupper(ch)):
                alpha[ord(ch) - ord('A')] += 1;

            # If the character is a lowercase letter, increment the corresponding element in the array 'alpha'
            else:
                alpha[ord(ch) - ord('a')] += 1;

    # Print the count of each alphabetic character and its corresponding ASCII value
    for i in range(SIZE):
        print(chr(ord('a') + i), ":", alpha[i]);

# 