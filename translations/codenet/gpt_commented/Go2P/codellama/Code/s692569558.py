
# Importing the required modules
import sys

# Reading the first line of input (not used)
sys.stdin.readline()

# Reading the second line of input which contains space-separated integers
ds = sys.stdin.readline()

# Splitting the input string into a list of strings
dd = ds.split()

# Creating a list of integers to hold the converted values
dn = []

# Converting each string in the list to an integer
for d in dd:
    dn.append(int(d))

# Initializing a variable to hold the sum of products
sum = 0

# Calculating the sum of products of all unique pairs of integers
for i in range(len(dn)):
    for j in range(i + 1, len(dn)):
        sum += dn[i] * dn[j] # Multiplying the pair and adding to sum

# Outputting the final sum of products
print(sum)

