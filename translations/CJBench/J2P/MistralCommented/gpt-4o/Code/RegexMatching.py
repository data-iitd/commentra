class Main:
    @staticmethod
    def regexBU(src, pat):
        strg = [[False] * (len(pat) + 1) for _ in range(len(src) + 1)]  # Initializes a 2D boolean array for storing the results of subproblems

        # Base case: If the source string and the pattern are both empty, they match
        strg[len(src)][len(pat)] = True

        # Loops through each character in the source string (from right to left)
        for row in range(len(src), -1, -1):
            for col in range(len(pat) - 1, -1, -1):
                # If we've reached the end of the source string, handle the wildcard character (*) differently
                if row == len(src):
                    if pat[col] == '*':
                        strg[row][col] = strg[row][col + 1]  # If the pattern's current character is a wildcard
                    else:
                        strg[row][col] = False  # If the pattern's current character is not a wildcard
                else:
                    # Compares the characters at the current positions in the source and pattern strings
                    chs = src[row]
                    chp = pat[col]

                    # Determines the answer based on the comparison result and the wildcard character (*)
                    if chs == chp or chp == '?':
                        ans = strg[row + 1][col + 1]  # Characters match or pattern's current character is a question mark
                    elif chp == '*':
                        blank = strg[row][col + 1]  # Wildcard handling
                        multiple = strg[row + 1][col]  # Wildcard handling
                        ans = blank or multiple
                    else:
                        ans = False  # Characters don't match and there's no wildcard character
                    strg[row][col] = ans  # Stores the result of the current subproblem in the 2D array

        # Returns the result of the first subproblem (source string is empty and pattern string is empty)
        return strg[0][0]

# Initializes the scanner and starts the program
if __name__ == "__main__":
    src = input()  # Reads the source string from the user
    pat = input()  # Reads the pattern string from the user
    isMatch = Main.regexBU(src, pat)  # Calls the regexBU method to check if the source string matches the pattern
    print("Does the source string match the pattern? " + str(isMatch))  # Prints the result to the console

# <END-OF-CODE>
