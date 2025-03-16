

import sys

# Read the input string from the user
str = input()

# Create a dictionary to count the frequency of each character in the input string
char_count = {}

# Initialize a counter for characters with odd frequencies
odd_count = 0

# Iterate through the input string to populate the frequency dictionary
for ch in str:
    if ch in char_count:
        char_count[ch] += 1
    else:
        char_count[ch] = 1

# Iterate through the dictionary to count characters with odd frequencies
for ch, count in char_count.items():
    if count % 2!= 0:
        odd_count += 1

# Determine the winner based on the count of characters with odd frequencies
if odd_count <= 1 or odd_count % 2!= 0:
    print("First")
else:
    print("Second")

# Flush the output to ensure the result is printed immediately
sys.stdout.flush()

