from collections import Counter
import sys

# Initialize the counter for each letter
alpha = Counter()

# Read input from stdin
for line in sys.stdin:
    for ch in line:
        if ch.isalpha():
            if ch.isupper():
                alpha[ch.lower()] += 1
            else:
                alpha[ch] += 1

# Print the counts
for ch in range(ord('a'), ord('z') + 1):
    print(f"{chr(ch)} : {alpha[chr(ch)]}")
