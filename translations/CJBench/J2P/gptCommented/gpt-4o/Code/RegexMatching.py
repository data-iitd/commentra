class Main:
    @staticmethod
    def regexBU(src, pat):
        # Create a 2D boolean array to store the matching results
        strg = [[False] * (len(pat) + 1) for _ in range(len(src) + 1)]
        
        # Initialize the bottom-right cell to true (empty string matches empty pattern)
        strg[len(src)][len(pat)] = True

        # Iterate over the source string in reverse order
        for row in range(len(src), -1, -1):
            # Iterate over the pattern string in reverse order
            for col in range(len(pat) - 1, -1, -1):
                # Handle the case when the source string is empty
                if row == len(src):
                    # If the current pattern character is '*', check if the next pattern character can match
                    if pat[col] == '*':
                        strg[row][col] = strg[row][col + 1]
                    else:
                        # If not, set the current cell to false
                        strg[row][col] = False
                else:
                    # Get the current characters from the source and pattern
                    chs = src[row]
                    chp = pat[col]
                    
                    # Check for character match or '?' wildcard
                    if chs == chp or chp == '?':
                        ans = strg[row + 1][col + 1]
                    # Handle '*' wildcard which can match zero or more characters
                    elif chp == '*':
                        blank = strg[row][col + 1]  # Match '*' with zero characters
                        multiple = strg[row + 1][col]  # Match '*' with one or more characters
                        ans = blank or multiple
                    else:
                        # If characters do not match, set answer to false
                        ans = False
                    
                    # Store the result in the current cell
                    strg[row][col] = ans
        
        # Return the result of the match for the entire source and pattern
        return strg[0][0]

if __name__ == "__main__":
    # Create a Scanner object to read input from the console
    src = input("Enter the source string: ")
    
    # Read the pattern string from the user
    pat = input("Enter the pattern string: ")
    
    # Call the regexBU method to check if the source matches the pattern
    isMatch = Main.regexBU(src, pat)
    
    # Output the result of the match
    print("Does the source string match the pattern? " + str(isMatch))

# <END-OF-CODE>
