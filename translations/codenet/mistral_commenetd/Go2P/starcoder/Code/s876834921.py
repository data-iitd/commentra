
# Initialize an empty string variable's'
s = ""

# Read a string input from the user using 'input' function
s = input()

# Replace all occurrences of the substrings "dream" and "erase" with "D" and "E" respectively using'replace' function
s = s.replace("dream", "D")
s = s.replace("erase", "E")

# Remove the substrings "Der" and "Er" from the string's' using'replace' function
s = s.replace("Der", "")
s = s.replace("Er", "")

# Remove leading and trailing spaces from the string's' using'strip' function
s = s.strip()

# Check if the string's' is empty or not
if s == "":
    # Print "YES" if the string's' is empty
    print("YES")
else:
    # Print "NO" if the string's' is not empty
    print("NO")

# End of the code

