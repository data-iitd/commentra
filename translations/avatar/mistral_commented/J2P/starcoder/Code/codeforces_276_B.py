
import sys

# Read input from stdin
str = sys.stdin.readline()

# Initialize the map to store character counts
map = {}

# Iterate through each character in the input string
for ch in str:
    # If the character is already in the map, increment its count
    if ch in map:
        map[ch] += 1
    else:
        # Otherwise, add the character to the map with a count of 1
        map[ch] = 1

# Initialize the odd count
oddCount = 0

# Iterate through each entry in the map and count odd-valued entries
for key, value in map.items():
    if value % 2!= 0:
        oddCount += 1 # Increment the odd count

# Determine the output based on the odd count
if oddCount <= 1 or oddCount % 2!= 0:
    print("First") # Output "First" if the odd count is 1 or odd
else:
    print("Second") # Output "Second" if the odd count is even

# 