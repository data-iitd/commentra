
import sys

# Read input from standard input
n = int(input())

# Initialize arrays'maps' and 'num' with given size'maxn'
maps = [0] * (n + 1)
num = [0] * (n + 1)

# Read input values and copy them to 'num' array
for i in range(1, n + 1):
    maps[i] = int(input())
    num[i] = maps[i]

# Sort'maps' array in ascending order
maps.sort()

# Calculate the middle index'm' of sorted'maps' array
m = n // 2

# Process each element in 'num' array based on the middle index'm'
for i in range(1, n + 1):
    # If current element 'num[i]' is smaller than or equal to middle element'maps[m]'
    if num[i] <= maps[m]:
        # Print the next element in sorted'maps' array
        print(maps[m + 1])
    # Otherwise print the current middle element'maps[m]'
    else:
        print(maps[m])

# End of code
print("