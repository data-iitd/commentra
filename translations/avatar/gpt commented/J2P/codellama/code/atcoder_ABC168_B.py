import sys

# Read an integer K from the user, which represents the maximum length of the string to display
K = int(sys.stdin.readline().strip())

# Read a string S from the user
S = sys.stdin.readline().strip()

# Check if the length of the string S is less than or equal to K
if len(S) <= K:
    # If true, print the string S as it is
    print(S)
else:
    # If false, print the first K characters of S followed by "..."
    print(S[:K] + "...")

# Close the scanner to prevent resource leaks
sys.stdin.close()

