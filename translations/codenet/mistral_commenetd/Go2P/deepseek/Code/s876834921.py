import re

# Read a string input from the user using input() function
s = input()

# Replace all occurrences of the substrings "dream" and "erase" with "D" and "E" respectively using re.sub() function
s = re.sub(r'dream', 'D', s)
s = re.sub(r'erase', 'E', s)

# Remove the substrings "Der" and "Er" from the string 's' using re.sub() function
s = re.sub(r'Der', '', s)
s = re.sub(r'Er', '', s)

# Remove leading and trailing spaces from the string 's' using strip() method
s = s.strip()

# Check if the string 's' is empty or not
if s == "":
    # Print "YES" if the string 's' is empty
    print("YES")
else:
    # Print "NO" if the string 's' is not empty
    print("NO")

# End-of-code
