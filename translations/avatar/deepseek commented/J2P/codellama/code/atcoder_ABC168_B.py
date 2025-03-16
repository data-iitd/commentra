
import sys

# Read an integer K from the user
K = int(sys.stdin.readline().strip())

# Read a string S from the user
S = sys.stdin.readline().strip()

# Check if the length of the string S is less than or equal to K
if len(S) <= K:
    # If true, print the string S as it is
    print(S)
else:
    # If false, truncate the string to the first K characters and append "..."
    print(S[:K] + "...")

# 