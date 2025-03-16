import sys
import math
from io import StringIO

# I/O setup
input = sys.stdin.read
sys.stdin.seek(0)

# Read input
str = input().strip()

# Initialize memoization array
memo = [0] * 26

# Process each character
for c in str:
    if 'a' <= c <= 'z':
        memo[ord(c) - ord('a')] += 1
    elif 'A' <= c <= 'Z':
        memo[ord(c) - ord('A')] += 1

# Print counts
for i in range(26):
    print(f"{chr(i + ord('a'))} : {memo[i]}")

