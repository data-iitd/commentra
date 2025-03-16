# Define long long type for large integers
from typing import List

# Declare variables
n, k, ans, L, ans2 = 0, 0, 0, '', 0
s: List[str] = []

# Read the number of characters (n) and the maximum number of operations (k)
n, k = map(int, input().split())

# Read the string of characters
s = list(input())

# Initialize L with the first character of the string
L = s[0]
cnt = 0 # Initialize a counter for consecutive characters

# Iterate through the string starting from the second character
for i in range(1, n):
    # If the current character is the same as the last character
    if L == s[i]:
        cnt += 1 # Increment the counter
    else:
        # If the character changes, update L and add the count to ans
        L = s[i]
        ans += cnt # Add the count of consecutive characters to ans
        ans2 += 1 # Increment the number of distinct character groups
        cnt = 0 # Reset the counter for the new character

# After the loop, add the count of the last group of characters to ans
ans += cnt
ans2 += 1 # Increment for the last group

# Output the final result: total operations plus the minimum of 2*k or (number of groups - 1)
print(ans + min(2 * k, ans2 - 1))

# End-of-code
