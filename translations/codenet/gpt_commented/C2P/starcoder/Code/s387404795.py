#include <stdio.h>
#include <string.h>

def main():
    # Declare character arrays for input strings and temporary storage
    str = [None] * 201
    tmp = [None] * 101
    p = [None] * 101
    
    # Declare integer variables for string lengths and loop control
    slen = 0
    plen = 0
    i = 0
    j = 0
    flag = 0
    
    # Read two strings from standard input
    scanf("%s %s", str, p)
    
    # Copy the original string into a temporary variable and concatenate it with itself
    strcpy(tmp, str)
    strcat(str, tmp)
    
    # Calculate the lengths of the concatenated string and the pattern string
    slen = strlen(str)
    plen = strlen(p)
    
    # Initialize a flag to indicate if the pattern is found
    flag = 0
    
    # Loop through the concatenated string to search for the pattern
    for i in range(0, slen - plen):
        # Compare the substring of str with the pattern p
        if (strncmp(&str[i], p, plen) == 0):
            flag = 1 # Set flag if a match is found
    
    # Output "Yes" if the pattern was found, otherwise output "No"
    if (flag):
        puts("Yes")
    else:
        puts("No")
    
    return 0 # Return success

