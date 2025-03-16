

import sys

def regexBU(src, pat):
    strg = [[False for _ in range(len(pat) + 1)] for _ in range(len(src) + 1)] # Initializes a 2D boolean array for storing the results of subproblems

    # Base case: If the source string and the pattern are both empty, they match
    strg[len(src)][len(pat)] = True

    # Loops through each character in the source string (from right to left)
    for row in range(len(src), -1, -1):
        for col in range(len(pat) - 1, -1, -1):
            # If we've reached the end of the source string, handle the wildcard character (*) differently
            if row == len(src):
                if pat[col] == '*':
                    strg[row][col] = strg[row][col + 1] # If the pattern's current character is a wildcard, the current subproblem is true if the next one is
                else:
                    strg[row][col] = False # If the pattern's current character is not a wildcard, the current subproblem is false
            else:
                # Compares the characters at the current positions in the source and pattern strings
                chs = src[row]
                chp = pat[col]

                # Determines the answer based on the comparison result and the wildcard character (*)
                ans = False
                if chs == chp or chp == '?':
                    ans = strg[row + 1][col + 1] # If the characters match or the pattern's current character is a question mark, the current subproblem is true if the next one is
                elif chp == '*':
                    blank = strg[row][col + 1] # If the pattern's current character is a wildcard, the current subproblem is true if the next one in the pattern is or if the current character in the source string matches the next character in the pattern
                    multiple = strg[row + 1][col] # If the pattern's current character is a wildcard, the current subproblem is true if the previous one in the source string and the current one match the pattern's current character and the next one
                    ans = blank or multiple
                strg[row][col] = ans # Stores the result of the current subproblem in the 2D array

    # Returns the result of the first subproblem (source string is empty and pattern string is empty)
    return strg[0][0]

# Reads the source string and the pattern string from the user
src = input("Enter the source string: ")
pat = input("Enter the pattern string: ")

# Checks if the source string matches the pattern using the regexBU algorithm
isMatch = regexBU(src, pat)

# Prints the result to the console
print("Does the source string match the pattern? " + str(isMatch))

