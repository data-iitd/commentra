
import sys

# Create a Scanner object to read input from the user
in = sys.stdin

# Read an integer K from the user
K = int(in.readline())

# Read a string S from the user
S = in.readline()

# Check if the length of the string S is less than or equal to K
if len(S) <= K:
    # If true, print the string S as it is
    print(S)
else:
    # If false, truncate the string to the first K characters and append "..."
    print(S[:K] + "...")

# 