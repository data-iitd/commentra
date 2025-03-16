
# Importing all utilities from the standard library
import sys
import math

# Reading the input
n = int(input())

# Initializing an empty string to store binary representation
s = ""

# Converting the integer to binary representation
while n > 0:
    x = n % 2
    n = n // 2
    s += str(x)

# Initializing a variable to count the number of '1's
ans = 0

# Counting the number of '1's in the binary representation
for i in range(len(s)):
    if s[i] == '1':
        ans += 1

# Printing the count of '1's
print(ans)

# 