
import sys
def regexBU(src, pat):
    # Create a 2D boolean array to store the results of subproblems
    strg = [[False for _ in range(len(pat) + 1)] for _ in range(len(src) + 1)]
    # Base case: an empty pattern matches an empty source string
    strg[-1][-1] = True
    # Fill the table in reverse order
    for row in range(len(src), -1, -1):
        for col in range(len(pat) - 1, -1, -1):
            # If we are at the last row, handle the '*' character
            if row == len(src):
                if pat[col] == '*':
                    strg[row][col] = strg[row][col + 1]
                else:
                    strg[row][col] = False
            else:
                # Get the current characters from the source and pattern
                chs = src[row]
                chp = pat[col]
                ans = False
                # Check if the characters match or if the pattern character is '?'
                if chs == chp or chp == '?':
                    ans = strg[row + 1][col + 1]
                elif chp == '*':
                    # Handle the '*' character: it can match zero, one, or multiple characters
                    blank = strg[row][col + 1]
                    multiple = strg[row + 1][col]
                    ans = blank or multiple
                strg[row][col] = ans
    # The result for the entire source and pattern is stored in the top-left cell
    return strg[0][0]

# Read the source string and pattern from the user
src = input("Enter the source string: ")
pat = input("Enter the pattern: ")
# Call the regexBU function to check if the source string matches the pattern
isMatch = regexBU(src, pat)
# Print the result
print("Does the source string match the pattern? " + str(isMatch))

