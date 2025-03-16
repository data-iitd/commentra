
```python
import sys

# Read the number of strings (n) and the number of queries (m)
n, m = map(int, input().split())

# Initialize an array to store the strings
arrs = [input() for _ in range(n)]

# Initialize an array to store the lengths of segments between 'G' and 'S'
length = []
index = 0
returnDex = 0

# Iterate through each string to find the indices of 'G' and 'S'
for tmp in arrs:
    dexG = tmp.find("G") # Find the index of 'G'
    dexS = tmp.find("S") # Find the index of 'S'
    
    # If 'G' appears after 'S', set returnDex to -1
    if dexG > dexS:
        returnDex = -1
    
    # Calculate the length between 'G' and 'S' and store it in the length array
    length.append(dexS - dexG)

# Use a set to store unique lengths
unique_lengths = set(length)

# Check if returnDex was set to -1 and print the appropriate result
if returnDex == -1:
    print(returnDex) # Print -1 if 'G' is after 'S' in any string
else:
    print(len(unique_lengths)) # Print the number of unique lengths
```

