from collections import Counter
import sys

# Read the input string
s = input()

# Count the frequency of each character in the string
char_count = Counter(s)

# Check if each character appears exactly twice and there are exactly 2 unique characters
if len(char_count) == 2 and all(count == 2 for count in char_count.values()):
    print("Yes")
else:
    print("No")

