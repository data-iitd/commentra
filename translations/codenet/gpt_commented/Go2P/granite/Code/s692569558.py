
import sys

# Read the first line of input (not used)
input()
# Read the second line of input which contains space-separated integers
ds = input()

# Split the input string into a list of strings
dd = ds.split(" ")
# Create a list of integers to hold the converted values
dn = [int(d) for d in dd]

# Initialize a variable to hold the sum of products
sum = 0
# Calculate the sum of products of all unique pairs of integers
for i in range(len(dn)):
    for j in range(i + 1, len(dn)):
        sum += dn[i] * dn[j] # Multiply the pair and add to sum

# Output the final sum of products
print(sum)

