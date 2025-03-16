
import sys

# Define constants
maxn = 200000 + 10  # Maximum number of elements
INF = int(1e8)  # A large value representing infinity

# Read the number of elements
n = int(input())

# Read the elements into maps array and copy them to num array
maps = [0] * (n + 1)
num = [0] * (n + 1)
for i in range(1, n + 1):
    maps[i] = int(input())
    num[i] = maps[i]

# Sort the maps array to find the median easily
maps.sort()

# Calculate the median index
m = n // 2

# Iterate through the num array and print the appropriate median value
for i in range(1, n + 1):
    if num[i] <= maps[m]:
        print(maps[m + 1])  # Print the element after the median if num[i] is less than or equal to the median
    else:
        print(maps[m])  # Print the median if num[i] is greater than the median

