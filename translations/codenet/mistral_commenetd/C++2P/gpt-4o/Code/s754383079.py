# Import necessary libraries
import sys

# Define constants
M = 1010  # maximum size of strings a and b

# Read string a from standard input
a = input().strip()
n = len(a)  # get the length of string a

# Read string b from standard input
b = input().strip()
m = len(b)  # get the length of string b

# Initialize the minimum number of differences
ans = M + 10

# Iterate through all possible substrings of string a that have the same length as string b
for i in range(n - m + 1):
    # Initialize sum to 0, it will be used to count the number of differences
    sum_diff = 0

    # Iterate through each character in the substring of string a and compare it with the corresponding character in string b
    for j in range(m):
        # If the characters are different, increment sum_diff by 1
        if a[i + j] != b[j]:
            sum_diff += 1

    # Update the minimum number of differences if a smaller number is found
    ans = min(ans, sum_diff)

# Print the minimum number of differences to standard output
print(ans)

# Terminate the program with exit code 0
# <END-OF-CODE>
