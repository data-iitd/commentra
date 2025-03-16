
import sys

# Read input from the standard input stream using sys.stdin.readline()
n, m = map(int, sys.stdin.readline().split())

# Create an array ans of size n to store the processed strings
ans = [None] * n

# Iterate through each string in the input
for i in range(n):
    # Read a string from the input
    str = sys.stdin.readline().strip()
    temp = ""

    # Iterate through each character in the string
    for j in range(m):
        if str[j] == '-':
            temp += "-"
        else:
            if (i + j) % 2 == 1:
                temp += "W"
            else:
                temp += "B"

    # Store the final string in the ans array using the index i
    ans[i] = temp

# Iterate through each string in the ans array and print it to the standard output stream
for i in range(n):
    print(ans[i])

# END-OF-CODE
