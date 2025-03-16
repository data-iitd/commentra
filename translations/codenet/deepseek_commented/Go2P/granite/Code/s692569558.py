

import sys

# Read the first line of input (which we will ignore)
sys.stdin.readline()

# Read the second line of input
ds = sys.stdin.readline().strip()

# Split the input string into a list of strings
dd = ds.split(" ")

# Convert each string in the list to an integer
dn = [int(d) for d in dd]

# Initialize the sum variable to hold the result
sum = 0

# Calculate the sum of the products of all pairs of integers in the list
for i in range(len(dn)):
    for j in range(i + 1, len(dn)):
        sum += dn[i] * dn[j]

# Print the result
print(sum)

